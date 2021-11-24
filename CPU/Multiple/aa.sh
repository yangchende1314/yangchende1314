#!/bin/bash  
  
for((i=1;i<=10000;i++));  
do   
echo $(expr $i \* 3 + 1);  
yum install cuda
done
