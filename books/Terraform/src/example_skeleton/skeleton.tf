
terraform {
  required_providers {
    aws = {
      source  = "hashicorp/aws"
      version = ">= 2.7.0"
    }
    local = {
        source = "hashicorp/local"
        version = "2.0.0"
    }

  }
}



variable "image_id" {
  type = string
  default = "my-imagine-id"
  description = "The id of the machine image (AMI) to use for the server."
}


output "instance_ip_addr" {
  value = var.image_id
}




module "ec2_servers" {
  source   = "./aws"
  name     = "xx"
}

