


sealed class GenericResult<R> {
    data class Success<R>(val result: R): GenericResult<R>()
    data class Failure<R>(val message: String, val cause: Exception? = null) : GenericResult<R>()
}
