#!/usr/bin/env bash

# INSTALL BASIC UTILS
sudo apt-get update
sudo apt-get install --yes --no-install-recommends apt-transport-https ca-certificates curl lsb-release
sudo apt-get install --yes --no-install-recommends gnupg-agent software-properties-common sudo
sudo apt-get install --yes --no-install-recommends gnupg2


# INSTALL LATEST DOCKER
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo apt-key fingerprint 0EBFCD88
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu  $(lsb_release -cs) stable"
sudo apt-get update
sudo apt-get install --yes --no-install-recommends docker-ce docker-ce-cli containerd.io
sudo usermod -aG docker ubuntu
