fun main() {
    val input = readlnOrNull()?.toIntOrNull() ?: 0

    println(
        when {
            (input % 4 == 0 && (input % 100 != 0 || input % 400 == 0)) -> 1
            else -> 0
        }
    )
}