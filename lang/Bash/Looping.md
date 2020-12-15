---
title: Looping
mathjax: true
layout: default
toc: true
---




# Looping 


```bash
#!/bin/bash
# Basic while loop
counter=1
while [ $counter -le 10 ]
do
    echo $counter
    ((counter++))
done
echo All done



names='Stan Kyle Cartman'
for name in $names
do
echo $name
done
echo All done

for value in {1..5}
do
echo $value
done
echo All done



for value in {10..0..2}
do
echo $value
done
echo All done



for value in $1/*
do
used=$( df $1 | tail -1 | awk '{ print $5 }' | sed 's/%//' )
if [ $used -gt 90 ]
then
echo Low disk space 1>&2
break
fi
cp $value $1/backup/
done



```





Command substitution allows us to take the output of a command or program (what would normally be printed to the screen) and save it as the value of a variable

```bash
myvar=$( ls /etc | wc -l )
```



let is a builtin function of Bash that allows us to do simple arithmetic. It follows the basic format:

```bash
#!/bin/bash
# Basic arithmetic using let

# This is the basic format. Note that if we don't put quotes around the expression then it must be written with no spaces.
let a=5+4
echo $a # 9

let "a = 5 + 4"
echo $a # 9

let a++
echo $a # 10

let "a = 4 * 5"
echo $a # 20

```


expr is similar to let except instead of saving the result to a variable it instead prints the answer. 

Unlike let you don't need to enclose the expression in quotes.

You also must have spaces between the items of the expression.


```bash


expr 5+4
expr 5 \* $1


a=$( expr 10 - 3 )
echo $a # 7

#Double Parentheses


a=$(( 4 + 5 ))

b=$(( a + 3 ))
echo $b # 11

(( b += 3 ))

(( b++ ))

# we don't need to escape the * sign.
a=$(( 4 * 5 ))
```


```bash

# Show the length of a variable.
a='Hello World'
echo ${#a} # 11

b=4953
echo ${#b} # 4

```



```

endpointArr=(
  os::005094-0210172920300921
)



echo "=============================== RUN ============================================="
for ENDPOINT_ID in "${endpointArr[@]}"; do
  curl -k -sSD/dev/stderr -X POST --header 'Content-Type: application/json' --header 'Accept: */*' --header "Authorization: Bearer ${TOKEN}" \
    -d "${JSON}" "https://${USP_HOST}/api/workflows/$WF_ID/agent/$ENDPOINT_ID" | jq "."
done
```