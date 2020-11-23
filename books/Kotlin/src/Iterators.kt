/**
 * Given a List<T> we create an infinite iterator.
 *         val itr  = infiniteIterator { historyBars }
 */
fun <T> infiniteIterator(supplier : () -> List<T>) = object : Iterator<T> {
    var idx = 0
    val list = supplier()
    @Synchronized
    override fun hasNext(): Boolean {
        return true
    }
    @Synchronized
    override fun next(): T {
        return list[idx++ % list.size]
    }
}