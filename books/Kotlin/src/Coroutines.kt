

// https://www.lukaslechner.com/why-exception-handling-with-kotlin-coroutines-is-so-hard-and-how-to-successfully-master-it/

coroutineScope{} re-throws exceptions of its failing children instead of propagating them up the job hierarchy.



    fun start(): Job {
        return scope.launch {
            log.info().log("~~ Created {} Vert.X eventloop-threads...", eventLoopThreads)
            eb.consumer<JsonObject>(MGR_ADDR, eventBusHandler())
            log.info().log("~~ Creating {} Agents...", agentConfig.numberOfClients)
            threadId = Thread.currentThread().id
            addAgents(0, agentConfig.numberOfClients)
            reconnectLoop.start(clientLoadDelay)
            checkerLoop.start(CHECKER_LOOP_DELAY)
        }
    }

    private suspend fun addAgents(inclusiveStart: Int, inclusiveEnd: Int) {
        if(isBusy) return
        isBusy = true
        (newFixedThreadPoolContext(eventLoopThreads, "addAgents").use {
            withContext(it) {
                db.open()
                val newAgents = (inclusiveStart until inclusiveEnd).map {
                    async {createAgent(contextIterator.next(), agentConfig.nextSerialNumber(it))}
                }.awaitAll()
                agents.addAll(newAgents)
                db.close()
            }
        })
        isBusy = false
    }