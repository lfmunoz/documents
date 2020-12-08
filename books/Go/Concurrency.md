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

* Roman Elizarov on goroutines verses kotlin coroutines
    * https://stackoverflow.com/questions/46864623/which-of-coroutines-goroutines-and-kotlin-coroutines-are-faster


http://journal.stuffwithstuff.com/2015/02/01/what-color-is-your-function/



* Bryan C Mills - An overview of sync.Map
    * https://www.youtube.com/watch?v=C1EtfDnsdDs