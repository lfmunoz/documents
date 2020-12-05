
# ________________________________________________________________________________
# PROVIDERS
# ________________________________________________________________________________
terraform {
  required_providers {
    docker = {
      source = "terraform-providers/docker"
    }
  }
}

variable "instances" {
  type = map(
    object({
      type = string
      script = string
    }))
}


module "docker_instance" {
  for_each = var.instances
  source   = "./file"
  name     = each.key
  config   = each.value
}


output "instances_config" {
  value = [ for k, v in module.file_instance : v.output ]
}



