


    cockroachdb:
        image: cockroachdb/cockroach:v20.1.4
        command: start --insecure --host=0.0.0.0 --http-port=8280


	docker-compose -f src/main/docker/dev.yml exec usp-elasticsearch curl -XDELETE localhost:9200/manage
