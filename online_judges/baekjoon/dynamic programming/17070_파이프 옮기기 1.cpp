// https://www.acmicpc.net/problem/17070

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<pair<int, int>> > pipes = {
    {{0, 0}, {0, 1}},
    {{0, 0}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}
};

int N;
int board[16][16];

int cache[3][16][16];

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

bool isValid(int pipeNo, int y, int x) {
    for (pair<int, int>& dydx: pipes[pipeNo]) {
        int dy = dydx.first, dx = dydx.second;
        int nextY = y + dy, nextX = x + dx;
        if (!inRange(nextY, nextX) || board[nextY][nextX] != 0) {
            return false;
        }
    }
    return true;
}

int searching(int pipeNo, int y, int x) {
    if (y == N - 1 && x == N - 1) {
        return 1;
    }

    int &ret = cache[pipeNo][y][x];
    if (ret != -1) {
        return ret;
    }

    ret = 0;

    if (pipeNo == 0) {
        int nextNo = 0;
        if (isValid(nextNo, y, x)) {
            pair<int, int> dydx = pipes[nextNo].back();
            int dy = dydx.first, dx = dydx.second;
            int nextY = y + dy, nextX = x + dx;

            ret += searching(nextNo, nextY, nextX);
        }
        nextNo = 2;
        if (isValid(nextNo, y, x)) {
            pair<int, int> dydx = pipes[nextNo].back();
            int dy = dydx.first, dx = dydx.second;
            int nextY = y + dy, nextX = x + dx;

            ret += searching(nextNo, nextY, nextX);
        }
    }

    if (pipeNo == 1) {
        int nextNo = 1;
        if (isValid(nextNo, y, x)) {
            pair<int, int> dydx = pipes[nextNo].back();
            int dy = dydx.first, dx = dydx.second;
            int nextY = y + dy, nextX = x + dx;

            ret += searching(nextNo, nextY, nextX);
        }
        nextNo = 2;
        if (isValid(nextNo, y, x)) {
            pair<int, int> dydx = pipes[nextNo].back();
            int dy = dydx.first, dx = dydx.second;
            int nextY = y + dy, nextX = x + dx;

            ret += searching(nextNo, nextY, nextX);
        }
    }

    if (pipeNo == 2) {
        for (int nextNo = 0; nextNo < 3; ++nextNo) {
            if (isValid(nextNo, y, x)) {
                pair<int, int> dydx = pipes[nextNo].back();
                int dy = dydx.first, dx = dydx.second;
                int nextY = y + dy, nextX = x + dx;

                ret += searching(nextNo, nextY, nextX);
            }
        }
    }

    return ret;
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(cache, -1, sizeof(cache));
    
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    cout << searching(0, 0, 1) << '\n';
    
    return 0;
}
