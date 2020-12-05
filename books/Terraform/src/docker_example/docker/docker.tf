# docker.tf

# these are the input parameter of the module
# variable "name" {}
variable "ipv4" {}

# ________________________________________________________________________________
# DOCKER
#   https://www.terraform.io/docs/providers/docker/index.html
# ________________________________________________________________________________

provider "docker" {
  alias = "manager"
  host = "ssh://ubuntu@${var.ipv4}:22"
}

resource "docker_image" "nginx" {
  provider     = docker.manager
  name         = "nginx:latest"
  keep_locally = false
}

# https://www.terraform.io/docs/providers/docker/r/container.html
resource "docker_container" "nginx" {
  provider = docker.manager
  image = docker_image.nginx.latest
  name  = "nginx-container"
  # network_mode = "host"
  ports {
    internal = 80
    external = 80
  }
}
