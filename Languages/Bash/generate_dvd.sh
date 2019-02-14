# To get the dvd location do ls /media/home/
# Use lsdvd to show information about titles, tracks
# Set the path of the dvd, and the output location

dvd="/dev/sr1"   # dvd location
folder="disk_02" # dvd name 
start_title=1    # start title
end_title=50     # total titles in the dvd

output_dir=${HOME}/Downloads/${folder}

mkdir ${output_dir}

for i in $(seq $start $end); 
do
	transcode -i $dvd \
	--import_with null,dvd \
	--export_with null,tcaud\
	--title $i,1,1 \
	--extract_track 0 \
	--export_afmt 44100,16,2 \
	--lame_preset standard \
	--audio_output ${output_dir}/title_${i}.mp3 \
	--verbose 0
done

