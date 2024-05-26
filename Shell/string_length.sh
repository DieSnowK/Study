#!/bin/bash

for str in I am SnowK, this is a example
do
    if [ `expr length $str` -le 4 ]
    then
        echo $str 
    fi
done
