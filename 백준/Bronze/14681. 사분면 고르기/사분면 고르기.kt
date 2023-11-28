fun main() {
    //첫 줄에는 정수 x가 주어진다
    val x = readLine()!!.toInt()
    //두번째 줄에는 정수 y가 주어진다
    val y = readLine()!!.toInt()
    //점 (x,y)의 사분면 번호(1,2,3,4 중 하나)를 출력한다
    if (x > 0 && y > 0) {
        println(1)
    } else if (x < 0 && y > 0) {
        println(2)
    } else if (x < 0 && y < 0) {
        println(3)
    } else {
        println(4)
    }
}