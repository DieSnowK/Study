#!/bin/bash

FreeMem=`free -m | awk 'NR==2 {print $NF}'`
CHARS="Current memory is $FreeMem"

if [ "$FreeMem" -lt 16000 ]
then
    echo $CHARS
    echo "内存不足，抓紧维护服务器!"
fi
