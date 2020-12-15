#!/usr/bin/env bash

# INSTALL BASIC UTILS
sudo apt-get update
sudo apt-get install --yes --no-install-recommends apt-transport-https ca-certificates curl
sudo apt-get install --yes --no-install-recommends gnupg-agent software-properties-common

# INTALL SSHD
#sudo apt-get install --yes --no-install-recommends openssh-server
#sudo ufw allow ssh

