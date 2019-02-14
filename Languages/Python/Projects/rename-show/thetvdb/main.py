from thetvdb_api import Api
from filtering import *
import os
import argparse
import json
import pprint as pp

credentials_file = "credentials.json"

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--id', default=None, type=str, help='ID of the series from thetvdb database')
    parser.add_argument('--output', default=None, type=str, help='Directory to output tv show info')
    args = parser.parse_args()

    api = Api.load_api(credentials_file)
    
    if args.id is None:
        series_name = input('Enter series name: ')
        results = api.search_series(series_name)
        results = filter_series_results(results, ('seriesName', 'firstAired'))
        if not results:
            print('No results for {}'.format(series_name))
            return
        series = select_series(results)
    else:
        series = api.get_series_by_id(args.id)
        if not series:
            print("No series with id '{}'".format(args.id))
            return

    series_id = series.get('id', None)
    episodes = api.get_series_episodes(series_id)
    filtered_episodes = filter_episode_list(episodes)
    if not args.output:
        pp.pprint(filtered_episodes)
    else:
        with open(args.output, 'w') as file:
            json.dump(filtered_episodes, file, indent=2, sort_keys=True)
            print('Json written to \'{}\''.format(args.output))




if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        pass

