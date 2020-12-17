# ________________________________________________________________________________
# API
# ________________________________________________________________________________
API_HOST="localhost"

TOKEN=$(shell curl \
  -d 'client_id=usp-control' \
  -d 'client_secret=414fcf10-6fa7-45c9-895f-e94314f11676' \
  -d 'username=admin' \
  -d 'password=admin' \
  -d 'grant_type=password' \
  'http://localhost:9080/auth/realms/ECO/protocol/openid-connect/token' \
| jq '.access_token' | tr -d '"')

env:
	echo ${TOKEN}
	curl -v -H "Authorization: Bearer ${TOKEN}" \
  -H "Accept: application/json" \
  'http://localhost:8080/management/env'