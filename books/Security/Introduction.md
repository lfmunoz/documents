


Most users turn to OpenSSL because they wish to configure and run a web server that supports SSL. That process consists of three steps:

* (1) generate a strong private key,
* (2) create a Certificate Signing Request (CSR) and send it to a CA, and
* (3) install the CA-provided certificate in your web server.

# Generate a strong private key

You must make several decisions:

* Key algorithm - OpenSSL supports RSA, DSA, and ECDSA keys.
    * For web server keys everyone uses RSA, because DSA keys are effectively limited to 1,024 bits and ECDSA keys are yet to be widely supported by CAs.
    * For SSH ECDSA because it is not supported by all clients, but yours will be :)
* Key size - default key sizes are not secure
    * Aim also to use 2,048 bits for DSA keys and at least 256 bits for ECDSA.
* Passphrase


```bash
#To generate an RSA key, use the genrsa command:
# -aes128, -aes192 and -aes256 are used to password protect the key
openssl genrsa -aes128 -out fd.key 2048
Generating RSA private key, 2048 bit long modulus
....+++++
................................+++++
e is 65537 (0x10001)
Enter pass phrase for fd.key:
Verifying - Enter pass phrase for fd.key:

# Let us look at the one file that was generated
cat fd.key              
-----BEGIN RSA PRIVATE KEY-----
Proc-Type: 4,ENCRYPTED
DEK-Info: AES-128-CBC,9E794BE96D82C265A1B8F88F6D744EE0

IW56jUEltMvuslAnAs5pbkraaFsMKppSEMc/dLLCTK4AnLmBrsefAynJ7Dqwxq6d
Ml8atgvCyMg0AJ0f/DCGyoC3J91cnS89yalbaozoSmryDy3rU3YijoceDKskGNZG
8xO8jFNUCrrGqypoNmfa+wB82iAYySCoDR07zGpzBKr45pAhGhR79MKB3ux8mzAg
W+I/4y+/YvkQ4SVgoWtFnb38Rdv+nw+kq4bnUnhJnHNK9suGr0sYRdCFV3uLsknQ
GIkpjHTj7hA1EUQl/edN5U0mFSkLeDHQV2OVD6Ou62a3VZ3i5cS6qGPT4DXoZu0K
3fTajokjLeUOA3e0goJS5VfPGaVFQZ9FAcaZc8CJZXXw3+21Fbvsa+ao0Fa6AQYx
wnmD/JzXkAMSh04L4k1WZbFFRxSJPaQwzstiQ5sss5YIcEbUOJHTJyCi2kyAX5qA
dxLcBwG1TQ/fOcXoKwv01slyYe2hi9onx7Fn3uhtGjoYAjuObzoZp5UZdrUScZVH
jKhc3Ghf28N7Kwn0MYlk41yuqSn+EnCxYW+6qbuBSQeiIfmL8Xy/N1Cxr3bgb9L5
W9HvO+nXmO0+D5xI4zCrsF53f82DJ5/CFIvAqXs6KbdLyqvoZzXB9YguexDiTzLx
A5FgK+JUnp/TtSMA8ojUp1VTCWMjP98rY1meSloaPOVQeHb5HHqa9IK6zEEZBDQa
jfUTbsmdzUpUzIsrWFO1LKDbf/gILDJYx+02xIuXj+WQCTgwRt7eOdL0qIutJRwr
jfcTXCqHL7Vh8vq6o0qJDpCUlnJmNVI4lpFKtlIfwwmCYdNk36jsITuTy2JQjZZ5
j29UDWSbBIE4xUrvoB8shFowHwNtx5QpuRCVyPPen7147acy6wzjDOOTsu21Sit+
psrxcinN6zWJXGF3c3eEEmSCLjSZPEaIpDjHfX6+rf8XmYvgjPt826I2qWS4KDZ9
KcPDZmQDlOr5uMZLzBBCjeTe5749h2NWUZhRNvsZepaee8onQ2hfTxexA0YXOe5I
2cQ/R4joDwbFh5TqN6boxagmMw6DNC0AbPSUyz29MXFoOVv1Y0UQ9TywYV1VgnUN
3onsMsSMspboycOqmHOr7Opa11NmQP2gjd/X/s4dRSU/+u3e96UJPArPQC1WKal3
sRFwfGbgAJCXglU5CtY6UPvcQbDt9lPe5YCExP653hucuIfLzatFcLUWC4prkUGJ
ZhL+YK7rW5N4hWyEQmxWSbCF2sSYx+ItpjwdxmjJ2X0ByXvPG8nfgpML7JAgBBtv
edsC+lNNcpNY6RYt6j+82U5xO2eb9vwh4kIE8Ba13kwf7fQZEOLW1SJPCi+EsFTR
TFaNcMfXJsY0ILPdUfB5A59G3Oz+Djac/0J5Ruph7WAE4PXGsbUbPAr7PnQ5H8dS
XsaI3WzF43F6vHcUflDxKLsk/I1K3gMSgeZLPRNMfAT548xoOlb30YrNbM/p8dbT
eoI+olV+3EXG6i1a+qiTNS71L7v1bicvbbXaf1OwpL0gxXLK5swBSJSuY4PVkdTK
jnBeKawAiYxwUyuOgT64n1e3UyOTL9QqctsUAEZOurrZUXvQXxj9T9a8MAEgvhsc
-----END RSA PRIVATE KEY-----


# You can see a key’s structure using the following rsa command:
openssl rsa -text -in fd.key
Private-Key: (2048 bit)
modulus:
    00:c1:75:7a:a1:9b:52:e4:40:df:8d:83:98:37:98:
    40:e0:60:42:d4:82:c7:91:e9:0d:91:be:fb:f5:9f:
    9d:54:8b:c6:be:72:44:ce:11:5f:a2:1b:dc:b1:85:
    eb:32:21:be:66:5e:0e:8d:0c:35:a6:9a:dd:ce:8b:
    83:86:9f:16:25:1a:15:2f:1a:0e:25:bb:d4:f0:6e:
    44:73:70:a2:cc:fb:c2:ea:37:f9:fd:19:64:26:d5:
    4e:06:5e:c1:cc:95:72:a5:72:e8:98:66:a5:d8:ed:
    09:8a:2b:6d:86:e9:62:f7:94:74:c3:e5:13:aa:5d:
    6f:0a:30:4c:e2:25:fb:9e:22:64:d2:ad:e9:78:03:
    0c:6c:97:28:7e:1b:86:b9:2d:3c:95:5f:55:46:50:
    94:59:31:62:b4:00:9e:9b:65:15:e2:c3:b7:9b:56:
    ef:76:90:cd:93:f3:ee:23:43:63:d7:53:87:5b:5e:
    c0:a3:ae:cb:07:dd:9c:29:48:a3:d6:b1:2c:1d:94:
    a8:1e:75:ac:7c:2b:2a:76:18:8f:94:2f:1c:4d:7a:
    d4:2b:4c:36:65:7b:06:da:99:1c:21:c6:7c:5b:7f:
    48:14:a1:c6:6d:64:f1:60:3a:37:6a:8a:d1:65:83:
    95:80:6e:b2:7c:60:f9:35:90:78:2e:fe:e9:78:81:
    e6:93
publicExponent: 65537 (0x10001)
privateExponent:
    00:9b:d2:77:43:01:eb:a3:44:09:8c:5f:89:54:86:
    43:03:37:25:bd:2b:d5:79:56:21:02:da:b4:f1:23:
    6e:42:f2:0e:d3:c9:10:58:76:af:f3:cf:c3:54:0d:
    cc:e2:65:41:8a:0c:8a:65:db:86:bf:3a:10:1c:54:
    4d:4d:3a:88:48:bc:18:82:06:d7:8c:57:1d:6d:c7:
    33:45:54:5d:1d:04:4f:fb:fd:b8:52:bf:87:e6:ab:
    7a:9c:30:e8:a2:53:61:b3:97:b9:77:3f:7e:a8:1a:
    4c:cb:c8:ad:00:b4:ad:6d:43:5b:45:8a:16:eb:eb:
    34:0c:1d:d9:5f:72:3e:98:20:2e:d7:59:fa:ef:77:
    76:59:7b:99:85:e4:4f:aa:2d:4d:15:24:6c:1b:ae:
    56:e8:55:d2:1b:02:3e:6c:fc:23:38:69:ae:9c:a1:
    58:18:7d:99:a8:de:2c:f1:01:a9:11:a6:f1:78:ba:
    09:81:61:1a:d2:b5:9f:6a:de:63:85:44:42:ae:87:
    21:13:2a:3e:08:23:51:fa:5c:74:8f:00:d9:61:cc:
    0d:95:41:f2:62:f1:44:83:46:60:28:e9:62:38:e5:
    cd:95:a8:f0:5a:40:f8:05:f8:cf:fa:3d:12:c6:97:
    1b:84:a3:ea:98:5a:25:2c:a6:79:f3:67:3a:5e:22:
    9e:99
prime1:
    00:ea:c8:e9:96:0d:b3:13:d4:5a:a3:3b:34:14:68:
    ec:c3:82:c9:67:54:bd:01:44:5e:27:79:c5:58:6f:
    21:08:f7:f2:c9:f8:51:07:0b:e6:5b:34:ef:66:0d:
    e3:92:fc:f3:e7:b2:1b:ee:0b:1b:9f:cd:cb:11:db:
    39:c1:64:1e:fd:73:e6:08:77:c7:31:e3:e1:e7:44:
    16:af:bf:8c:2f:29:0c:05:3a:d4:56:a0:ce:d1:79:
    9f:12:43:8a:e9:07:1f:af:ba:15:a3:ee:1a:b9:35:
    da:f6:d8:39:94:d7:a8:ac:3a:65:bd:1a:6a:27:cc:
    33:4e:5b:07:39:42:79:8b:ef
prime2:
    00:d2:f0:9b:8d:9e:74:46:d3:3a:67:f3:cd:41:6d:
    25:7a:76:59:ce:89:61:02:49:3b:68:f7:32:94:d5:
    66:86:9c:c7:c9:58:5b:8d:f6:14:bc:87:ba:09:5d:
    87:9c:a7:87:89:32:f5:d8:ef:f6:8f:e2:01:43:dc:
    66:e9:fe:cc:f0:f4:df:59:ac:74:bb:99:1e:5d:d3:
    93:be:4d:74:5a:5e:55:fd:9e:ee:d1:ac:f5:9d:ab:
    24:b5:71:88:c3:29:1d:39:95:79:2a:e7:d7:b3:dc:
    99:3c:38:9c:d1:97:5b:30:86:ba:44:38:fc:50:a3:
    98:80:4b:23:48:7f:b9:3b:9d
exponent1:
    00:98:94:cf:71:2c:20:08:30:06:63:74:93:48:fc:
    53:7a:4f:e1:d1:dc:79:24:7c:a8:ef:e0:ac:46:e7:
    99:c1:79:59:f8:b5:fe:fa:a4:5a:25:46:06:9a:fd:
    45:bb:7d:d6:88:e9:f0:4a:c8:3f:40:a0:7e:6b:71:
    5c:5c:79:53:c6:85:6e:a6:6c:29:31:1c:16:f0:b4:
    08:46:59:26:a2:73:7b:93:5e:83:26:75:45:53:4f:
    45:f8:99:9a:8a:0c:8e:24:26:bb:ef:98:4b:17:b8:
    8f:3f:c2:8f:d1:52:42:15:03:b2:a0:ad:ac:f5:86:
    38:85:a0:94:d6:3a:84:41:53
exponent2:
    4c:22:37:a2:a7:bc:44:0b:dd:1a:c3:ee:23:5d:27:
    97:c9:bb:a4:46:05:53:73:e7:13:7d:95:2e:0e:cf:
    d0:6a:29:d9:cc:20:4f:5e:b0:21:53:c3:9b:b9:bc:
    46:98:58:dc:f6:1d:b1:cc:fa:6a:f8:21:88:c2:b6:
    0a:62:c2:c9:7d:38:57:ff:5c:aa:91:1b:5a:b6:10:
    af:30:f9:7b:dc:6c:a0:fb:8a:2a:f7:88:36:fe:1c:
    63:b8:b4:a9:eb:de:f6:77:b2:a1:ff:c7:e4:cd:0c:
    29:a6:2d:43:a0:a3:73:22:4d:7c:6e:2c:f3:55:f8:
    a6:e5:77:b8:a5:10:d0:29
coefficient:
    00:b1:28:d5:74:3d:9d:e4:03:e7:c2:14:f8:23:3b:
    d3:14:96:ed:97:5e:c6:2d:6c:da:a7:c5:13:5f:46:
    4d:89:b0:36:63:e6:40:e8:78:91:a7:89:e1:0b:d1:
    e5:01:86:9f:c2:70:11:cd:d0:90:06:88:e7:58:ed:
    4f:82:40:bb:26:56:f6:a6:98:5c:c0:7a:06:29:a0:
    fe:a6:f7:b4:7d:ba:09:be:5d:05:8d:f9:d0:ec:30:
    5a:d7:0f:35:5a:37:03:79:a3:5a:fe:10:39:db:e2:
    98:4f:39:77:40:65:8c:57:b0:af:ac:aa:2a:3d:9d:
    72:67:a6:b4:c7:6c:b8:8f:44
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEAwXV6oZtS5EDfjYOYN5hA4GBC1ILHkekNkb779Z+dVIvGvnJE
zhFfohvcsYXrMiG+Zl4OjQw1pprdzouDhp8WJRoVLxoOJbvU8G5Ec3CizPvC6jf5
/RlkJtVOBl7BzJVypXLomGal2O0Jiitthuli95R0w+UTql1vCjBM4iX7niJk0q3p
eAMMbJcofhuGuS08lV9VRlCUWTFitACem2UV4sO3m1bvdpDNk/PuI0Nj11OHW17A
o67LB92cKUij1rEsHZSoHnWsfCsqdhiPlC8cTXrUK0w2ZXsG2pkcIcZ8W39IFKHG
bWTxYDo3aorRZYOVgG6yfGD5NZB4Lv7peIHmkwIDAQABAoIBAQCb0ndDAeujRAmM
X4lUhkMDNyW9K9V5ViEC2rTxI25C8g7TyRBYdq/zz8NUDcziZUGKDIpl24a/OhAc
VE1NOohIvBiCBteMVx1txzNFVF0dBE/7/bhSv4fmq3qcMOiiU2Gzl7l3P36oGkzL
yK0AtK1tQ1tFihbr6zQMHdlfcj6YIC7XWfrvd3ZZe5mF5E+qLU0VJGwbrlboVdIb
Aj5s/CM4aa6coVgYfZmo3izxAakRpvF4ugmBYRrStZ9q3mOFREKuhyETKj4II1H6
XHSPANlhzA2VQfJi8USDRmAo6WI45c2VqPBaQPgF+M/6PRLGlxuEo+qYWiUspnnz
ZzpeIp6ZAoGBAOrI6ZYNsxPUWqM7NBRo7MOCyWdUvQFEXid5xVhvIQj38sn4UQcL
5ls072YN45L88+eyG+4LG5/NyxHbOcFkHv1z5gh3xzHj4edEFq+/jC8pDAU61Fag
ztF5nxJDiukHH6+6FaPuGrk12vbYOZTXqKw6Zb0aaifMM05bBzlCeYvvAoGBANLw
m42edEbTOmfzzUFtJXp2Wc6JYQJJO2j3MpTVZoacx8lYW432FLyHugldh5ynh4ky
9djv9o/iAUPcZun+zPD031msdLuZHl3Tk75NdFpeVf2e7tGs9Z2rJLVxiMMpHTmV
eSrn17PcmTw4nNGXWzCGukQ4/FCjmIBLI0h/uTudAoGBAJiUz3EsIAgwBmN0k0j8
U3pP4dHceSR8qO/grEbnmcF5Wfi1/vqkWiVGBpr9Rbt91ojp8ErIP0CgfmtxXFx5
U8aFbqZsKTEcFvC0CEZZJqJze5NegyZ1RVNPRfiZmooMjiQmu++YSxe4jz/Cj9FS
QhUDsqCtrPWGOIWglNY6hEFTAoGATCI3oqe8RAvdGsPuI10nl8m7pEYFU3PnE32V
Lg7P0Gop2cwgT16wIVPDm7m8RphY3PYdscz6avghiMK2CmLCyX04V/9cqpEbWrYQ
rzD5e9xsoPuKKveINv4cY7i0qeve9neyof/H5M0MKaYtQ6CjcyJNfG4s81X4puV3
uKUQ0CkCgYEAsSjVdD2d5APnwhT4IzvTFJbtl17GLWzap8UTX0ZNibA2Y+ZA6HiR
p4nhC9HlAYafwnARzdCQBojnWO1PgkC7Jlb2pphcwHoGKaD+pve0fboJvl0FjfnQ
7DBa1w81WjcDeaNa/hA52+KYTzl3QGWMV7CvrKoqPZ1yZ6a0x2y4j0Q=
-----END RSA PRIVATE KEY-----

# If you need to generate the corresponding public key, you can do that with the following rsa command:
$ openssl rsa -in fd.key -pubout -out fd-public.key
Enter pass phrase for fd.key: ****************

# View the public key we just generated
cat fd-public.key 
-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwXV6oZtS5EDfjYOYN5hA
4GBC1ILHkekNkb779Z+dVIvGvnJEzhFfohvcsYXrMiG+Zl4OjQw1pprdzouDhp8W
JRoVLxoOJbvU8G5Ec3CizPvC6jf5/RlkJtVOBl7BzJVypXLomGal2O0Jiitthuli
95R0w+UTql1vCjBM4iX7niJk0q3peAMMbJcofhuGuS08lV9VRlCUWTFitACem2UV
4sO3m1bvdpDNk/PuI0Nj11OHW17Ao67LB92cKUij1rEsHZSoHnWsfCsqdhiPlC8c
TXrUK0w2ZXsG2pkcIcZ8W39IFKHGbWTxYDo3aorRZYOVgG6yfGD5NZB4Lv7peIHm
kwIDAQAB
-----END PUBLIC KEY-----
```


