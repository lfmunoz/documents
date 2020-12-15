#!/bin/bash
# bash ./cmd_line_args.sh one two three four five six seven eight nine ten eleven twelve

# The name of the Bash script.
echo $0 
# ./cmd_line_args.sh

# The first 9 arguments to the Bash script. 
echo $1 
# one
echo $2 
# two
echo $3 
# three
echo $4 
# four
echo $5 
# five
echo $6 
# six
echo $7 
# seven
echo $8 
# eight
echo $9 
# nine

echo ${10} 
# ten

# How many arguments were passed to the Bash script.
echo $#
# 12

# All the arguments supplied to the Bash script.
echo $@
# one two three four five six seven eight nine ten eleven twelve

# The exit status of the most recently run process.
echo $?
# 0 
