---
title: Envoy
mathjax: true
layout: default
toc: true
---




# Envoy 


* Homepage
  * https://www.envoyproxy.io/


* Alternatives
  * Linkerd, NGINX, HAProxy, Traefik,
  * F5 and Cisco (hardware)


* Important Terms
  * **downstream:** A downstream host **connects to Envoy**, sends requests, and receives responses.
  * **upstream:** An upstream host **receives connections and requests from Envoy** and returns responses.
  * **listener:** A listener is a named network location (e.g., port, unix domain socket, etc.) that can be connected to by downstream clients. Envoy exposes one or more listeners that downstream hosts connect to.


<details>
<summary> <strong> cat src/install_envoy.bash </strong> </summary>

<p markdown="block">
```bash
{% include_relative src/install_envoy.bash  %}
````
</p></details>  



<details>
<summary> <strong> cat src/proxy_http.yaml </strong> </summary>

<p markdown="block">
```yaml
{% include_relative src/proxy_http.yaml %}
````
</p></details>





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


# Static Configuration

You will need to specify listeners and clusters as static_resources.





# Dynamic Configuration

v2 api

using proto3 and implemented as both gRPC and REST+JSON/YAML endpoints.

https://github.com/envoyproxy/data-plane-api


The v2 APIs are composed of:

* Endpoint Discovery Service (EDS):
* Cluster Discovery Service (CDS):  dynamically add/update/remove all upstream clusters (each cluster itself has its own service/endpoint discovery).
* Route Discovery Service (RDS):  dynamically add/update HTTP route tables.
* Listener Discovery Service (LDS):  dynamically add/update/remove entire listeners, including their full L4 and L7 filter stacks.
* Health Discovery Service (HDS):  This API will allow an Envoy to become a member of a distributed health checking network.
* Aggregated Discovery Service (ADS):
* Secret Discovery Service (SDS)

In aggregate, we call all of the above APIs xDS  (LDS/EDS/RDS/CDS/SDS, together “xDS”)





# Control plane


There are a number of control planes compatible with Envoy’s API such as Gloo or Istio.
* https://istio.io/
* https://github.com/heptio/contour
* https://gloo.solo.io/

* Create your own using this reference implementation
    * https://github.com/envoyproxy/go-control-plane




 Envoy’s configuration via its xDS APIs is eventually consistent by design meaning there is no way to affect an “atomic update” to all of the proxies in the cluster.




“Simple” control planes typically use the State-of-The-World (SoTW) xDS API which means that the control plane sends a complete snapshot of a resource set whenever any resource in that set changes.




# References


https://github.com/salrashid123/envoy_control

https://mattklein123.dev/2020/03/15/on-the-state-of-envoy-proxy-control-planes/