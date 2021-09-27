#!/bin/bash

count=1

if [ $# -eq 1 ]; then
    count=$1
fi 

for ((i = 1; i <= $count; i++));
do
    file_in="tests/$i.in"
    file_out="tests/$i.expected"
    ./translator tests/test_data.txt < $file_in > $file_out 
done