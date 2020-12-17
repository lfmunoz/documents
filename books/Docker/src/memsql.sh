

#________________________________________________________________________________
# MemSQL
#  Public port
#   8080 (UI)  mapped to 8092
#   3306
#
#________________________________________________________________________________
# include ../flink-element-property-aggregate/src/main/docker/memsql_license.env
memsql-start:
        echo mesql-start

#       -docker run -d --rm --name memsql-${RND} --network=${NETWORK}  ${MEMSQL_PORT} --network-alias=memsql \
#           -e "LICENSE_KEY=${LICENSE_KEY}" \
#           -e "START_AFTER_INIT=Y" \
#           memsql/cluster-in-a-box

memsql-stop:
        echo mesql-stop
#       -docker stop memsql-${RND}




