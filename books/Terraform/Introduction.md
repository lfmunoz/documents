---
title: Terraform
mathjax: true
layout: default
toc: true
---

# Terraform


**Terraform** is an open-source tool that is specifically dedicated to creating, modifying, and even deleting infrastructure on cloud, focusing on "Infrastructure as Code." **Infrastructure as code** means provisioning infrastructure through software to achieve consistent and predictable environments


* [](https://registry.terraform.io/)
* [https://www.terraform.io/docs/configuration/index.html](https://www.terraform.io/docs/configuration/index.html)


* Written in [The Go Programming Language](../Go/Introduction.html).
* What is running on a virtual server is outside of Terraform's scope and the responsibility of some other tool.
* Uses a declarative language known as **HashiCorp Configuration Language (HCL)** (use ruby syntax highlighting markdown)
* Terraform attemps to be **idempotent** in the sense that if you haven't changed anything about your configuration and you apply it again to the same environment, nothing will change in the environment. 
* Terraform is a push-type model. Constrast to if there was an agent running on the environment and it pulls its configuration from a central source on a regular basis.


Everything is controlled by a Command Line Interface (CLI)

* terraform init  - initializes project, downloads plugins, checks modules
* terraform plan - Analyze code and show you the changes that will be made
* terraform apply - Applying a configuration is the process of creating, updating, and destroying real infrastructure objects in order to make their settings match the configuration.
* terraform destroy - Process of destroying all the resources that were built
* terraform show
* terraform fmt  - format the .tf files
* terraform validate - validate the .tf files have correct syntaxx
* terraform graph

```bash
# specific modules
terraform apply -target=aws_security_group.my_sg -target=aws_security_group.my_2nd_sg


# run with debug
TF_LOG=DEBUG terraform apply
```


# Installation 

```bash
curl -fsSL https://apt.releases.hashicorp.com/gpg | sudo apt-key add -
sudo apt-add-repository "deb [arch=amd64] https://apt.releases.hashicorp.com $(lsb_release -cs) main"
sudo apt-get update && sudo apt-get install terraform
terraform -help

# Initialize the project, which downloads a plugin
 terraform init
 
# Install aws cli
#  https://docs.aws.amazon.com/cli/latest/userguide/cli-chap-install.html
/usr/local/bin/aws --version
aws configure
```




* https://registry.terraform.io/providers/hashicorp/null/latest/docs/resources/resource

# Overview


When you create a new configuration — or check out an existing configuration from version control — you need to initialize the directory with **terraform init**. This command will create a **.terraform/** folder in the current directory and download plugins.


**First rule of Terraform:** Make all changes in Terraform.  The State File is the truth. 

Do not store **.tfstate** into git, storing in source control could expose potentially sensitive data and risks running Terraform against an old version of state. You are likely to forget to commit and push your changes after running terraform apply, so your teammates will have out-of-date .tfstate files.  Don't do it.



# Module

* Any set of Terraform configuration files in a folder is a module. 
* A module is a container for multiple resources that are used together.
* Every Terraform configuration has at least one module, known as its root module, which consists of the resources defined in the .tf files in the main working directory.

* Explicit provider blocks appear only in the root module, and downstream modules can simply declare resources for that provider and have them automatically associated with the root provider configurations.


* Providers should be configured by the user of the module and not by the module itself.
* A module intended to be called by one or more other modules must not contain any provider blocks

To declare that a module requires particular versions of a specific provider, use a required_providers block inside a terraform block:


```ruby
# NAME is an identifier you can use throughout the Terraform code
module "<NAME>" {
  # SOURCE is the path where the module code can be found
  source = "<SOURCE>"
  # CONFIG consists of one or more arguments that are specific to that module
  [CONFIG ...]
}

module "webserver_cluster" {
  source = "../../../modules/services/webserver-cluster"
  source = "github.com/foo/modules//webserver-cluster?ref=v0.0.1"
}
```

```ruby
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
```


Terraform Cloud's main unit of organization is a workspace. A **workspace** is a collection of everything Terraform needs to run: a Terraform configuration (usually from a VCS repo), values for that configuration's variables, and state data to keep track of operations between runs.

Name your workspaces with both their component and their environment

# Provider


A **provider** is a plugin that Terraform uses to translate the API interactions with the service. Also offers a collection of resource types. 

* Every provider has its own documentation, describing its resource types and their arguments.
* Public providers are distributed on the Terraform Registry
    * https://registry.terraform.io/browse/providers
* Provider configurations belong in the root module of a Terraform configuration. 
 
```ruby
 terraform {
  required_providers {
    docker = {
      source = "terraform-providers/docker"
    }
    aws = {
      source  = "hashicorp/aws"
      version = "~> 2.70"
    }
    local = {
        source = "hashicorp/local"
        version = "2.0.0"

    }
  }
}

 
// local name
provider "aws" {
  profile = "default"
  region  = "us-west-2"
}

// local name
provider "docker" {}
```

Providers are the most common type of Plugin, which expose the features that a specific service offers via its application programming interface (API). Providers define Resources and are responsible for managing their life cycles. Examples of providers are the Amazon Web Service Provider or the Google Cloud Provider. Example resources are aws_instance and google_compute_instance.


  * https://www.terraform.io/docs/providers/docker/index.html


# Resource 
The **resource** block defines a piece of infrastructure. 

* A resource might be an EC2 instance, docker image, docker container
* Each resource type is implemented by a provider.
* The arguments within the body of a resource block are specific to the selected resource type.


```ruby
resource "aws_instance" "example" {
  ami           = "ami-830c94e3"
  instance_type = "t2.micro"
}

resource "docker_image" "nginx" {
  provider     = docker.manager
  name         = "nginx:latest"
  keep_locally = false
}

// https://registry.terraform.io/providers/hashicorp/local/latest/docs/resources/file
resource "local_file" "foo" {
    content     = "foo!"
    filename = "${path.module}/foo.bar"
}


```

meta-arguments can be used with any resource type to change the behavior:
* depends_on - for specifying hidden dependencies
* count - for creating multiple resource instances according to a count
* for_each -to create multiple instances according to a map, or set of strings
* provider - for selecting a non-default provider configuration
* lifecycle - for lifecycle customizations
* provisioner and connection - for taking extra actions after resource creation

* Official resource docs
    * https://www.terraform.io/docs/configuration/resources.html


# Provisioners

**Provisioners** can be used to model specific actions on the local machine or on a remote machine in order to prepare servers or other infrastructure objects for service.

Multiple provisioners can be specified within a resource. Multiple provisioners are executed in the order they're defined in the configuration file.

```ruby
provisioner "remote-exec" {
        inline = [
          "export PATH=$PATH:/usr/bin",
          "sudo yum -y update",
          "sudo yum -y install httpd",
          "sudo /etc/init.d/httpd start",

          "sudo wget https://raw.githubusercontent.com/javabrown/terraform_aws_single-web-server/amazon-linux-ec2-sites/web-config/rk.conf -O /etc/httpd/conf.d/rk.conf",

          "sudo mkdir /var/www/mywebsite", 

          "sudo wget https://raw.githubusercontent.com/javabrown/terraform_aws_single-web-server/amazon-linux-ec2-sites/web-config/site-1/index.html -O /var/www/mywebsite/index.html",
          "sudo service httpd restart",
        ]
}

  provisioner "remote-exec" {
    scripts = ["${path.root}/../provision_scripts/docker_install.bash"]
     on_failure = continue
  }

  provisioner "local-exec" {
    command = <<EOT
      ssh-keyscan -H ${self.public_ip} >> ~/.ssh/known_hosts
      echo ${self.public_ip} >> ${path.root}/../public-ip.txt
    EOT
  }

  provisioner "local-exec" {
    when = destroy
    command = <<EOT
      ssh-keygen -R ${self.public_ip}
    EOT
  }

```


# DependsOn

I would like to run in order as follows.

get_my_public_ip -> ec2 -> db -> test_http_status


```ruby
data "external" "get_my_public_ip" {
  program = ["sh", "scripts/get_my_public_ip.sh"]
}

module "ec2" {
  ...
}

module "db" {
  ...
}


data "external" "test_http_status" {
  program = ["sh", "scripts/test_http_status.sh"]
}
```


 You can use depends_on to explicitly declare the dependency. You can also specify multiple resources in the depends_on argument, and Terraform will wait until all of them have been created before creating the target resource.

```ruby
resource "null_resource" "test_status" {
  depends_on = ["module.db.id"] #or any output variable
  provisioner "local-exec" {
    command = "scripts/test_http_status.sh"
  }
}


resource "aws_instance" "web" {
  depends_on = ["aws_instance.leader", "module.vpc"]
}

```


The syntax of depends_on is a list of resources and modules:

Resources are TYPE.NAME, such as aws_instance.web.
Modules are module.NAME, such as module.foo.

https://www.terraform.io/docs/configuration-0-11/resources.html#explicit-dependencies

# Variables

* Variables must be unique among all variables in the same module. 
* Can be accessed from within expressions as **var.< NAME >**
* primitives include: string, number, bool
* collections include 
    * list(< TYPE >)
    * set(< TYPE >)
    * map(< TYPE >)
    * object({< ATTR NAME > = < TYPE >, ... })
    * tuple([ < TYPE >, ...])

Terraform requires that it can compute count and for_each during the plan phase, before any resources are created or modified. That means count and for_each can reference hard-coded values, variables, data sources, and even lists of resources (so long as the length of the list can be determined during plan), but not computed resource outputs.

```ruby
// string 
variable "image_id" {
  type = string
  // optional
  default = "my-imagine-id"
  // optional
  description = "The id of the machine image (AMI) to use for the server."

  // optional
  validation {
    condition     = length(var.image_id) > 4 && substr(var.image_id, 0, 4) == "ami-"
    error_message = "The image_id value must be a valid AMI id, starting with \"ami-\"."
  }
}

// List of strings
variable "availability_zone_names" {
  type    = list(string)
  default = ["us-west-1a"]
}

// List of objects
variable "docker_ports" {
  type = list(object({
    internal = number
    external = number
    protocol = string
  }))
  default = [
    {
      internal = 8300
      external = 8300
      protocol = "tcp"
    }
  ]
}

# count
variable "user_names" {
  description = "Create IAM users with these names"
  type        = list(string)
  default     = ["neo", "trinity", "morpheus"]
}
resource "aws_iam_user" "example" {
  count = length(var.user_names)
  name  = var.user_names[count.index]
}

output "neo_arn" {
  value       = aws_iam_user.example[0].arn
  description = "The ARN for user Neo"
}
output "all_arns" {
  value       = aws_iam_user.example[*].arn
  description = "The ARNs for all users"
}

# for_each

resource "aws_iam_user" "example" {
  for_each = toset(var.user_names)
  name     = each.value
}

output "all_arns" {
  value = values(aws_iam_user.example)[*].arn
}


```

```bash
# specify individual variables 
terraform apply -var="image_id=ami-abc123"
# specify variable definitions file 
terraform apply -var-file="testing.tfvars"
```

A variable definitions file 
* consists only of variable name assignments
* ends in either **.tfvars** or **.tfvars.json**

```ruby
// .tfvars
image_id = "ami-abc123"
availability_zone_names = [
  "us-east-1a",
  "us-west-1c",
]
```

```json
// .tfvars.json
{
  "image_id": "ami-abc123",
  "availability_zone_names": ["us-west-1a", "us-west-1c"]
}
```

* https://www.terraform.io/docs/configuration/outputs.html





# Patterns


```ruby
variable "create_vm_images" {
  default = true
}

resource "null_resource" "win_vm" {
  for_each = var.create_vm_images ? var.vms_to_image : {}
  ...
}
```


```bash

TF_LOG=DEBUG terraform apply
```


https://www.terraform.io/docs/provisioners/local-exec.html


# References

https://github.com/shuaibiyy/awesome-terraform


https://github.com/28mm/blast-radius


https://blog.gruntwork.io/how-to-create-reusable-infrastructure-with-terraform-modules-25526d65f73d


https://blog.gruntwork.io/terraform-tips-tricks-loops-if-statements-and-gotchas-f739bbae55f9


https://github.com/hashicorp/terraform/blob/master/CHANGELOG.md