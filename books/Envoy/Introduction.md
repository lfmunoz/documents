---
title: Envoy
mathjax: true
layout: default
toc: true
---


# Envoy 

**Envoy** is an open source edge and service proxy, designed for cloud-native applications.

It is an application written in C++ that runs as a service and has many networking features generally centered around proxying network connections.  You write a config file (generally YAML or JSON) which often can be complicated and you feed that to envoy instructing it what to do. It gives you the ability to:

  * Make intelligent routing decisions based on source destination port, address, protocol, SNI (rate limiting,  load balance, block)
  * Gather statistics  (measure API usage)
  * Secure connections (enable mutual TSL, terminate TSL)
  * Service discovery by having envoy read its configuration dynamically and/or remotely (reload without dropping connections)


* Homepage
  * https://www.envoyproxy.io/
  * https://github.com/envoyproxy/envoy


* Alternatives
  * Linkerd, NGINX, HAProxy, Traefik,
  * F5 and Cisco (hardware)


* Important Terms
  * **Downstream:** A downstream host **connects to Envoy**, sends requests, and receives responses.
  * **Upstream:** An upstream host **receives connections and requests from Envoy** and returns responses.
  * **Listener:** A listener is a named network location (e.g., port, unix domain socket, etc.) that can be connected to by downstream clients. Envoy exposes one or more listeners that downstream hosts connect to.
  * **Cluster:** A cluster is a group of logically similar upstream hosts that Envoy connects to. 
  * A **Service mesh** - consists of two major components:
    * **Control plane** - manages and configures the data plane to route traffic.
    * **Data plane** - Composed of a set of intelligent proxies (Envoy). The proxies mediate and control all network communication between microservices. 



## Install


<details>
<summary> <strong> cat src/install_envoy.bash </strong> </summary>
<p markdown="block">
```bash
{% include_relative src/install_envoy.bash  %}
````
</p></details><br>


## Skeleton

This example will proxy 0.0.0.0:80 to www.lfmunoz.com:80

```bash
# run envoy with the following command
envoy -c src/proxy_http.yaml

```

<details>
<summary> <strong> cat src/proxy_http.yaml </strong> </summary>
<p markdown="block">
```yaml
{% include_relative src/proxy_http.yaml %}
````
</p></details><br>


## Command line

```bash
# Run and specify the config file
envoy -c <path to config>.{json,yaml,pb,pb_text}

# Validating your Envoy configuration 
envoy --mode validate -c my-envoy-config.yaml

# Envoy system logs are sent to /dev/stderr. 
# Override with --log-path
envoy -c envoy-demo.yaml --log-path logs/custom.log

# Debugging Envoy, use -l or --log-level
# levels: trace debug info warning/warn error critical off
envoy -c envoy-demo.yaml --log-level debug
```



# API


There are 4 basic building blocks in Envoy: 
* Listeners (LDS) - tells the Envoy to bind to a port
* Filters(LDS) - tells the listeners what to do with the requests they receive.  (similar to netty)
* Routes(RDS) - information on how to proxy the requests
* Clusters (CDS) - a list of endpoints which are the backends for a service


xDS gives us the capability to dynamically configure Envoy. However, each discovery service is independent of each other and eventually consistent.

 Aggregated Discovery Service (ADS) publishes all configuration updates through a gRPC stream to ensure the calling sequence of each discovery service and avoid the inconsistency of configuration data caused by the update sequence of discovery service.

Using proto3 and implemented as both gRPC and REST+JSON/YAML endpoints.
* https://github.com/envoyproxy/data-plane-api

The v2 APIs are composed of:

* Endpoint Discovery Service (EDS): EDS allows an Envoy deployment to circumvent the limitations of DNS
* Cluster Discovery Service (CDS):  dynamically add/update/remove all upstream clusters (each cluster itself has its own service/endpoint discovery).
* Route Discovery Service (RDS):  dynamically add/update HTTP route tables.
* Listener Discovery Service (LDS):  dynamically add/update/remove entire listeners, including their full L4 and L7 filter stacks.
* Health Discovery Service (HDS):  This API will allow an Envoy to become a member of a distributed health checking network.
* Aggregated Discovery Service (ADS):
* Secret Discovery Service (SDS)

