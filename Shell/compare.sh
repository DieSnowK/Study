#!/bin/bash

a=$1
b=$2

if [ $a -lt $b ]
then
    echo "Yes, $a less than $b"
    exit 0
fi

if [ $a -eq $b ]
then
    echo "Yes, $a equal $b"
    exit 0
fi

if [ $a -gt $b ]
then
    echo "Yes, $a greater than $b"
    exit 0
fi
