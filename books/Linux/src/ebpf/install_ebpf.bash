#!/usr/bin/env bash

# check what linux kernel version youa are on
cat /etc/lsb-release
uname -a

# check kernel compilation options
grep BPF /boot/config-`uname -r`


# Look at documentation
# https://github.com/iovisor/bcc/blob/master/INSTALL.md#ubuntu---binary

# Download examples
# git clone https://github.com/iovisor/bcc

# Download tools
# sudo apt-get install bpfcc-tools linux-headers-$(uname -r)

# Install from source 
sudo apt-get -y install bison build-essential \ 
    cmake flex git libedit-dev libllvm6.0 llvm-6.0-dev \ 
    libclang-6.0-dev python zlib1g-dev libelf-dev

git clone github.com/iovisor/bcc.git
mkdir bcc/build; cd bcc/build 
cmake .. -DCMAKE_INSTALL_PREFIX=/usr 
make 
sudo make install 

# Check it works
sudo opensnoop-bpfcc
sudo ./examples/hello_world.py

