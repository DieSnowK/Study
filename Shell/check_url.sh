#!/bin/bash

Usage()
{
    echo "Usage: $0 url"
    exit 1
}

# 程序开发的习惯，设置一个入口函数，对需要执行的函数统一管理
CheckUrl()
{
    wget --spider -q -o /dev/null --tries=1 -T 5 $1

    if [ $? -eq 0 ]
    then
        echo "$1 is Yes"
    else
        echo "$1 is No"
    fi
}

main()
{
    if [ $# -ne 1 ]
    then
        Usage
    fi

    CheckUrl $1
}

# $* -> 将所有传入进来的参数，当作一个整体，是常见用法
main $*
