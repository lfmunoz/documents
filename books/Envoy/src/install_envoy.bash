#!/usr/bin/env bash

sudo apt update
sudo apt install -y apt-transport-https ca-certificates curl gnupg-agent software-properties-common
curl -sL 'https://getenvoy.io/gpg' | sudo apt-key add -
# verify the key
apt-key fingerprint 6FF974DB | grep "5270 CEAC"
sudo add-apt-repository "deb [arch=amd64] https://dl.bintray.com/tetrate/getenvoy-deb $(lsb_release -cs) stable"
sudo apt update
sudo apt install -y getenvoy-envoy

