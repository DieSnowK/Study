#!/bin/bash

CheckUrl()
{
    timeout=5
    fails=0
    success=0

    while true
    do
        wget --timeout=$timeout --tries=1 snowk.x3322.net:9098 -q -O /dev/null

        # 如果状态码!=0，就报错
        if [ $? -ne 0 ]
        then
            let fails+=1
        else
            let success+=1
        fi

        if [ $success -ge 1 ]
        then
            echo "It's success :P"
            exit 0
        fi

        # 如果出错次数大于2，就告警
        if [ $fails -ge 2 ]
        then
            echo "It's dead :("
            exit 2
        fi
    done
}

CheckUrl
