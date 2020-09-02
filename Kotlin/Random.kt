
fun randomId(): Int = (1..99999).random()


fun getRandomString(length: Int) : String {
    val allowedChars = ('A'..'Z') + ('a'..'z') + ('1'..'9')
    return (1..length)
        .map { allowedChars.random() }
        .joinToString("")
}
