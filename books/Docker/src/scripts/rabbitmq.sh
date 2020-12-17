


#________________________________________________________________________________
# RabbitMQ
# #  Public port 5672  15672
# IP: 172.18.0.7
#________________________________________________________________________________

# guest / guest

rabbit-start:
        -docker run -d --rm --name rabbitmq-${RND} --network=${NETWORK} ${RABBIT_PORT} --network-alias=rabbitNet rabbitmq:3.7.2-management

rabbit-stop:
        -docker stop rabbitmq-${RND}



# VERIFIED
docker run -d --rm --name rabbitmq \
--network=host \
rabbitmq:3.8.9-management

