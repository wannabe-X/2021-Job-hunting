import java.util.*;
public class Main {

    private static int minTime = Integer.MAX_VALUE;
    private static boolean flag = false;
    private static int row;
    private static int col;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int row = scanner.nextInt();
        int col = scanner.nextInt();
        Main.row = row;
        Main.col = col;
        int[][] map = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                map[i][j] = scanner.nextInt();
            }
        }
        if (map[0][0] == 0 || map[row - 1][col - 1] < row + col - 1) {
            System.out.println(-1);
        } else {
            boolean[][] visited = new boolean[row][col];
            dfs(map, 0, visited, 0, 0);
            if (flag) {
                System.out.println(minTime);
            } else {
                System.out.println(-1);
            }
        }

    }

    private static void dfs(int[][] map, int time, boolean[][] visited, int i, int j) {
        if (map[i][j] <= time) {
            return;
        }

        if (i == row - 1 && j == col - 1) {
            minTime = Math.min(minTime, time);
            flag = true;
        }

        if (i != row - 1 && map[i + 1][j] > time + 1 && !visited[i + 1][j]) {
            visited[i][j] = true;
            dfs(map, time + 1, visited, i + 1, j);
        }

        if (j != col - 1 && map[i][j + 1] > time + 1 && !visited[i][j + 1]) {
            visited[i][j] = true;
            dfs(map, time + 1, visited, i, j + 1);
        }

        if (i != 0 && map[i - 1][j] > time + 1 && !visited[i - 1][j]) {
            visited[i][j] = true;
            dfs(map, time + 1, visited, i - 1, j);
        }

        if (j != 0 && map[i][j - 1] > time + 1 && !visited[i][j - 1]) {
            visited[i][j] = true;
            dfs(map, time + 1, visited, i, j - 1);
        }
        visited[i][j] = false;
    }

}
