def filter_series_results(results, required_params):
    filtered_results = []
    if not results:
        return filtered_results
    for series in results:
        has_sufficient_info = True
        for param in required_params:
            if not series.get(param, None):
                has_sufficient_info = False
                break
        if has_sufficient_info:
            filtered_results.append(series)
    return filtered_results

def select_series(series_list):
    for index, series in enumerate(series_list):
        print("{}: {} - {}".format(index+1, series.get('seriesName'), series.get('firstAired', None)))

    while True:
        try:
            selection = int(input("Select series: "))
        except KeyboardInterrupt:
            exit()
        except:
            print('Invalid selection')
            continue
        if selection <= 0 or selection > len(series_list):
            print('Index out of range')
            continue
        break

    return series_list[selection-1]

def filter_episode_list(episode_list):
    filtered_list = {}
    for episode in episode_list:
        try:
            season = int(episode.get('airedSeason'))
            episode_number = int(episode.get('airedEpisodeNumber'))
            episode_name = episode.get('episodeName')
        except:
            continue
        if season not in filtered_list:
            filtered_list[season] = {}
        filtered_list[season][episode_number] = episode_name

    return filtered_list
        
