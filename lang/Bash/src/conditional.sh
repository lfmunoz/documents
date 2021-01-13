#!/bin/bash

# ./conditional.sh


if [ -z ${var+x} ]; 
then 
    echo "var is unset"; 
else 
    echo "var is set to '$var'"; 


fi

