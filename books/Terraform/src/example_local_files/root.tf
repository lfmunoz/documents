
terraform {
  required_providers {
    local = {
        source = "hashicorp/local"
        version = "2.0.0"
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


module "file_instance" {
  for_each = var.instances
  source   = "./file"
  name     = each.key
  config   = each.value
}


output "instances_names" {
  value = [ for k, v in module.file_instance : k]
}

output "instances_config" {
  value = [ for k, v in module.file_instance : v.config ]
}

output "path_root" {
  value = "path.root = ${path.root}"
}

