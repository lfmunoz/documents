



# Collections




# Map


```kotlin


fun convertListToMap() {
    //  takes two lambdas for generating the key and value
    val map = friends.associateBy({it.facebookId}, {it.points})

    // Create a list of Pair which can be used by toMap to generate the final map:
    val map = friends.map { it.facebookId to it.points }.toMap()
}


```