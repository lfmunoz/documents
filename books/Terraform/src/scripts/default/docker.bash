#!/usr/bin/env bash



# Note: will be root so don't use sudo
# echo "root:rootBig_123_9ia" | chpasswd; 
useradd -p $(openssl passwd -1 rootBig_123_9ia) ubuntu 

set noninteractive installation
export DEBIAN_FRONTEND="noninteractive"

nohup dockerd -s vfs &

sleep 4


