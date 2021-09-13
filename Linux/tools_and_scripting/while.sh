#!/usr/bin/env bash
count=0
while true; do
 ./test.sh &> tmp
 if [[ $? -ne 0 ]]; then 
 break
 fi
 count=$[count+1]
done
echo "total run times: $count"
cat tmp
