---
title: Makefile
mathjax: true
layout: default
toc: true
---



# Makefile



* make with no arguments executes the first rule in the file. 
* special constants 
  * CFLAGS is the list of flags to pass to the compilation command.

 $@ $^

 %.o





```bash

CC=gcc
CFLAGS=-I.
DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.o hellofunc.o 
	$(CC) -o hellomake hellomake.o hellofunc.o 

```



$@ says to put the output of the compilation in the file named on the left side of the :, the $< is the first item in the dependencies list, and the CFLAGS macro is defined as above.





 ```bash
# ________________________________________________________________________________
# DEVELOPMNET
# ________________________________________________________________________________
APP_DIR = ./src



default: src/main/mainApp.go
	go run src/main/mainApp.go

test:
	go test ./src/... -v

# ________________________________________________________________________________
# PRODUCTION
# ________________________________________________________________________________


# ________________________________________________________________________________
# INFO
# ________________________________________________________________________________
.PHONY: info

info:
	@go version


 ```




References
https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/




https://stackoverflow.com/questions/19475037/function-and-difference-between-and-in-makefile/19476225