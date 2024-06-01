#!/bin/bash

read -p "Pls input a char:> " var1

[ "${var1}" -eq 1 ] && {
    echo ${var1}
    exit 0
}

[ "$var1" -eq 2 ] && {
    echo $var1
    exit 0
}

[ "$var1" -ne "1" -a "$var1" -ne "2" ] && {
    echo "Script Error"
    exit 1
}
