---
title: Security
mathjax: true
layout: default
toc: true
---


# Security




# Certificates


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
# check the version for following along
openssl version
OpenSSL 1.0.2p  14 Aug 201

#To generate an RSA key, use the genrsa command:
# -aes128, -aes192, and -aes256 are used to password protect the key
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
# Create a certificate signing request
# use -subj or -config file to not get prompted
# -subj "/C=US/ST=Texas/L=Austin/O=LFM/OU=Engineering Depeartment/CN=jenkins"
openssl req -new -key fd.key -out fd.csr
You are about to be asked to enter information that will be incorporated
into your certificate request.
What you are about to enter is what is called a Distinguished Name or a DN.
There are quite a few fields but you can leave some blank
For some fields there will be a default value,
If you enter '.', the field will be left blank.
-----
Country Name (2 letter code) [AU]:US
State or Province Name (full name) [Some-State]:CA
Locality Name (eg, city) []:Austin
Organization Name (eg, company) [Internet Widgits Pty Ltd]:
Organizational Unit Name (eg, section) []:
Common Name (e.g. server FQDN or YOUR name) []:
Email Address []:

Please enter the following 'extra' attributes
to be sent with your certificate request
A challenge password []:
An optional company name []:

# check your CSR
openssl req -text -in fd.csr -noout
Certificate Request:
    Data:
        Version: 0 (0x0)
        Subject: C=US, ST=CA, L=Austin, O=Internet Widgits Pty Ltd
        Subject Public Key Info:
            Public Key Algorithm: rsaEncryption
                Public-Key: (2048 bit)
                Modulus:
                    00:b8:48:a1:91:1f:39:83:e8:b5:96:3c:9d:92:fb:
                    7e:c7:10:9c:60:fe:81:c0:14:3b:1e:cc:bc:01:e2:
                    f5:ce:6a:5e:9f:c8:57:32:fb:40:45:de:43:5a:ee:
                    2e:e8:12:02:25:15:4a:43:3d:c1:a7:79:d7:2f:6f:
                    93:23:35:a1:ef:b0:71:e0:53:07:00:8a:9a:19:9f:
                    be:90:77:f8:00:c8:5b:cb:83:84:01:9a:f3:23:fa:
                    d0:d2:bc:25:24:99:89:50:7b:5b:f5:96:99:41:54:
                    a0:37:0c:3b:ba:57:c6:6b:9a:3e:0c:37:ce:89:30:
                    c0:33:fd:d8:56:0e:98:cb:1e:e9:e2:2b:d1:65:72:
                    80:14:3b:43:20:a7:cc:57:9f:3c:d6:bd:9a:9f:02:
                    04:72:86:99:ba:43:5c:7f:2d:4f:5e:07:a4:b5:e8:
                    38:16:a6:21:4f:e6:72:5a:71:96:5e:88:ab:69:fa:
                    67:aa:f4:36:2a:5a:1b:b6:a8:f0:23:22:80:cf:08:
                    65:d1:3e:23:71:af:a7:d1:38:0f:b4:08:c2:da:f0:
                    31:f8:49:31:0f:95:31:ba:bb:aa:a3:56:6c:89:f4:
                    6c:94:c3:be:c6:62:a1:de:a2:a7:fb:ac:aa:0b:39:
                    d9:86:df:eb:6e:83:e1:80:13:62:9e:e6:e1:9d:fe:
                    64:ef
                Exponent: 65537 (0x10001)
        Attributes:
            a0:00
    Signature Algorithm: sha256WithRSAEncryption
         5a:18:93:fc:20:09:2c:7c:42:a3:b9:81:62:a6:5b:be:89:f5:
         24:b9:11:e6:72:a4:58:4c:1d:f5:40:ae:11:c5:cc:f3:35:c4:
         99:91:3c:84:62:38:82:2a:0d:26:21:67:a8:01:39:f7:ea:3b:
         f5:0b:fb:73:80:ee:fb:81:16:f7:01:c7:24:bb:14:96:05:b4:
         b3:c8:7d:93:bb:a3:38:c4:68:02:7b:d3:22:e9:ec:d9:5f:f2:
         be:d0:5e:0a:4f:5f:b9:3c:77:4b:59:b8:da:4e:39:d7:3b:cd:
         ef:05:72:10:4d:ed:59:d8:e1:55:71:58:83:c0:46:47:ab:17:
         dd:7a:ea:06:48:96:4d:df:38:fc:e1:08:a7:ed:4c:fd:15:fb:
         ea:f9:34:db:8a:34:f4:06:3e:1c:08:01:2f:f6:f0:f7:09:87:
         e6:b8:c0:8f:b0:da:7e:ea:b4:38:d4:7a:1a:be:c7:ca:ee:91:
         b2:cf:84:da:dd:e7:b6:d3:0c:20:4b:3e:73:b1:2f:60:a8:26:
         73:41:2d:99:c2:bc:45:b5:ea:7b:fd:d9:42:19:30:2f:d8:f3:
         75:fc:7f:0c:32:49:4c:1a:d4:2e:50:15:f2:a8:33:36:b0:5e:
         ff:b3:f6:0c:27:a1:09:f5:8a:dd:8f:6b:37:d6:f6:d6:a3:d6:
         0e:81:ac:6e

