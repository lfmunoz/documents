# ________________________________________________________________________________
#  root module for example_aws
# Note: Any set of Terraform configuration files in a folder is a module,
#   but not all configurations files are root modules

# ________________________________________________________________________________
# PROVIDERS
# ________________________________________________________________________________
# To declare that a module requires particular versions of a 
#  specific provider, use a required_providers block 
#  inside a terraform block:
terraform {
  required_providers {
    aws = {
      source  = "hashicorp/aws"
      version = "~> 2.70"
    }
  }
  required_version = ">= 0.13"
}

# A **provider** is a plugin that Terraform uses to translate the API interactions with the service. Also offers a collection of resource types. 


# Explicit provider blocks appear only in the root module, 
# child modules can simply use resources for that 
# provider and have them automatically associated 
# with the root provider configurations.

# A provider block without an alias argument is the default configuration 
# for all the resources
provider "aws" {
  # alias  = "east"   alias not needed because we only have 1 provider
  profile = "default"
  region  = "us-east-1"
}

# ________________________________________________________________________________
# CONFIG
# ________________________________________________________________________________
variable "instances" {
  default = {
    "nginx0" = {
      scripts = ["docker/nginx"]
      type = "t2.micro"
      count   = 1
    },
    "nginx1" = {
      scripts = ["docker/nginx"]
      type    = "t2.micro"
      count   = 2
    }
  }
}

# ________________________________________________________________________________
# STAGE 1: SETUP INFRASTRUCTURE
# ________________________________________________________________________________
# A module is a container for multiple resources that are used together.
module "aws_cluster" {

  for_each = var.instances
  source   = "../../modules/aws"
  config   = merge(each.value, { name = each.key })
}


# ________________________________________________________________________________
# OUTPUT INFRASTRUCTURE
# ________________________________________________________________________________
output "aws_output" {
 value = module.aws_cluster
}

#output "docker_instance_output" {
#  value = flatten([for key, value in module.docker_instance :
#    value.return
#  ])
#}
#
#resource "local_file" "output" {
#  content = jsonencode(flatten([for key, value in module.docker_instance :
#    value.return
#  ]))
#  filename = "../${path.root}/infrastructure.json"
#}


#output "docker_instance_debug" {
# value = [for key, value in module.docker_instance : 
#   { "$key" = value.debug }
# ]
#}

#output "docker_instance_debug" {
# value = [for key, value in module.docker_instance : 
#   { "$key" = value.debug }
# ]
#}

}
}

variable "instances" {
  type = map(
    object({
      type = string
      script = string
    }))
}


// A module is a container for multiple resources that are used together.
module "aws_cluster" {
  for_each = var.instances
  source   = "./file"
  name     = each.key
  config   = each.value
}


output "instances_config" {
  value = [ for k, v in module.file_instance : v.output ]
}



