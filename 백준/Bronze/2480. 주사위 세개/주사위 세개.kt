fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }
    val result = when {
        input[0] == input[1] && input[1] == input[2] -> 10000 + input[0] * 1000
        input[0] == input[1] || input[0] == input[2] -> 1000 + input[0] * 100
        input[1] == input[2] -> 1000 + input[1] * 100
        else -> input.maxOrNull()!! * 100
    }
    println(result)
}