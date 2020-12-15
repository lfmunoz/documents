
#  Types:
#       t2.micro    1vcpu    1 gig
#       t2.small    1vcpu    2 gig
#       t2.medium   2vcpu    4 gig
#       t2.large    2vcpu    8 gig
#       t2.xlarge   4vcpu    16 gig

instances = {
    "redis" = {
        type = "t2.micro"
        script = "default.bash"
    },
    "postgres" = {
        type = "t2.micro"
        script = "default.bash"
    }
}
