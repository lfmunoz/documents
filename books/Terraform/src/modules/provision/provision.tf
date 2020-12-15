




variable "config" {
  default = []
}



module "copy_muliple_instance" {
 count = length(var.config)
 source   = "../copy_multiple"
 config = {
   host    = var.config.value[count.index].ip_address
   name    = var.config.value[count.index].name
   scripts = var.config.scripts
   count   = 1
 }
}

output "provison_output" {
    value =  var.config
}



# variable "config" {
#   default = {
#     name    = "myservice"
#     value   = {}
#     scripts = []
#   }
# }





# This module will copy and possibly execute multiple files
#module "provision_instance" {
#  count = (var.config.count != 0) ? length(var.config.scripts) : 0
#  source = "../copy"
#  config = {
#    ssh_host    = var.config.host
#    ssh_port    = 22
#    username    = "root"
#    password    = "root"
#    source      = "${path.module}/../../provision_scripts/${var.config.scripts[count.index]}.bash",
#    destination = "/root/${basename(var.config.scripts[count.index])}.bash"
#    execute     = true
#  }
#}

#resource "local_file" "infrastructure_output" {
#  #  count = (var.config.count != 0) ? length(var.config.scripts) : 0
#  content  = "works"
#  filename = "${path.module}/${var.config.scripts[0]}.bash"
#}

