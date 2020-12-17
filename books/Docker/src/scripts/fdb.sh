fdb-start:
        docker run -d --rm --name fdb \
                --network=host \
                -e  FDB_COORDINATOR_PORT=4500 \
                -e  FDB_COORDINATOR=${FB_SERVER} \
                lfmunoz4/fdb:1.0.0


fdb-stop:
        docker stop fdb