```bash
# ECDSA key generation is a two-step process: ECDSA parameters are created in the first step and the key in the second.
openssl ecparam -genkey -name secp256r1 | openssl ec -out ec.key -aes128
using curve name prime256v1 instead of secp256r1
read EC key
writing EC key
Enter PEM pass phrase:
Verifying - Enter PEM pass phrase:

# Let us look at the one file that was generated
cat ec.key
-----BEGIN EC PRIVATE KEY-----
Proc-Type: 4,ENCRYPTED
DEK-Info: AES-128-CBC,9FCFC15384DC74884A6710E472262199

FmSh7hBg/Vuz+M9LsSBo/Jgl0DIkZLfSxUw6I3UWC+VnIFs0E5auA51CENL9QDIg
hiKm3WWBl8L02ZRYScS2rfBfOYGiokBCaKxmQ06R+uccZM1MOYCuq1xqrauDgTLc
GswcFi1WCldETcnkA56aqXhOb8Bm41higRVuKLY+FH0=
-----END EC PRIVATE KEY-----

```

For web server keys, you're limited to only two curves that are supported by all major browsers: secp256r1 (OpenSSL uses the name prime256v1 ) and secp384r1 (as of January 2017)


# Create a Certificate Signing Request (CSR)


```bash
openssl req -new -key fd.key -out fd.csr

# check your CSR
openssl req -text -in fd.csr -noout
```


```
[req]
prompt = no
distinguished_name = dn
req_extensions = ext

[dn]
CN = www.feistyduck.com
emailAddress = webmaster@feistyduck.com
O = Feisty Duck Ltd
L = London
C = GB

[ext]
subjectAltName = DNS:www.feistyduck.com,DNS:feistyduck.com
```



# public-key infrastructure

The goal of PKI is to enable secure communication among parties who have never met before.


The model we use today relies on trusted third parties called certification authorities (CAs) to issue certificates that we unreservedly trust.

A public certificate comprises of at least three pieces of information

* Public Key
* Naming Information - identify the owner of the public key
* Digital signatures - Attest to the fact that the other two pieces of information belong together



# Client Certificates

From a theoretical perspective, there is no major difference between a server certificate and a client certificate

