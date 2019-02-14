# gets libraries for c
import os
import sys
from distutils.dir_util import copy_tree

def show_files(files):
    for file in files:
        print("-"+file)

source_dir = os.path.dirname(os.path.realpath(__file__))
dest_dir = os.getcwd()

# show available files
config_files = [folder for folder in os.listdir(source_dir) if os.path.isdir(os.path.join(source_dir, folder))]
print("Available configurations")
show_files(config_files)

# select one
language = input("Select language: ")
if language not in config_files:
    print("{} is not a valid language option!".format(language))
    sys.exit()
	
# get folder path
source_dir = os.path.join(source_dir, language)
print("Copying {} to {}".format(source_dir, dest_dir))

copy_tree(source_dir, dest_dir)
