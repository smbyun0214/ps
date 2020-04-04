#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int height, width;

bool visited[100][100];
char board[100][100];
int dist[100][100];

bool inRange(int y, int x) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

void algospot(int y, int x) {
    dist[y][x] = 0; visited[y][x] = false;
    
    while (true) {
        int closest = INF;
        
        for (int i = height - 1; 0 <= i; --i) {
            for (int j = width - 1; 0 <= j; --j) {
                if (dist[i][j] < closest && !visited[i][j]) {
                    closest = dist[i][j];
                    y = i; x = j;
                }
            }
        }
        
        if (closest == INF) break;
        
        visited[y][x] = true;
        
        for (int direction = 0; direction < 4; ++direction) {
            int nextY = y + dy[direction], nextX = x + dx[direction];
            if (inRange(nextY, nextX) && !visited[nextY][nextX]) {
                if (board[nextY][nextX] == '0')
                    dist[nextY][nextX] = dist[y][x];
                else
                    dist[nextY][nextX] = min(dist[nextY][nextX], dist[y][x] + 1);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(visited, false, sizeof(visited));
    memset(board, 0, sizeof(board));
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            dist[i][j] = INF;
    
    cin >> width >> height;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> board[i][j];
        }
    }
    
    algospot(0, 0);
    
    cout << dist[height - 1][width - 1] << '\n';
    
    return 0;
}
