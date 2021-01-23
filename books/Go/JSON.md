---
title: JSON
mathjax: true
layout: default
toc: true
---


# JSON

* [The Go Programming Language](Introduction.html)



```go


type Feed struct {
   URI string `json:"link"`
   Type string `json:"type"`
}

var feeds []*Feed
err = json.NewDecoder(file).Decode(&feeds)

u := struct {
    Name string
    Email string
}{
    Name: "Bill",
    Email: "bill@ardanstudios.com",
}

json.NewEncoder(rw).Encode(&u)
```


```go

// The encoding/json package and similar packages ignore unexported fields (lower case fields)
m := Message{"Alice", "Hello", 1294706395881547000}

b, err := json.Marshal(m)
```

```go
// We must first create a place where the decoded data will be stored
var m Message

// call json.Unmarshal, passing it a []byte of JSON data and a pointer to m
err := json.Unmarshal(b, &m)
```


## References

https://blog.golang.org/json