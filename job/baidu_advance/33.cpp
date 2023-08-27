#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 定义一个Point结构体表示二维坐标点
struct Point2 {
    int x;
    int y;
};

// 定义一个八邻的方向数组，表示八个相邻点的偏移量
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // 对应x坐标的偏移量
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // 对应y坐标的偏移量

// 使用八邻进行BFS搜索

int bfs(std::vector<std::vector<int>>& grid, Point2 start, Point2 end) {
    int m = grid.size();
    cout << "m:" << m << endl;
    int n = grid[0].size();
    cout << "n:" << n << endl;
    vector<vector<bool>> visited(m, vector<bool>(n, false)); // 用来记录每个位置是否被访问过
    vector<vector<int>> dis(m, vector<int>(n, 0)); // 用来记录每个位置是否被访问过

    queue<Point2> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Point2 current = q.front();
        q.pop();

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<11;j++)
        {
            cout << dis[i][j] << " " ;
        }
        cout << endl;
    }

     cout << endl;

        // 到达终点，返回结果
        if (current.x == end.x && current.y == end.y) {
            // cout << current.x << " " << current.y << endl;
            return grid[current.x][current.y];
        }

        // 遍历八个方向上的相邻点
        for (int i = 0; i < 8; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // 检查相邻点是否合法和未被访问
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                if(grid[current.x][current.y] >0)
                    dis[nx][ny]++;
            }

        }
    }


    // 无法到达终点，返回-1
    return -1;
}

int main() {
    // 创建一个 5x5 的网格

    std::vector<std::vector<int>> grid = {
        {0,0,0,0,1,1,1,0,0,0,0},
        {0,0,0,1,1,1,1,1,1,0,0},
        {0,0,0,0,1,1,1,1,1,0,0}
    };


    Point2 start = {0, 0}; // 起点
    Point2 end = {2, 10}; // 终点

    int shortestPath = bfs(grid, start, end);
    cout << "最短路径长度为: " << shortestPath << endl;

    return 0;
}