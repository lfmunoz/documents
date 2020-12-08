

# ________________________________________________________________________________
# DEFAULT
# ________________________________________________________________________________


.PHONY: info

info:
	openssl version

# ________________________________________________________________________________
# GENERATE PRIVATE AND PUBLIC KEY PAIR
# ________________________________________________________________________________
keypair: server-private.key server-public.key

LENGTH=2048

# RSA 
# Note: $@ is target being generated
server-private.key:
	openssl genrsa -out $@ 2048

# Note: $< is first prerequisite
server-public.key: server-private.key
	openssl rsa -in $< -pubout -out $@

# ________________________________________________________________________________
# GENERATE CSR
# ________________________________________________________________________________
CN=jenkins
OU=Engineering Department

# Create a certificate signing request (CSR)
server.csr: server-private.key
	openssl req -new -key $< -out $@ \
		-subj "/C=US/ST=Texas/L=Austin/O=LFM/OU=$(OU)/CN=$(CN)"

# ________________________________________________________________________________
# SING YOUR OWN CSR
# ________________________________________________________________________________
SERVER_DAYS=3650

cert: server.crt server-public.key

# Note $^ is all the prerequisites.
#  The word function takes the nth word (starting from 1)
server.crt: server.csr server-private.key
	openssl x509 -req -days $(SERVER_DAYS) -in $< -signkey $(word 2, $^) -out $@

view-server: server.crt
	openssl x509 -text -in $< -noout


# ________________________________________________________________________________
# CREATE A CLIENT CERT
# ________________________________________________________________________________
SERIAL_NUMBER = 1001
CLIENT_DAYS=365
CLIENT_CN=app

client-cert: client.crt

client-private.key: 
	openssl genrsa -out $@ 2048

client.csr: client-private.key
	openssl req -new -key $< -out $@ \
		-subj "/C=US/ST=Texas/L=Austin/O=LFM/OU=$(OU)/CN=$(CLIENT_CN)"

#  -outform PEM 
client.crt: client.csr server.crt server-private.key
	openssl x509 -req -in $(word 1, $^)  -CA $(word 2, $^)  -CAkey $(word 3, $^) \
		-set_serial $(SERIAL_NUMBER) -extensions client -days $(CLIENT_DAYS) -out $@

view-client: client.crt
	openssl x509 -text -in $< -noout

# ________________________________________________________________________________
# HELPER METHODS
# ________________________________________________________________________________
.PHONY: clean

clean:
	rm -rf *.key
	rm -rf *.csr
	rm -rf *.crt

