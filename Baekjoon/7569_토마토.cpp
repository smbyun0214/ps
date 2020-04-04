#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int dz[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dx[] = {0, 0, 0, 0, -1, 1};

int width, length, height;

int board[100][100][100];
int dist[100][100][100];

struct Coordinates {
    int z, y, x;
    Coordinates(int z, int y, int x) : z(z), y(y), x(x) { }
};

bool inRange(int z, int y, int x) {
    return 0 <= z && z < height && 0 <= y && y < length && 0 <= x && x < width;
}

void tomato() {
    queue<Coordinates> q;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            for (int k = 0; k < width; ++k) {
                if (board[i][j][k] == 1) {
                    dist[i][j][k] = 0;
                    q.push(Coordinates(i, j, k));
                }
            }
        }
    }
    
    while (!q.empty()) {
        int z = q.front().z, y = q.front().y, x = q.front().x;
        q.pop();
        
        for (int direction = 0; direction < 6; ++direction) {
            int nextZ = z + dz[direction], nextY = y + dy[direction], nextX = x + dx[direction];
            if (inRange(nextZ, nextY, nextX) && board[nextZ][nextY][nextX] == 0 && dist[nextZ][nextY][nextX] == -1) {
                dist[nextZ][nextY][nextX] = dist[z][y][x] + 1;
                q.push(Coordinates(nextZ, nextY, nextX));
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(board, 0, sizeof(board));
    memset(dist, -1, sizeof(dist));
    
    cin >> width >> length >> height;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            for (int k = 0; k < width; ++k) {
                cin >> board[i][j][k];
            }
        }
    }
    
    tomato();
    
    int ret = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            for (int k = 0; k < width; ++k) {
                if (board[i][j][k] != -1 && dist[i][j][k] == -1) {
                    ret = -1;
                    break;
                }
                
                ret = max(ret, dist[i][j][k]);
            }
            
            if (ret == -1) break;
        }
        
        if (ret == -1) break;
    }
    
    cout << ret << '\n';
    
    return 0;
}
