#!/bin/bash

path=/scripts

[ ! -d "$path" ] && mkdir -p scripts

cat << END
    1.[install lamp]
    2.[install inmp]
    3.[exit]
END

read -p "Pls input your choice:> " num

# 判断输入是否合法
[[ ! $num =~ [1-3] ]] && {
    echo "The num you input must be in {1|2|3}"
    echo "Input Error"
    exit 1
}

[ $num -eq 1 ] && {
    echo "start installing lamp...waiting..."
    sleep 2

    # 如果该脚本没权限
    [ ! -x "$path/lamp.sh" ] || {
        echo "The file does not exit or can't be exec"
        exit 2
    }

    # 安装脚本
    source ${path}/lamp.sh
    exit $?
}

[ $num -eq 2 ] && {
    echo "start installing lnmp...waiting..."
    sleep 2
    [ ! -x "$path/lnmp.sh" ] || {
        echo "The file does not exit or can't be exec"
        exit 3
    }
    source ${path}/lnmp.sh
    exit $?
}

[ $num -eq 3 ] && {
    echo "Bye~"
    exit 4
}

