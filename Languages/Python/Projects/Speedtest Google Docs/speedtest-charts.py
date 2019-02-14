#!/usr/bin/env python3
# run in virtual env as a standalone app
import os
import re
import subprocess
import sys

# custom imports
import time
import collections
import datetime 
import pygsheets
import speedtest


# Set constants
DATE_FORMAT = "%d-%m-%y %H:%M:%S"
UNIT = collections.namedtuple("UNIT", ["name", "scale", "unit", "formatter"])

def get_current_time():
    return datetime.datetime.now().strftime(DATE_FORMAT)

def main():
    s = Speedtest("credentials.json", "Speedtest")
    s.start_tests(100)
    #s.start_tests(100, 60*10)

# run speedtest and save to google spreadsheet
class Speedtest(speedtest.Speedtest):
    def __init__(self, credentials, sheet, page='sheet1'):
        speedtest.Speedtest.__init__(self)
        self.open_credentials(credentials)
        self.open_sheet(sheet, page)

    def open_credentials(self, credentials):
        try:
            self.credentials = pygsheets.authorize(outh_file=credentials)
            print("Successful authentication with: {0}".format(credentials))
        except:
            print("Failed to authenticate with: {0}, exiting with error".format(credentials))
            raise
    
    def open_sheet(self, sheet, page):
        try:
            spreadsheet = self.credentials.open(sheet)
            self.sheet = getattr(spreadsheet, page)
            print("Successful opening of sheet: {0}.{1}".format(sheet, page))
        except:
            print("Failed to open sheet: {0}.{1}".format(sheet, page))
            raise

    def start_tests(self, total=1, duration=0):
        print("[starting {0} tests, with {1} seconds delay]".format(total, duration))
        for i in range(total):
            print("test {:03d}: ".format(i+1), end='')
            previous_time = time.time()
            results = self.run_test()
            self.log_to_sheet(results)
            print(results)
            # waiting
            while time.time()-previous_time < duration:
                time.sleep(1)
        

    # return named tuple of a test
    def run_test(self):
        self.get_best_server()
        self.download()
        self.upload()
        return SpeedtestResult(self.results)

    # write results with timestamp to sheet
    def log_to_sheet(self, results):
        self.sheet.append_table(values=results.get_list())

# store a speedtest result
class SpeedtestResult:
    # units that will be used
    DEFAULT_OPTIONS = [
        UNIT("download",10**-6, "Mbps", "{:4.2f}"),
        UNIT("upload",  10**-6, "Mbps", "{:4.2f}"),
        UNIT("ping",    1,      "ms",   "{:.0f}"),
    ]

    def __init__(self, results):
        self.read_results(results)

    # get results
    def read_results(self, results):
        for option in SpeedtestResult.DEFAULT_OPTIONS:
            value = getattr(results, option.name)
            setattr(self, option.name, value)
        self.time = str(get_current_time())

    # get list representation of values
    def get_list(self):
        row_values = [self.time]
        row_values.extend([getattr(self, option.name) for option in SpeedtestResult.DEFAULT_OPTIONS])
        return row_values

    # formatted string output for console
    def __str__(self):
        output = ""
        option_formatter = "{0}={1}{2} "
        for option in SpeedtestResult.DEFAULT_OPTIONS:
            value = option.formatter.format(getattr(self, option.name)*option.scale)
            output += option_formatter.format(option.name, value, option.unit)
        output += "@ {0}".format(self.time)
        return output

if __name__ == "__main__":
    main()
