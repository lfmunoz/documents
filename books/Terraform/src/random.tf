


  #dynamic "ports" {
  #  for_each = {
  #    for key, value in var.config.ports:
  #    key => value if value.external != 0
  #  }
  #  # for_each = var.config.ports
  #  content {
  #    internal = ports.value.internal
  #    external = ports.value.external
  #  }
  #}



#resource "local_file" "infrastructure_output" {
#  content = jsonencode([
#    for key, value in module.docker_instance :
#    {
#      name = key
#      ports = concat(value.return[0].ports, [
#        for ckey, cvalue in var.config[key].ports :
#        {
#          "internal" = cvalue.internal
#          "ip"       = value.return[0].ip_address
#        } if cvalue.external == 0
#      ])
#
#    }
#  ])
#  filename = "${path.module}/infrastructure_output.txt"
#}


  # provisioner "remote-exec" {
    # scripts = ["${path.module}/../../provision_scripts/default_docker.bash"]
  # }

  # provisioner "remote-exec" {
    # scripts = [for script in var.config.scripts : "${path.module}/../../provision_scripts/${script}.bash"]
  # }