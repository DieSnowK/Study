#!/bin/bash
Usage()
{
    printf "Error! Please enter an integer\n"
    exit 1
}

# 接收用户输入的命令，-p参数后面写给用户看到的提示信息
read -p "Please input your number> " first

# 进行对用户输入判断 --> if语句
# 限制用户必须输入纯数字
# []里面前后必须有一个空格，是固定语法
# -n，如果字符串为空，则条件不成立，如果不为空，则条件成立
# sed的作用是把字符串进行替换，把所有的数字都替换为空，那么就剩下其他的非数组内容了
if [ -n "`echo $first | sed 's/[0-9]//g'`" ]
    then
        Usage
fi

read -p "Please input your operator> " operator
if [ "$operator" != "+" ] && [ "$operator" != "-" ] && [ $operator != "*" ] && [ $operator != "/" ]
    then
        echo "只允许输入+-*/"
        exit 2
fi

read -p "Please input your number> " second
if [ -n "`echo $second | sed 's/[0-9]//g'`" ]
    then
        Usage
fi

echo $(($first $operator $second))
