#!/usr/bin/env bash



curl -fsSL https://apt.releases.hashicorp.com/gpg | sudo apt-key add -
sudo apt-add-repository "deb [arch=amd64] https://apt.releases.hashicorp.com $(lsb_release -cs) main"
sudo apt-get update && sudo apt-get install terraform
terraform -help




# Install aws cli
#  https://docs.aws.amazon.com/cli/latest/userguide/cli-chap-install.html
# /usr/local/bin/aws --version
# aws configure
