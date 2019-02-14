import subprocess
import os
import sys
import pprint
import argparse
import time

DEV_NULL = open(os.devnull, "w")
# format of output files
OUTPUT_FOLDER_FORMAT = "{folder}/title_{title:02d}"
OUTPUT_FILE_FORMAT = "chapter_{chapter:02d}.mp3"

# debugging messages
RIP_START_MSG = "starting rip: {title:02d}/{chapter:02d} @ {duration}"
RIP_ERROR_MSG = "Failed RIP: {source} to {destination}, title={title:02d}, chapter={chapter:02d}"
RIP_SUCCESS_MSG = "rip success: title: {title:02d}, chapter: {chapter:02d}, duration: {duration}"

# mount dvd
def mount_dvd(directory, destination):
	# if already mounted, unmount it
	subprocess.run(["sudo", "umount", destination])
	# mount the drive
	process = subprocess.run([
		"sudo", "mount",
		"-t", "drvfs",
		directory, destination,
	], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	# if error, just exit
	if process.returncode > 0:
		print("Failed to mount the drive")
		sys.exit(process.stderr.decode("utf-8"))

# dvd fetch config
def get_dvd_info_command(directory):
	return [
		"lsdvd",   	# name of program (sudo apt install lsdvd if not found)
		directory, 	# directory name
		"-c", 		# show all information
		"-Oy"		# format as python object
	]

# get dvd info
def get_dvd_info(directory):
	command = get_dvd_info_command(directory)
	process = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	if process.returncode > 0:
		print("Failed to extract information from dvd")
		print(process.stderr.decode("utf-8"))
		sys.exit()
	dvd_byte_info = process.stdout[len("lsdvd = "):] # remove variable assignment from pythonfied output
	dvd_info = eval(dvd_byte_info)			 		 # evaluate into python object
	# pprint.pprint(dvd_info)
	return dvd_info

# get dvd ripping command
# creates directory if it doesnt exist
def get_dvd_rip_command(directory, title, chapter, output_dir):
	# if folder doesnt exist, create it
	output_folder = OUTPUT_FOLDER_FORMAT.format(folder=output_dir, title=title)
	output_file = OUTPUT_FILE_FORMAT.format(chapter=chapter)
	filename = "{}/{}".format(output_folder, output_file)
	if not os.path.exists(output_folder):
		os.makedirs(output_folder)
	# return a valid command string with existing directory
	return [
		"transcode",
		"-i", directory,								# set directory of dvd
		"--import_with", "null,dvd", 					# import type
		"--export_with", "null,tcaud",					# export type
		"--title", "{},{}".format(title, chapter), 		# select section to rip (title, chapter, angle)
		"--extract_track", "0",							# which audio track to extract
		"--export_afmt", "44100,16,2", 					# format of sound track (sample rate, bits, channels)
		"--lame_preset", "standard", 					# config of export
		"--audio_output", filename, 					# output file
	]
	
# rip a section from the dvd
def rip_dvd_section(directory, title, chapter, output_dir):
	command = get_dvd_rip_command(directory, title, chapter, output_dir)
	process = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	if process.returncode > 0:	# failed rip
		print(RIP_ERROR_MSG.format(source=directory,
								   destination=output_dir,
								   title=title,
								   chapter=chapter))
		print(process.stderr.decode("utf-8"))
		sys.exit()

# parse arguments
def parse_arguments():
	parser = argparse.ArgumentParser(description='Rip music off dvds.')
	parser.add_argument('drive_directory', 
						help='Path to the dvd drive')
	parser.add_argument('--mount_dir', 
						dest='mount_dir', 
						help='Path to mount the drive',
						default='dvd_mounts/dvd_mount')
	parser.add_argument('-o', 
						dest='output_dir', 
						help='Folder to output ripped music to',
						default='dvd_rips/dvd_out')
	return parser.parse_args()

# return a valid directory that has not been occupied yet
# prevent deletion of existing dvd rips
# will create a new valid directory
def get_unused_directory(directory):
	current_dvd = 0
	unique_directory = directory
	while True:
		try:
			os.makedirs(unique_directory)
			break
		except Exception as ex:
			unique_directory = "{}_{}".format(directory, current_dvd)
			current_dvd += 1
			continue
	return unique_directory
	
# start ripping dvd
def main():
	args = parse_arguments()
	# retrieve parameters
	drive_dir = args.drive_directory
	mount_dir = get_unused_directory(args.mount_dir)
	output_dir = get_unused_directory(args.output_dir)
	# mount and get dvd info
	mount_dvd(drive_dir, mount_dir)
	dvd_info = get_dvd_info(mount_dir)
	# show dvd info before rip
	tracks = dvd_info['track']
	total_tracks = len(tracks)
	print("Ripping {} titles, from \"{}\" to \"{}\"".format(total_tracks, drive_dir, output_dir))
	# go through each track and rip it
	for track in tracks:
		chapters = track["chapter"]
		total_chapters = len(chapters)
		title = int(track["ix"])
		print("title: {:02d}, chapters: {:02d}".format(title, total_chapters))
		for chapter in chapters:
			chapter_number = int(chapter["ix"])
			duration = time.strftime("%H:%M:%S", time.gmtime(float(chapter["length"])))
			print(RIP_START_MSG.format(title=title, chapter=chapter_number, duration=duration), 
				  end="\r")
			rip_dvd_section(mount_dir, title, chapter_number, output_dir)
			print(RIP_SUCCESS_MSG.format(title=title, chapter=chapter_number, duration=duration))
			

			
		
if __name__ == "__main__":
	try:
		main()
	except KeyboardInterrupt:
		sys.exit("Cancelling dvd rip")
		
	
	
