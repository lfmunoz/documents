

// https://www.lukaslechner.com/why-exception-handling-with-kotlin-coroutines-is-so-hard-and-how-to-successfully-master-it/

coroutineScope{} re-throws exceptions of its failing children instead of propagating them up the job hierarchy.