# ________________________________________________________________________________
# INPUT VARIABLES
# ________________________________________________________________________________
variable "config" {
  default = {
    name = "blank_name"
    scripts = []
    count  = 1
  }
}

# ________________________________________________________________________________
# DOCKER
# https://registry.terraform.io/providers/kreuzwerker/docker/latest/docs
# ________________________________________________________________________________
# Create a container
resource "docker_container" "container" {
  count       = var.config.count
  image      = docker_image.ubuntu.latest
  name       = "${var.config.name}_${count.index}"
  hostname   = "docker_${var.config.name}"
  privileged = true

  # https://www.terraform.io/docs/provisioners/connection.html
  connection {
    host     = self.ip_address
    port     = 22
    type     = "ssh"
    user     = "root"
    password = "root"
  }

  provisioner "local-exec" {
    command = <<EOT
    sleep 3
    ssh-keyscan -H ${self.ip_address} >> ~/.ssh/known_hosts
    SSHPASS=root sshpass -e ssh-copy-id root@${self.ip_address}
  EOT
  }

  provisioner "local-exec" {
    when    = destroy
    command = <<EOT
     ssh-keygen -R ${self.ip_address}
   EOT
  }

}

# ________________________________________________________________________________
# COPY AND EXECUTE DEFAULT PROVISION SCRIPT
#  Note: This is used to so make sure that all Ubuntu instances have 
#   a similar environment (i.e., change default pw, start services)
# ________________________________________________________________________________
module "default_provision" {
  count = var.config.count
  source = "../copy"
  config = {
    ssh_host    = docker_container.container[count.index].ip_address
    ssh_port    = 22
    username    = "root"
    password    = "root"
    source      = "${path.module}/../../provision_scripts/default/docker.bash",
    destination = "/root/default.bash"
    execute     = true
  }
}

# ________________________________________________________________________________
# DOCKER IMAGE (DOWNLOAD)
#  Note: This is a Ubuntu image "fully loaded". The bigger the better becase
#   images are shared between intances, would be way slower and not space
#   efficient to have to download dependencies on each instance.
# 
#  docker exec -it c1edd671b165 /bin/bash
# ________________________________________________________________________________
resource "docker_image" "ubuntu" {
  keep_locally = true
  name = "lfmunoz4/bertha:2.0.0"
}

# ________________________________________________________________________________
# OUTPUT VARIABLES
# ________________________________________________________________________________
output "return" {
   value = [ for index, value in docker_container.container : {
    name = value.name
    gateway = value.gateway
    ip_address = value.ip_address
    scripts = var.config.scripts
   }]
}

output "debug" {
  value = docker_container.container
}
