



# Time



https://github.com/Kotlin/kotlinx-datetime




```kotlin
import kotlinx.datetime.Instant

fun main() {

    val time = System.currentTimeMillis() // 1608405149330
    val instant = Instant.fromEpochMilliseconds(time) // 2020-12-19T19:12:29.330Z

    val date = instant.toLocalDateTime(TimeZone.currentSystemDefault()).date // 2020-12-19
}


val currentMoment = Clock.System.now()

val datetimeInUtc: LocalDateTime = currentMoment.toLocalDateTime(TimeZone.UTC)
val datetimeInSystemZone: LocalDateTime = currentMoment.toLocalDateTime(TimeZone.currentSystemDefault())


```