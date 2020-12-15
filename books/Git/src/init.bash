#!/usr/bin/env bash


git init



cp ../data/data0.c ./main.c
git add .
head -n 1 main.c | git commit -F -


cp ../data/data1.c ./main.c
git add .
head -n 1 main.c | git commit -F -


git checkout -b featureA
cp ../data/data2.c ./main.c
git add .
head -n 1 main.c | git commit -F -



git checkout master
cp ../data/data3.c ./main.c
git add .
head -n 1 main.c | git commit -F -


