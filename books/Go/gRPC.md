---
title: gRPC
mathjax: true
layout: default
toc: true
---


# gRPC


* Official Documentation
    * https://developers.google.com/protocol-buffers/docs/gotutorial

* gRPC uses HTTP/2
* gRPC uses the protocol buffer data format 



<details>
<summary> cat src/api/chat.proto </summary>

<p markdown="block">
```go
{% include_relative src/api/chat.proto  %}
````
</p></details> <br>


<details>
<summary> cat src/chat/chat.go </summary>

<p markdown="block">
```go
{% include_relative src/chat/chat.go %}
````
</p></details> <br>





```go

	hst0 := &core.Address{Address: &core.Address_SocketAddress{
		SocketAddress: &core.SocketAddress{
			Address:  "localhost",
			Protocol: core.SocketAddress_TCP,
			PortSpecifier: &core.SocketAddress_PortValue{
				PortValue: uint32(443),
			},
		},
	}}
	fmt.Println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
	fmt.Println(hst0.String())
	m := jsonpb.Marshaler{}
	result, _ := m.MarshalToString(hst0)
    fmt.Println(result)
    


	// Protocol Buffer to JSON
	x := chat.Message{Body: "Hello From the Server!"}
	m := jsonpb.Marshaler{}
	result, _ := m.MarshalToString(&x)
	fmt.Println(result)


```



https://pkg.go.dev/github.com/golang/protobuf/proto#Message



```go

	// fmt.Println(l)
	m := jsonpb.Marshaler{}

	for _, s := range l {
		// fmt.Println(i, s)
		result, _ := m.MarshalToString(s)
		fmt.Println(result)
	}


```