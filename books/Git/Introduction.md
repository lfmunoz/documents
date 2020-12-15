---
title: Git
mathjax: true
layout: default
toc: true
---



# Git

For a commit with only one parent, rev~ and rev^ mean the same thing. 


* Tilde ~ is almost linear in appearance and wants to go backward in a straight line
* Caret ^ suggests an interesting segment of a tree or a fork in the road

* HEAD means (the reference to the) current commit
* HEAD~1 means (the reference to) 1 commit before
* HEAD~ ALSO means (the reference to) 1 commit before
* HEAD~87 means (the reference to) 87 commits before
* HEAD~3..HEAD means from 3 commits to current commit


```
G   H   I   J
 \ /     \ /
  D   E   F
   \  |  / \
    \ | /   |
     \|/    |
      B     C
       \   /
        \ /
         A

A =      = A^0
B = A^   = A^1     = A~1
C = A^2
D = A^^  = A^1^1   = A~2
E = B^2  = A^^2
F = B^3  = A^^3
G = A^^^ = A^1^1^1 = A~3
H = D^2  = B^^2    = A^^^2  = A~2^2
I = F^   = B^3^    = A^^3^
J = F^2  = B^3^2   = A^^3^2
```

## Git log


```
git log --branches --remotes --tags --graph --oneline --decorate
git lg --all
```


## Creating patches

```bash
# Changes you made relative to the index (staging area for next commit)
git diff > add-rspec.patch

# git diff <x> <x+∆x>
git diff <branch>..<current_branch>

git diff --oneline --graph master..feature



```


You create a branch then make some changes and commit those changes. To create
a patch based on the changes you use *git format-patch [ <since> | <revision range>]*
```bash

# -o is specified, output files are created in <dir> (default current dir)

# Extract all commits which are in the current branch but not in the origin branch:
git format-patch origin

```



## Applying patches

* **git apply** provides the patch as unstaged changes
* **git am** apply the patches as commits


https://git-scm.com/docs/git-apply

```bash
# check out to the branch where you want your patch file to be applied.
git checkout <feature>


git apply --reject --whitespace=fix


git apply --3way
# 

#  use the “git am” command and specify the Git patch file to be used.
#  git am <patch_file>
git am patches/0001-My-feature-commit-1.patch

# skip a Git patch apply operation and ignore conflicts
git am --skip

# Git apply merging errors, identify the files that are causing problems, 
#  edit them, and run the “git am” command with the “–continue” option.
git am --continue
```

### References

* https://git-scm.com/docs/git-format-patch


# Setup Tips

### Problem: Git log disappears from console when you exit less

When git uses **less** as pager the output of commands like git log disappear from the console when you exit **less**. This is not convenient so here is the fix:

``` bash
# fix just for git commands:
git config --global --replace-all core.pager "less -iXFR"

# fix globally or local session
export LESS=-iXFR
```

* -i - ignore case when searching (but respect case if search term contains uppercase letters)
* -X - do not clear screen on exit
* -F - exit if text is less then one screen long
* -R - default on my system, something related to colors




# Tutorial





```bash

git lg --all
* 51e2008 - (HEAD -> featureA) // 2. Change to factorial 
| * 4840aa5 - (master) // 3. Add debugging statements 
|/  
* 69e1857 - // 1. Adding fib feature 
* bc7db88  - // 0. Start of project (skeleton)

```