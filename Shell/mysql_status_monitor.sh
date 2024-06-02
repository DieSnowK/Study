#!/bin/bash

if [ `netstat -tunlp | grep mysql | wc -l` -ge "1" ]
then
    echo "MySQL is running"
else
    echo "MySQL is stopped"
    # systemctl start mysql.service
fi
