#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 987654321;
const int dz[] = {0, 0, 0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0, 0, 0};
const int dx[] = {0, 0, -1, 1, 0, 0};

struct Coordinates {
    int weight;
    int z, y, x;
    
    Coordinates (int weight, int z, int y, int x) : weight(weight), z(z), y(y), x(x) { }
    
    Coordinates delta(int direction) const {
        return Coordinates(weight + 1, z + dz[direction], y + dy[direction], x + dx[direction]);
    }
    
    bool operator > (const Coordinates &other) const {
        return weight > other.weight;
    }
};

int L, R, C;

bool visited[30][30][30];
char board[30][30][30];
int dist[30][30][30];

bool inRange(int z, int y, int x) {
    return 0 <= z && z < L && 0 <= y && y < R && 0 <= x && x < C;
}

void escapeBuilding(int z, int y, int x) {
    dist[z][y][x] = 0;
    visited[z][y][x] = true;
    
    priority_queue<Coordinates, vector<Coordinates>, greater<>> pq;
    pq.push(Coordinates(0, z, y, x));
    
    while (!pq.empty()) {
        Coordinates here = pq.top();
        pq.pop();
        
        if (here.weight < dist[here.z][here.y][here.x]) continue;
        
        visited[here.z][here.y][here.x] = true;
        
        for (int direction = 0; direction < 6; ++direction) {
            Coordinates there = here.delta(direction);
            if (inRange(there.z, there.y, there.x) && board[there.z][there.y][there.x] != '#' && !visited[there.z][there.y][there.x]) {
                if (there.weight < dist[there.z][there.y][there.x]) {
                    dist[there.z][there.y][there.x] = there.weight;
                    pq.push(there);
                }
            }
        }
    }
}
//
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    while (true) {
        cin >> L >> R >> C;
        
        if (L == 0 || R == 0 || C == 0) break;
        
        memset(visited, false, sizeof(visited));
        memset(board, 0, sizeof(board));
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < R; ++j) {
                for (int k = 0; k < C; ++k) {
                    dist[i][j][k] = INF;
                }
            }
        }
        
        int startZ, startY, startX;
        int endZ, endY, endX;
        
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < R; ++j) {
                for (int k = 0; k < C; ++k) {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S') {
                        startZ = i;
                        startY = j;
                        startX = k;
                    }
                    else if (board[i][j][k] == 'E') {
                        endZ = i;
                        endY = j;
                        endX = k;
                    }
                }
            }
        }
        
        escapeBuilding(startZ, startY, startX);
        
        if (dist[endZ][endY][endX] != INF)
            cout << "Escaped in " << dist[endZ][endY][endX] << " minute(s)." << '\n';
        else
            cout << "Trapped!" << '\n';
    }
    
    return 0;
}
