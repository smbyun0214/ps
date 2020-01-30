#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<vector<pair<int, int>>> listOfDirection(int type) {
    vector<vector<pair<int, int>>> ret;
    
    int loop = 0, dirs = 0;
    
    if (type == 0 || type == 2 || type == 3) {
        if (type == 0)
            dirs = 1;
        else
            dirs = type;
        
        loop = 4;
    }
    else if (type == 1) {
        dirs = 2;
        loop = 2;
    }
    else {
        dirs = 4;
        loop = 1;
    }
        
    
    for (int i = 0; i < loop; ++i) {
        vector<pair<int, int>> dir;
        
        if (type == 1) ++dirs;
        
        for (int j = 0; j < dirs; ++j) {
            dir.push_back(make_pair(directions[(i + j) % 4][0], directions[(i + j) % 4][1]));
            
            if (type == 1) ++j;
        }
        
        ret.push_back(dir);
        
        if (type == 4) break;
    }
    
    return ret;
}

int N, M;

int used[8][8];
int board[8][8];

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M && used[y][x] != -1;
}

int countBlindspot() {
    int ret = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!used[i][j])
                ++ret;
        }
    }

    return ret;
}

void spreading(int y, int x, const pair<int, int> &dir, const int delta) {
    if (!inRange(y, x))
        return;
    
    used[y][x] += delta;
    spreading(y + dir.first, x + dir.second, dir, delta);
}

int watching(int toPick, const vector<pair<int, int>> &cameras) {
    if (toPick == -1)
        return countBlindspot();
    
    int ret = 987654321;
    
    pair<int, int> camera = cameras[toPick];
    
    vector<vector<pair<int, int>>> list = listOfDirection(board[camera.first][camera.second] - 1);
    
    for (vector<pair<int, int>> dirs : list) {
        for (pair<int, int> dir : dirs) {
            int nextY = camera.first + dir.first, nextX = camera.second + dir.second;
            spreading(nextY, nextX, dir, 1);
        }
        
        ret = min(ret, watching(toPick - 1, cameras));
        
        for (pair<int, int> dir : dirs) {
            int nextY = camera.first + dir.first, nextX = camera.second + dir.second;
            spreading(nextY, nextX, dir, -1);
        }
    }
    
    return ret;
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(used, 0, sizeof(used));
    memset(board, 0, sizeof(board));
    
    cin >> N >> M;
    
    vector<pair<int, int>> cameras;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            
            if (board[i][j] == 6)
                used[i][j] = -1;
            else if (1 <= board[i][j]) {
                cameras.push_back(make_pair(i, j));
                used[i][j] = 1;
            }
        }
    }
    
    cout << watching(cameras.size() - 1, cameras) << '\n';
    
    return 0;
}

