#!/usr/bin/env bash

git lg --all

git checkout featureA
git diff HEAD^..HEAD > featureA.patch
cat featureA.patch

git checkout master
git apply  --3way  featureA.patch
# git apply --ignore-whitespace --ignore-space-change --3way  featureA.patch
# git checkout --theirs main.c
# git checkout --ours main.c

# Note: At this point main.c has conflicts embedded in the file
# Manually resolve conflicts 
git mergetool

git add main.c

git commit -m"Applied the patch"

