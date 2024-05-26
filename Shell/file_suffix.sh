#!/bin/bash

if expr $1 ":" ".*\.jpg" &> /dev/null
then
    echo "This is a jpg file"
else
    echo "It's not a jpg file"
fi
