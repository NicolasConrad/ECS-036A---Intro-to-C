#! /bin/bash

filetoCopy=$1

if [[ "$#" -le 1 ]]; then
	echo "Usage: ./cp_mult.sh [src] [dest1] ..."
	exit 1
else
	while [[ "$#" -ge 2 ]]; do
		cp $filetoCopy $2
		shift
	done
	exit 0
fi