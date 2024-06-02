#!/bin/bash

if [ "$#" -ne 1 ]
then
    echo "Usage: $0 {start|stop|restart}"
    exit 1
fi

if [ "$1" = "start" ]
then
    /usr/bin/rsync --daemon
    sleep 2

    if [ `netstat -tunlp | grep rsync | wc -l` -ge 1 ]
    then
        echo "Rsync is started"
        exit 0
    fi
elif [ "$1" = "stop" ]
then
    killall rsync &>/dev/null
    sleep 2

    if [ `netstat -tunlp | grep rsync | wc -l` -eq 0 ]
    then
        echo "Rsync is stopped"
        exit 0
    fi
elif [ "$1" = "restart" ]
then
    kill rsync
    sleep 1

    killpro=`netstat -tunlp | grep rsync | wc -l`
    /usr/bin/rsync --daemon
    sleep 1
    
    startpro=`netstat -tunlp | grep rsync | wc -l`

    if [ "$killpro" -eq 0 -a "$startpro" -ge 1 ]
    then
        echo "Rsync is restarted"
        exit 0
    fi
else
    echo "Usage: $0 {start|stop|restart}"
    exit 1
fi
