fun main() {
    //첫째 줄에 두 정수 H와 M이 주어진다. 
    //H는 시를 나타내며 0<=H<=23, M은 분을 나타내며 0<=M<=59이다.
    val (H, M) = readLine()!!.split(' ').map(String::toInt)
    // 45분 일찍 알람 설정
    val alarm = (H * 60 + M - 45 + 1440) % 1440
    println("${alarm / 60} ${alarm % 60}")
}