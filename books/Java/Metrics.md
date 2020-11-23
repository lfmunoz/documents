

```kotlin
     private const val CPE_ACTIVE_CHANNELS = "cpe.active.channels"
        var clientActive: AtomicInteger = Metrics.globalRegistry.gauge(CPE_ACTIVE_CHANNELS,
                AtomicInteger(0))!!

        // INFORM ENABLED
        private const val INFORM_LOOP_ENABLED = "cwmp.inform.enabled"
        var informLoopEnabledMetric: AtomicInteger = Metrics.globalRegistry.gauge(INFORM_LOOP_ENABLED,
                AtomicInteger(0))!!

        // INFORM LOOP
        val informLoopMetric: Timer = Timer
                .builder("cwmp.inform.loop")
                .description("Timer for looping through devices")
                .publishPercentiles(.95)
                .register(Metrics.globalRegistry)

        // INFORM SEQ
        private const val DEVICE_INFORM_SEQ = "cwmp.inform.seq"
        private const val DEVICE_INFORM_SEQ_DESC = "Percentiles for specific inform operations"
        val dbLookUpMetric: Timer = Timer
                .builder(DEVICE_INFORM_SEQ)
                .tags(TAG_KEY_TYPE, "DB_LOOK_UP")
                .description(DEVICE_INFORM_SEQ_DESC)
                .publishPercentiles( .95)
                .register(Metrics.globalRegistry)

        val withoutAutSeqMetric: Timer = Timer
                .builder(DEVICE_INFORM_SEQ)
                .tags(TAG_KEY_TYPE, "NO_AUTH")
                .description(DEVICE_INFORM_SEQ_DESC)
                .publishPercentiles( .95)
                .register(Metrics.globalRegistry)

        const val TAG_KEY_TYPE = "type"
        const val TAG_KEY_RESP = "resp"
        const val TAG_KEY_REASON = "reason"
const val CLOSER_REASON = "connection.close"

private val connectedMeter = Metrics.counter(connectedFrameCountName)
 disconnectMeter.increment()

     Metrics.counter(CLOSER_REASON, TAG_KEY_REASON, reason.name).increment()

```

