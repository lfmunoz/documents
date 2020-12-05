
# ________________________________________________________________________________
# AWS INFRASTRUCTURE 
# ________________________________________________________________________________
# terraform show
# terraform apply
# terraform plan
# terraform destroy

AWS_ACCESS_KEY=/home/luis/github/TMP/terraform-docker-demo/eco-analytics-keypair.pem
EC2_INSTANCE=34.229.231.245
DOCKER_HOST=ssh://ubuntu@${EC2_INSTANCE}



docker-start:
	cd terraform/service; terraform init
	cd terraform/service; terraform apply
	cd terraform/service; terraform show 

docker-stop:
	cd terraform/service; terraform destroy

aws-start:
	cd terraform/server; terraform init
	cd terraform/server; terraform apply
	cd terraform/server; terraform show 

aws-stop:
	cd terraform/server; terraform destroy 

aws-valid:
	cd terraform/server; terraform fmt 
	cd terraform/server; terraform validate

#  https://docs.aws.amazon.com/cli/latest/userguide/cli-chap-install.html
aws:
	/usr/local/bin/aws --version
	#cat ~/.aws/credentials
	aws sts get-caller-identity

# find the latest AMI
aws-ami:
	aws ec2 describe-images \ --owners 099720109477 \
    --filters "Name=name,Values=ubuntu/images/hvm-ssd/ubuntu-xenial-16.04-amd64-server-????????" "Name=state,Values=available" \
    --query "reverse(sort_by(Images, &CreationDate))[:1].ImageId" \
    --output text

# For an Ubuntu AMI, the user name is ubuntu.
ssh:
	#chmod 400 ${AWS_ACCESS_KEY}
	ssh -i ${AWS_ACCESS_KEY} ubuntu@${EC2_INSTANCE}




