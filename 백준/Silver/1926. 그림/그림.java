import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    static class Coord {
        int y;
        int x;

        public Coord(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] board = new int[n][m];
        boolean[][] visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num = sc.nextInt();
                board[i][j] = num;
            }
        }

        int[] dy = {1, 0, -1, 0};
        int[] dx = {0, 1, 0, -1};

        int pictureNumber = 0;
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    visited[i][j] = true;
                    Deque<Coord> deque = new ArrayDeque<>();
                    deque.push(new Coord(i, j));
                    pictureNumber++;

                    while (!deque.isEmpty()) {
                        Coord coord = deque.pop();
                        area++;
                        for (int z = 0; z < 4; z++) {
                            int ny = coord.y + dy[z];
                            int nx = coord.x + dx[z];
                            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || board[ny][nx] == 0)
                                continue;
                            visited[ny][nx] = true;
                            deque.push(new Coord(ny, nx));
                        }
                    }
                    maxArea = Math.max(maxArea, area);
                }
            }
        }

        System.out.println(pictureNumber);
        System.out.println(maxArea);
    }
}