```


Required fields for the CSR (used with -subj)
* /C=	Country	 GB
* /ST=	State	London
* /L=	Location	London
* /O=	Organization	Global Security
* /OU=	Organizational Unit	IT Department
* /CN=	Common Name	example.com


You can also use -config file (instead of -subj)
```ini
# config.cnf
[req]
prompt = no
distinguished_name = dn
req_extensions = ext

[dn]
C=
ST=
L=
O=
OU=
CN=

emailAddress = webmaster@feistyduck.com

[ext]
subjectAltName = DNS:www.feistyduck.com,DNS:feistyduck.com

# or 

[ ext ]
subjectAltName = @alt_names

[alt_names]
DNS.1 = hostname.domain.tld
DNS.2 = hostname
IP.1 = 10.20.30.40

```

# Singing your own certificates

If you’re installing a TLS server for your own use, you probably don’t want to go to a CA to get a publicly trusted certificate.

It's much better to use a private CA in a development environment than to use self-signed certificates everywhere.

```bash
# Create a x509 certificate if you have a CSR
openssl x509 -req -days 365 -in fd.csr -signkey fd.key -out fd.crt


# creates a self-signed certificate starting with a key alone
#  In other words, don't create a CSR just straight create the self-signed cert
openssl req -new -x509 -days 365 -key fd.key -out fd.crt

# create a self-signed certificate with key alone and don't prompt
openssl req -new -x509 -days 365 -key fd.key -out fd.crt \
-subj "/C=GB/L=London/O=Feisty Duck Ltd/CN=www.feistyduck.com"


