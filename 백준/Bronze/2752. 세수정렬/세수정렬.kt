fun main() {
    val input = readlnOrNull() ?: ""
    val numbers = input.split(" ").mapNotNull { it.toIntOrNull() }

    val sortedList = numbers.sorted()
    sortedList.forEach(::println)
}