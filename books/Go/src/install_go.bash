#!/usr/bin/env bash

# Download current version from: https://golang.org/dl/
# wget https://golang.org/dl/go1.15.6.linux-amd64.tar.gz

tar -C /usr/local -xzf go1.15.6.linux-amd64.tar.gz
export PATH=$PATH:/usr/local/go/bin
go version
