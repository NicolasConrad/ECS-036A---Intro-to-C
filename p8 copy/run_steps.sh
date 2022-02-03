#! /bin/bash

executable=$1
start=$2
step=$4
end=$3
outputFile=$5
num=0

if [[ $# -le 4 ]]; then
	echo "Usage: ./run_steps.sh [executable] [start] [end] [step] [outfile]"
	exit 1
else
	while [[ $(($start+(($step*$num)))) -le $end ]]; do
		if [[ $num -eq 0 ]]; then
			echo "=== $(($start+$step*$num)) ===" > $outputFile
			$executable "$(($start+$step*$num))" >> $outputFile
			num=$((num+1))
		else
			echo "=== $(($start+$step*$num)) ===" >> $outputFile
			$executable "$(($start+$step*$num))" >> $outputFile
			num=$((num+1))
		fi
	done
	exit 0
fi