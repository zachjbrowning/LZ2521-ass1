#!/bin/bash

lower_test=1
upper_test=5

if [ $# -eq 1 ]; then
    lower_test=$1
    upper_test=$1
fi 

for ((i = $lower_test; i <= $upper_test; i++));
do 
    in="tests/$i.in"
    expected="tests/$i.expected"
    out="tests/$i.out"

    ./translator tests/test_data.txt < $in > $out 

    diffs=$(diff -iad $expected $out) 


    if [ $? != 0 ]; then
        printf "TEST %d FAILED : \n%s\n\n" "$i" "$diffs"
    else
        printf "TEST %d PASSED\n\n" "$i"
    fi
done