# Examine the certificate
#  -text - print certificate contents
#  -noout - reduce clutter by not printing the encoded certificate itself
openssl x509 -text -in fd.crt -noout
Certificate:
    Data:
        Version: 1 (0x0)
        Serial Number:
            fe:d8:fb:bc:c5:16:ff:f7
    Signature Algorithm: sha256WithRSAEncryption
        Issuer: C=US, ST=Texas, L=Austin, O=LFM, OU=Engineering Department, CN=jenkins
        Validity
            Not Before: Dec  8 20:07:02 2020 GMT
            Not After : Dec  8 20:07:02 2021 GMT
        Subject: C=US, ST=Texas, L=Austin, O=LFM, OU=Engineering Department, CN=jenkins
        Subject Public Key Info:
            Public Key Algorithm: rsaEncryption
                Public-Key: (2048 bit)
                Modulus:
                    00:e8:30:dd:4e:56:23:d5:44:18:88:de:57:05:fd:
                    a9:57:1f:2c:46:48:c4:51:b4:ab:cb:f1:01:bb:2d:
                    80:a7:06:9a:f9:ed:bc:03:b5:a1:87:fe:6a:57:dc:
                    b3:e1:30:b9:4d:fb:96:e3:22:fe:38:05:63:33:de:
                    db:a2:56:e3:f8:37:a5:68:26:90:7b:9b:8b:b4:87:
                    11:fa:22:24:4a:d8:f2:3f:25:38:8c:cf:53:f6:28:
                    f0:07:c9:52:fb:51:12:1a:1f:9f:d3:39:bb:17:6f:
                    de:d1:d5:41:2b:f3:4f:5f:40:a7:3e:71:1f:bd:c2:
                    45:be:fb:67:91:fb:a8:dc:32:e0:fb:d9:2c:89:3d:
                    42:33:69:96:e0:61:75:d8:b3:36:05:d9:6a:12:33:
                    c5:9e:a8:73:d1:0d:eb:1a:02:06:b5:2f:dc:56:4d:
                    90:4a:cf:56:d4:68:5d:df:9b:40:f1:78:45:97:ca:
                    f5:e1:eb:26:f5:57:5b:5b:36:c0:05:0a:39:6c:eb:
                    f9:1d:cd:b1:dc:0f:55:12:3c:fa:36:e6:a5:af:67:
                    a3:41:61:84:d1:65:79:cb:77:b2:fd:ca:ef:c2:b5:
                    99:22:1e:4e:9f:2d:dd:1f:c9:4b:92:18:89:8a:f1:
                    9a:34:c7:16:82:ee:8f:0a:ce:67:cf:23:21:09:5a:
                    1b:0d
                Exponent: 65537 (0x10001)
    Signature Algorithm: sha256WithRSAEncryption
         52:b7:b2:a7:bd:bf:bd:69:6a:9c:88:db:75:9c:fa:13:15:f3:
         48:7d:74:a8:e5:8e:73:ce:52:af:f5:23:a4:fd:89:65:c5:82:
         a7:3b:5e:69:56:71:8e:77:60:f0:b1:7d:45:c0:3c:44:9e:d3:
         e1:46:9e:09:fa:cd:a8:c5:53:be:eb:72:dc:14:33:19:03:29:
         27:2e:aa:70:89:11:f2:dd:2b:48:e8:42:24:45:97:4d:18:a0:
         37:6f:e5:08:e6:a2:2d:53:9e:17:16:f4:ab:b6:e1:ae:19:b9:
         5b:a6:47:0b:16:f0:06:a9:0f:03:c2:19:36:de:89:12:38:cb:
         e0:06:77:d8:bb:25:1c:7f:8f:23:c4:84:c9:34:8c:1e:13:14:
         e7:d6:fa:bb:b0:8f:52:c6:d6:23:40:15:f0:de:0b:1f:03:59:
         0c:58:ce:82:4b:65:19:3b:71:c2:09:86:1c:1c:19:e9:77:b8:
         b0:11:35:2c:bf:62:cd:b4:84:55:00:0a:75:ad:8e:f9:5d:a3:
         9a:48:d7:41:01:76:25:17:59:45:9c:0a:9f:0c:41:b4:1a:53:
         00:b3:79:90:37:d4:a1:3e:63:ec:13:59:29:7e:aa:1f:7a:10:
         3e:e0:e8:90:64:ff:e3:91:c0:a3:9a:7a:cc:e8:fe:8b:7f:a5:
         10:1c:18:bd

