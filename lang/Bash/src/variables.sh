#!/bin/bash

a="variable called a"
b="variable called b"

# Under normal circumstances Bash uses a space 
#  to determine separate items.

#  ./skeleton.sh: line 15: Number: command not found
WRONG=Variable Number 1

# ./skeleton.sh: line 18: WRONG: command not found
WRONG = Variable Number 1

# Double quotes will allow you to do substitution 
VAR_A="a=$a"
echo $VAR_A  # a=variable called a

# Single quotes will treat every character literally.
VAR_B='b=$b'
echo $VAR_B # b=$b

echo $VAR_C  # prints a blank line
VAR_C="c is declared after used"
echo $VAR_C # c is declrated after used

