#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int N;

bool visited[125][125];
int dist[125][125];
int board[125][125];

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

void losingRupees(int y, int x) {
    dist[y][x] = board[y][x]; visited[y][x] = false;
    
    while (true) {
        int closest = INF;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][j] < closest && !visited[i][j]) {
                    y = i; x = j;
                    closest = dist[i][j];
                }
            }
        }
        
        if (closest == INF) break;
        
        visited[y][x] = true;
        
        for (int direction = 0; direction < 4; ++direction) {
            int nextY = y + dy[direction], nextX = x + dx[direction];
            if (inRange(nextY, nextX) && !visited[nextY][nextX]) {
                int nextDist = closest + board[nextY][nextX];
                dist[nextY][nextX] = min(dist[nextY][nextX], nextDist);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int i = 0;
    while (++i) {
        cin >> N;
        
        if (N == 0) break;
        
        memset(visited, false, sizeof(visited));
        memset(board, 0, sizeof(board));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dist[i][j] = INF;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> board[i][j];
            }
        }
        
        losingRupees(0, 0);
        cout << "Problem " << i << ": " << dist[N - 1][N - 1] << '\n';
    }
    
    return 0;
}
