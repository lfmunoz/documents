#!/usr/bin/env bash



# -p 5432:5432  
# -v ~/volumes/jhipster/tank/postgresql/:/var/lib/postgresql/data

docker run --name postgres --rm -d \
--network=host \
-e "POSTGRES_USER=postgres" \
-e "POSTGRES_PASSWORD=postgres" \
-e "POSTGRES_DB=monitor" \
postgres:11.3

