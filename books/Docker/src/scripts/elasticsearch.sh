


    elasticsearch:
        image: elasticsearch:5.6.3
        environment:
            - network.host=0.0.0.0
            - cluster.name=manage.search
            - xpack.security.enabled=false
            - discovery.type=single-node
            # reduce memory for dev/demo environment
            - "ES_JAVA_OPTS=-Xms1g -Xmx1g"
        ulimits:
            nofile:
                # elasticsearch needs at least 65536 file descriptors, default may be too low
                soft: 65536
                hard: 65536



                docker-compose -f src/main/docker/dev.yml exec usp-elasticsearch curl -XDELETE localhost:9200/manage