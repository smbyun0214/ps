#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int N;

bool visited[100][100];
int adjacent[100][100];

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

void islandBound(int y, int x, vector<pair<int, int>> &bound) {
    visited[y][x] = true;
    
    bool isBound = false;
    for (int direction = 0; direction < 4; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (inRange(nextY, nextX) && !visited[nextY][nextX]) {
            if (adjacent[nextY][nextX] == 0)
                isBound = true;
            else
                islandBound(nextY, nextX, bound);
        }
    }
    
    if (isBound) bound.push_back(make_pair(y, x));
}

int getBridgeLength(const pair<int, int> &p1, const pair<int, int> &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second) - 1;
}

int getBridgeLength(const vector<pair<int, int>> &bound1, const vector<pair<int, int>> &bound2) {
    int ret = 10000;
    
    for (int i = 0; i < bound1.size(); ++i) {
        for (int j = 0; j < bound2.size(); ++j) {
            ret = min(ret, getBridgeLength(bound1[i], bound2[j]));
        }
    }
    
    return ret;
}

int minBridge(const vector<vector<pair<int, int>>> &bounds) {
    int ret = 10000;
    
    for (int i = 0; i < bounds.size(); ++i) {
        for (int j = i + 1; j < bounds.size(); ++j) {
            ret = min(ret, getBridgeLength(bounds[i], bounds[j]));
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(adjacent, 0, sizeof(adjacent));
    memset(visited, false, sizeof(visited));

    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adjacent[i][j];
        }
    }
    
    vector<vector<pair<int, int>>> bounds;
    
    vector<pair<int, int>> bound;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && adjacent[i][j] == 1) {
                bound.clear();
                islandBound(i, j, bound);
                bounds.push_back(bound);
            }
        }
    }
    
    cout << minBridge(bounds) << '\n';
    
    return 0;
}

