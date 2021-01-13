


# 
info:
	go version


skeleton:
	go run skeleton.go

if:
	go run if.go

looping:
	go run looping.go

struct:
	go run struct.go

method:
	go run method.go

interfaces:
	go run interfaces.go


.PHONY: http
http:
	go run cmd/http/main.go

.PHONY: test unit
test:
	go test -v ./...

unit:
	go test ./...
# ________________________________________________________________________________
# GPRC
# ________________________________________________________________________________
.PHONY: grpc

grpc-client:
	go run cmd/grpc-client/client.go

grpc-server:
	go run cmd/grpc-server/main.go

proto:
	protoc --go_out=./chat --go_opt=paths=source_relative \
    --go-grpc_out=./chat --go-grpc_opt=paths=source_relative \
    api/chat.proto

