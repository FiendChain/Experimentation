import re
import os
import sys
import argparse
import pprint as pp
from thetvdb import thetvdb_api, filtering
from se_pattern import get_group
from enum import Enum

class RenameError(Enum):
    Same = 1
    Unknown = 2

    def __str__(self):
        return self.name

root_path_source = os.path.dirname(os.path.abspath(__file__))
credentials_file = os.path.join(root_path_source, 'credentials.json')

PROPER_FILE_NAME = "{title}S{season:02d}E{episode:02d}{name}.{extension}"
EPISODE_TITLE_RENAME = r"[\s+\:\.+]"
EPISODE_NAME_RENAME  = r"[^a-zA-Z0-9]"

def main():
    if len(sys.argv) >= 2:
        default_title = re.sub(EPISODE_TITLE_RENAME, ".", sys.argv[1]) 
    parser = argparse.ArgumentParser()
    parser.add_argument('title', default=None)
    parser.add_argument('--id', dest='id', type=str, default=None)
    parser.add_argument('--thetvdb', dest='enable_thetvdb', action='store_true')
    parser.add_argument('--fetch_title', dest='fetch_title', action='store_true')

    args = parser.parse_args()
    title = clean_title(args.title)

    if args.enable_thetvdb:
        api = thetvdb_api.Api.load_api(credentials_file)
        if args.id is None:
            series = get_series_from_string(api, title)
        else:
            series = api.get_series_by_id(args.id)

        if series:
            name_table = get_series_filtered_episodes(api, series.get('id', None))
            if args.fetch_title:
                title = clean_title(series.get('seriesName')) 
        else:
            name_table = None

    if args.enable_thetvdb and not name_table:
        print("Couldn't fetch name table")
        return

    file_translations = recursive_search(default_title=title, name_table=name_table)
    pp.pprint(file_translations)
    response = input('Do you want to continue? ')
    if response not in ('Y', 'y', 'yes'):
        return
    print('Renaming files')
    recursive_rename(file_translations)

def clean_title(title):
    new_title = re.sub(EPISODE_TITLE_RENAME, ".", title)
    new_title = re.sub(EPISODE_TITLE_RENAME, ".", new_title)
    return new_title

def get_series_filtered_episodes(api, series_id):
    episodes = api.get_series_episodes(series_id)
    filtered_episodes = filtering.filter_episode_list(episodes)
    return filtered_episodes

def get_series_from_string(api, series_name):
    series_name = series_name.replace('.', ' ')
    results = api.search_series(series_name)
    results = filtering.filter_series_results(results, ('seriesName', 'firstAired'))
    if not results:
        print('No results for {}'.format(series_name))
        return None
    series = filtering.select_series(results)
    return series

def recursive_rename(file_translations, path='.'):
    for file, new_file in file_translations.items():
        if isinstance(new_file, RenameError):
            continue
        elif type(new_file) is str:
            os.rename(os.path.join(path, file), os.path.join(path, new_file))
        elif type(new_file) is dict:
            recursive_rename(new_file, path=os.path.join(path, file))

def recursive_search(path='.', depth=1, default_title=None, name_table=None):
    file_translations = {}
    for file in os.listdir(path):
        if os.path.isfile(os.path.join(path, file)):
            file_translations[file] = get_file_name(file, default_title, name_table)
        elif os.path.isdir(file) and depth <= 2:
            file_translations[file] = recursive_search(os.path.join(path, file), depth+1, default_title, name_table)

    return file_translations

def get_file_name(file, default_title=None, name_table=None):
    group = get_group(file)
    if not group:
        return RenameError.Unknown
    if default_title:
        title = default_title
    else:
        title = group['title']
        title = re.sub(EPISODE_TITLE_RENAME, ".", title)
        title = re.sub(r"\.+", ".", title)
    season = group['season']
    episode = group['episode']
    extension = group['extension']

    if name_table and season in name_table and episode in name_table[season]:
        name = name_table[season][episode]
        name = re.sub(EPISODE_NAME_RENAME, ".", name)
        name = re.sub(r"\.+", ".", name)
    else:
        name = ''

    new_name = PROPER_FILE_NAME.format(
        title=title if not title else title+'.', 
        season=season, 
        episode=episode, 
        name=name if not name else '-'+name, 
        extension=extension)
    new_name = re.sub(r"\.+", ".", new_name)
    if new_name == file:
        return RenameError.Same
    return new_name

if __name__ == '__main__':
    main()
