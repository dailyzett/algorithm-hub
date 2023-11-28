fun main() {
    //첫째 줄에는 현재 시각이 나온다.
    //현재 시각은 시 A (0 ≤ A ≤ 23) 와 분 B (0 ≤ B ≤ 59)가 정수로 빈칸을 사이에 두고 순서대로 주어진다.
    //두 번째 줄에는 요리하는 데 필요한 시간 C (0 ≤ C ≤ 1,000)가 분 단위로 주어진다.
    //첫째 줄에 종료되는 시각의 시와 분을 공백을 사이에 두고 출력한다.
    
    val (hour, minute) = readLine()!!.split(" ").map { it.toInt() }
    val cookingTime = readLine()!!.toInt()
    val totalMinute = hour * 60 + minute + cookingTime
    val resultHour = totalMinute / 60 % 24
    val resultMinute = totalMinute % 60
    println("$resultHour $resultMinute")
}