```

Warning: When a certificate contains alternative names, all common names are ignored.

There are two mechanisms for supporting multiple hostnames in a certificate. The first is to list all desired hostnames using an X.509 extension called Subject Alternative Name (SAN). The second is to use wildcards.

```ini
# fd.ext
subjectAltName = DNS:*.feistyduck.com, DNS:feistyduck.com
```


# Performance

```bash
openssl speed -multi 4 rsa
Forked child 0
Forked child 1
Forked child 2
Forked child3
+DTP:512:private:rsa:10
+DTP:512:private:rsa:10
+DTP:512:private:rsa:10
+DTP:512:private:rsa:10
+R1:265814:512:10.00
+DTP:512:public:rsa:10
+R1:264622:512:10.00
+DTP:512:public:rsa:10
+R1:265482:512:10.00
+DTP:512:public:rsa:10
+R1:264064:512:10.00
+DTP:512:public:rsa:10
+R2:4978119:512:10.00
+R2:4965095:512:10.00
+R2:4949064:512:10.00
+R2:4961196:512:10.00
+DTP:1024:private:rsa:10
+DTP:1024:private:rsa:10
+DTP:1024:private:rsa:10
+DTP:1024:private:rsa:10
+R1:123240:1024:10.00
+DTP:1024:public:rsa:10
+R1:122939:1024:10.00
+DTP:1024:public:rsa:10
+R1:123341:1024:10.00
+DTP:1024:public:rsa:10
+R1:123040:1024:10.00
+DTP:1024:public:rsa:10
+R2:2080715:1024:10.00
+R2:2049657:1024:10.00
+R2:2082599:1024:10.00
+R2:2076420:1024:10.00
+DTP:2048:private:rsa:10
+DTP:2048:private:rsa:10
+DTP:2048:private:rsa:10
+DTP:2048:private:rsa:10
+R1:19037:2048:10.00
+DTP:2048:public:rsa:10
+R1:18884:2048:10.00
+R1:18860:2048:10.00
+DTP:2048:public:rsa:10
+DTP:2048:public:rsa:10
+R1:18954:2048:10.00
+DTP:2048:public:rsa:10
+R2:658241:2048:10.00
+R2:657726:2048:10.00
+R2:663370:2048:10.00
+R2:661916:2048:10.00
+DTP:4096:private:rsa:10
+DTP:4096:private:rsa:10
+DTP:4096:private:rsa:10
+DTP:4096:private:rsa:10
+R1:2843:4096:10.00
+DTP:4096:public:rsa:10
+R1:2715:4096:10.00
+DTP:4096:public:rsa:10
+R1:2717:4096:10.00
+DTP:4096:public:rsa:10
+R1:2829:4096:10.00
+DTP:4096:public:rsa:10
+R2:185001:4096:10.00
+R2:187334:4096:10.00
+R2:182507:4096:10.00
+R2:184055:4096:10.00
Got: +F2:0:512:0.000038:0.000002 from 0
Got: +F2:1:1024:0.000081:0.000005 from 0
Got: +F2:2:2048:0.000530:0.000015 from 0
Got: +F2:3:4096:0.003681:0.000055 from 0
Got: +F2:0:512:0.000038:0.000002 from 1
Got: +F2:1:1024:0.000081:0.000005 from 1
Got: +F2:2:2048:0.000530:0.000015 from 1
Got: +F2:3:4096:0.003517:0.000054 from 1
Got: +F2:0:512:0.000038:0.000002 from 2
Got: +F2:1:1024:0.000081:0.000005 from 2
Got: +F2:2:2048:0.000525:0.000015 from 2
Got: +F2:3:4096:0.003683:0.000053 from 2
Got: +F2:0:512:0.000038:0.000002 from 3
Got: +F2:1:1024:0.000081:0.000005 from 3
Got: +F2:2:2048:0.000528:0.000015 from 3
Got: +F2:3:4096:0.003535:0.000054 from 3
OpenSSL 1.0.2p  14 Aug 2018
built on: reproducible build, date unspecified
options:bn(64,64) rc4(16x,int) des(idx,cisc,16,int) aes(partial) idea(int) blowfish(idx)
compiler: /home/conda/feedstock_root/build_artifacts/openssl_1546586955028/_build_env/bin/x86_64-conda_cos6-linux-gnu-cc -DNDEBUG -D_FORTIFY_SOURCE=2 -O2 -march=nocona -mtune=haswell -ftree-vectorize -fPIC -fstack-protector-strong -fno-plt -O2 -pipe -I/home/luis/anaconda3/include -fdebug-prefix-map=/home/conda/feedstock_root/build_artifacts/openssl_1546586955028/work=/usr/local/src/conda/openssl-1.0.2p -fdebug-prefix-map=/home/luis/anaconda3=/usr/local/src/conda-prefix -Wa,--noexecstack -I. -I.. -I../include  -fPIC -DOPENSSL_PIC -DOPENSSL_THREADS -D_REENTRANT -DDSO_DLFCN -DHAVE_DLFCN_H -m64 -DL_ENDIAN -O3 -Wall -DOPENSSL_IA32_SSE2 -DOPENSSL_BN_ASM_MONT -DOPENSSL_BN_ASM_MONT5 -DOPENSSL_BN_ASM_GF2m -DRC4_ASM -DSHA1_ASM -DSHA256_ASM -DSHA512_ASM -DMD5_ASM -DAES_ASM -DVPAES_ASM -DBSAES_ASM -DWHIRLPOOL_ASM -DGHASH_ASM -DECP_NISTZ256_ASM
                  sign    verify    sign/s verify/s
rsa  512 bits 0.000010s 0.000000s 105263.2 2000000.0
rsa 1024 bits 0.000020s 0.000001s  49382.7 800000.0
rsa 2048 bits 0.000132s 0.000004s   7572.3 266666.7
rsa 4096 bits 0.000901s 0.000013s   1110.4  74086.8