In aggregate, we call all of the above APIs xDS  (LDS/EDS/RDS/CDS/SDS, together “xDS”)


# Static Configuration

You will need to specify 
* listeners 
* clusters 
* static_resources.


By configuring a Listener, users can enable the flow of traffic through the proxy, and then perform operations on the data using Filters. 


This example will proxy HTTP 0.0.0.0:80 to HTTP www.lfmunoz.com:80

<details>
<summary> <strong> cat src/proxy_http.yaml </strong> </summary>
<p markdown="block">
```yaml
{% include_relative src/proxy_http.yaml %}
````
</p></details>

This example will proxy TCP 0.0.0.0:80 to TCP www.lfmunoz.com:2010

<details>
<summary> <strong> cat src/proxy_tcp.yaml </strong> </summary>
<p markdown="block">
```yaml
{% include_relative src/proxy_tcp.yaml %}
````
</p></details>

This example will proxy https

<details>
<summary> <strong> cat src/proxy_https.yaml </strong> </summary>
<p markdown="block">
```yaml
{% include_relative src/proxy_https.yaml %}
````
</p></details>




# Dynamic Configuration

https://www.envoyproxy.io/docs/envoy/latest/configuration/overview/examples

```yaml
admin:
  access_log_path: /tmp/admin_access.log
  address:
    socket_address: { address: 127.0.0.1, port_value: 9901 }

dynamic_resources:
  lds_config:
    resource_api_version: V3
    api_config_source:
      api_type: GRPC
      transport_api_version: V3
      grpc_services:
        - envoy_grpc:
            cluster_name: xds_cluster
  cds_config:
    resource_api_version: V3
    api_config_source:
      api_type: GRPC
      transport_api_version: V3
      grpc_services:
        - envoy_grpc:
            cluster_name: xds_cluster

static_resources:
  clusters:
  - name: xds_cluster
    connect_timeout: 0.25s
    type: STATIC
    lb_policy: ROUND_ROBIN
    typed_extension_protocol_options:
      envoy.extensions.upstreams.http.v3.HttpProtocolOptions:
        "@type": type.googleapis.com/envoy.extensions.upstreams.http.v3.HttpProtocolOptions
        explicit_http_config:
          http2_protocol_options:
            # Configure an HTTP/2 keep-alive to detect connection issues and reconnect
            # to the admin server if the connection is no longer responsive.
            connection_keepalive:
              interval: 30s
              timeout: 5s
    load_assignment:
      cluster_name: xds_cluster
      endpoints:
      - lb_endpoints:
        - endpoint:
            address:
              socket_address:
                address: 127.0.0.1
                port_value: 5678
```




# Control plane


There are a number of control planes compatible with Envoy’s API such as Gloo or Istio.
* https://istio.io/
* https://github.com/heptio/contour
* https://gloo.solo.io/
* https://github.com/uswitch/yggdrasil/blob/master/pkg/envoy/boilerplate.go

* Create your own using this official reference implementation
    * https://github.com/envoyproxy/go-control-plane
    * https://github.com/envoyproxy/java-control-plane



Envoy’s configuration via its xDS APIs is eventually consistent by design meaning there is no way to affect an “atomic update” to all of the proxies in the cluster.





“Simple” control planes typically use the State-of-The-World (SoTW) xDS API which means that the control plane sends a complete snapshot of a resource set whenever any resource in that set changes.




# References




https://github.com/salrashid123/envoy_control

https://mattklein123.dev/2020/03/15/on-the-state-of-envoy-proxy-control-planes/


https://blog.gojekengineering.com/demystifying-the-packet-flow-in-istio-part-1-1cad8e9b3a2c