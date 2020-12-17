#!/usr/bin/env bash

# verified

# -p 3000:3000
# or 
# --network=host \


# -e GF_SERVER_HTTP_PORT=80 \
# EROR[12-15|18:55:12] Stopped HTTPServer                       logger=server reason="listen tcp 0.0.0.0:80: bind: permission denied"
# even when runnign this script as root


# -v ./grafana/provisioning/:/etc/grafana/provisioning/

# All options in the configuration file can be overridden using environment variables using the syntax:
# GF_<SectionName>_<KeyName>

# admin / 2wire

# docker run --name grafana -it --rm  \
docker run --name grafana --rm -d \
-p 80:3000 \
-e GF_SECURITY_ADMIN_PASSWORD=2wire \
-e GF_USERS_ALLOW_SIGN_UP=false \
-e GF_INSTALL_PLUGINS=grafana-piechart-panel \
grafana/grafana:6.4.3





