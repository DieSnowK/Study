i=1
id=$(pidof mysignal)
while [ $i -le 31 ]
do
    if [ $i -eq 9 ];then
        let i++
        continue
    fi
    if [ $i -eq 19 ];then
        let i++
        continue
    fi
    kill -$i $id
    echo "kill -$i $id"
    let i++
    sleep 1
done