# Run (1)
              sign      verify      sign/s  verify/s
rsa 2048 bits 0.003606s 0.000102s   277.3   9762.6

# Run (2)
rsa 2048 bits 0.002209s 0.000068s   452.8   14693.6
# NOTE: The performance went from 277 signatures/s to 450 signatures/s.

# Run (3) with multi 4
rsa 2048 bits 0.000917s 0.000027s   1090.7  37068.1


# activate hardware acceleration, use the -evp switch 
openssl speed -evp aes-128-cbc
```

I’m looking at how many RSA signatures can be executed per second, because this is the most CPU-intensive operation performed on a server and is thus always the first bottleneck. The example number of 1,090 signatures/second tells us that this server can handle about 1,000 brand-new TLS connections per second. I wish I had enough traffic on that server to worry about the performance of TLS.


# Client Authentication (two-way TSL)

From a theoretical perspective, there is no major difference between a server certificate and a client certificate.

The major difference between a server certificate and a client certificate is the way they are issued: 
* server certificate - issued by an internationally operating trusted CA, 
* client certificate - issued by any locally operating CA that is trusted by the server(s).

TLS Client Authentication can be CPU intensive to implement - it’s an additional cryptographic operation on every request.

```bash

# This creates the private key “client-key1” in PEM format.
# create a client certificate
openssl req -newkey rsa:2048 -days 1000 -nodes -keyout client-key1.pem > client-req.pem

# create a client certificate that will be signed by the CA certificate created in Step 2.
openssl x509 -req -in client-req.pem -days 1000 -CA ca-cert.pem -CAkey ca-key.pem -set_serial 01 > client-cert1.pem
```

```bash
# create client private key
openssl genrsa -out client-private.key 2048
Generating RSA private key, 2048 bit long modulus
.............+++++
....................................................+++++
e is 65537 (0x10001)

# create client certificate signing request
openssl req -new -key client-private.key -out client.csr \
        -subj "/C=US/ST=Texas/L=Austin/O=LFM/OU=Engineering Department/CN=app"
openssl genrsa -out server-private.key 2048
Generating RSA private key, 2048 bit long modulus
.........................................................................+++++
.................................................................+++++
e is 65537 (0x10001)

# sign the client certificate with the server private key and server.crt as the CA
openssl x509 -req -in client.csr  -CA server.crt  -CAkey server-private.key \
        -set_serial 1001 -extensions client -days 365 -out client.crt
Signature ok
subject=/C=US/ST=Texas/L=Austin/O=LFM/OU=Engineering Department/CN=app
Getting CA Private Key


```




### References

https://www.makethenmakeinstall.com/2014/05/ssl-client-authentication-step-by-step/


```bash
curl --cacert ca.crt \
   --key client.key \
   --cert client.crt \
   https://cloud-controller-ng.service.cf.internal:9023/internal/v4/syslog_drain_urls
   
```


# Testing with OpenSSL

OpenSSL comes with a client tool that you can use to connect to a secure server.

```bash
openssl s_client -connect www.feistyduck.com:443

openssl s_client -connect www.feistyduck.com:443 -CAfile /etc/ssl/certs/ca-certificates.crt

```
The most important information here is the protocol version (TLS 1.1) and cipher suite used ( ECDHE-RSA-AES256-SHA ). 


When coupled with the -reconnect switch, the s_client command can be used to test session reuse.

```
echo | openssl s_client -connect www.feistyduck.com:443 -reconnect
echo | openssl s_client -connect www.feistyduck.com:443 -reconnect -no_ssl2 2> \
/dev/null | grep 'New\|Reuse'
```

You should see 1 new and the rest Reused

Reused, TLSv1/SSLv3, Cipher is RC4-SHA


# public-key infrastructure

The goal of PKI is to enable secure communication among parties who have never met before.


The model we use today relies on trusted third parties called certification authorities (CAs) to issue certificates that we unreservedly trust.

A public certificate comprises of at least three pieces of information

* Public Key
* Naming Information - identify the owner of the public key
* Digital signatures - Attest to the fact that the other two pieces of information belong together



# Client Certificates

From a theoretical perspective, there is no major difference between a server certificate and a client certificate

