fun main() {
    val input = readlnOrNull()?.split(" ") ?: listOf("0", "0")
    val a = input[0].toIntOrNull() ?: 0
    val b = input[1].toIntOrNull() ?: 0

    if(a<b) {
        println("<")
    } else if(a > b) {
        println(">")
    } else {
        println("==")
    }
}