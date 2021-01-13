---
title: Concurrency
mathjax: true
layout: default
toc: true
---


# Concurrency

* [The Go Programming Language](Introduction.html)


# Concurrency

A wait group is a synchronisation primitive that allows you to 'hang' your program until the counter goes down to 0. It is similar to CountDownLatch in JVM land. 

```go

 // parallel with mutex and waitgroup
    // create a wait group
    wg := &sync.WaitGroup{}
    // init a mutex
    mutex := & ync.Mutex{}
    startTime := time.Now()

     wg.Add(1)

      defer wg.Done()

       mutex.Lock()

        mutex.Unlock()

         wg.Wait()
    elapsedTime := time.Now().Sub(startTime)
    fmt.Println(elapsedTimeMt)


```


## Channel

**Channels** are the pipes that connect concurrent goroutines. You can send values into channels from one goroutine and receive those values into another goroutine.

```go
package main

import "fmt"

func main() {

    // By default channels are unbuffered
    messages := make(chan string)
    // To buffer we specify the buffering value
    messagesBuffering := make(chan string, 2)

    go func() { 
        // Send a value into a channel using the channel <- syntax
        messages <- "ping"
    }()
    
    // The <-channel syntax receives a value from the channel.
    msg := <- messages
    fmt.Println(msg)

}
```

By default sends and receives block until both the sender and receiver are ready. 

## Select

Go’s select lets you wait on multiple channel operations.


```go
package main

import (
    "fmt"
    "time"
)

func main() {

    c1 := make(chan string)
    c2 := make(chan string)

    go func() {
        time.Sleep(1 * time.Second)
        c1 <- "one"
    }()
    go func() {
        time.Sleep(2 * time.Second)
        c2 <- "two"
    }()

    for i := 0; i < 2; i++ {
        // use select to await both values simultaneously
        select {
        case msg1 := <-c1:
            fmt.Println("received", msg1)
        case msg2 := <-c2:
            fmt.Println("received", msg2)
        }
    }
}

```


## Concurrent Map

* https://www.youtube.com/watch?v=C1EtfDnsdDs
* https://medium.com/@deckarep/the-new-kid-in-town-gos-sync-map-de24a6bf7c2c
* https://golang.org/pkg/sync/

```go 


```


## Reference



* Roman Elizarov on goroutines verses kotlin coroutines
    * https://stackoverflow.com/questions/46864623/which-of-coroutines-goroutines-and-kotlin-coroutines-are-faster


http://journal.stuffwithstuff.com/2015/02/01/what-color-is-your-function/



* Bryan C Mills - An overview of sync.Map
    * https://www.youtube.com/watch?v=C1EtfDnsdDs



https://medium.com/@trevor4e/learning-gos-concurrency-through-illustrations-8c4aff603b3

https://yourbasic.org/golang/concurrent-programming/

