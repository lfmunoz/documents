# local_files/file.tf

# these are the input parameter of the module
variable "name" {}
variable "config" {}

resource "local_file" "my-file" {
    # provider    = local.bar
    content     = jsonencode(var.config)
    filename    = "${path.module}/${var.name}.txt"



  provisioner "local-exec" {
    for_each = ["a", "b"]
    command = each.value
  }

  provisioner "local-exec" {
    command = "echo '22222222222222222222222222222'"
  }

 

}


# Because you ran this as part of a module and not the root project
#  this output would not make it back to the console once applied
output "config" {
  value = var.config
}
