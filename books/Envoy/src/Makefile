


PWD := $(shell pwd)
# ________________________________________________________________________________
# Start Ubuntu on a docker instance 
# ________________________________________________________________________________
start: 
	-docker start envoy
	# <hostPort>:<containerPort>
	#  3080 on loclahost will go to 80 inside container
	-docker run -d -p 3080:80 -p 9901:9901 --name envoy --privileged \
		-v $(PWD)/:/root/tools \
		lfmunoz4/bertha:2.0.0

bash:
	docker exec -it envoy /bin/bash

stop: 
	-docker stop envoy
	# -docker rm envoy



# ________________________________________________________________________________
# Examples
# ________________________________________________________________________________
e1:
	envoy -c proxy_http.yaml

e2:
	envoy -c proxy_https.yaml

e3:
	envoy -c proxy_tcp.yaml