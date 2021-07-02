// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <limits>

using namespace std;

int N, M;
int board[1000][1000];

bool visited[1000][1000];
int srcToDst[1000][1000];
int dstToSrc[1000][1000];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int INF = 987654321;

void init() {
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            srcToDst[i][j] = INF;
            dstToSrc[i][j] = INF;
        }
    }
}

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void setDistance(int y, int x, int cache[][1000]) {
    memset(visited, false, sizeof(visited));

    int cost = 1;
    cache[y][x] = cost;

    priority_queue<pair<int, pair<int, int>> > pq;
    pq.push(make_pair(-cost, make_pair(y, x)));

    visited[y][x] = true;

    while (!pq.empty()) {
        pair<int, pair<int, int> > info = pq.top();
        pair<int, int> pos = info.second;
        pq.pop();

        int cost = -info.first;
        int y = pos.first;
        int x = pos.second;

        for (int direction = 0; direction < 4; ++direction) {
            int nextY = y + dy[direction], nextX = x + dx[direction];
            if (inRange(nextY, nextX) && !visited[nextY][nextX] && board[nextY][nextX] == 0) {
                visited[nextY][nextX] = true;

                int dist = cost + 1;
                cache[nextY][nextX] = dist;
                pq.push(make_pair(-dist, make_pair(nextY, nextX)));
            }
        }
    }
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();

    cin >> N >> M;

    string row;
    for (int i = 0; i < N; ++i) {
        cin >> row;
        for (int j = 0; j < M; ++j) {
            board[i][j] = row[j] - '0';
        }
    }

    setDistance(0, 0, srcToDst);
    setDistance(N-1, M-1, dstToSrc);

    int ret = INF;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (board[y][x] == 1) {
                if (inRange(y - 1, x) && srcToDst[y - 1][x] != INF
                 && inRange(y, x - 1) && dstToSrc[y][x - 1] != INF) {
                    ret = min(ret, srcToDst[y - 1][x] + dstToSrc[y][x - 1] + 1);
                }
                if (inRange(y - 1, x) && srcToDst[y - 1][x] != INF
                 && inRange(y, x + 1) && dstToSrc[y][x + 1] != INF) {
                    ret = min(ret, srcToDst[y - 1][x] + dstToSrc[y][x + 1] + 1);
                }
                if (inRange(y - 1, x) && srcToDst[y - 1][x] != INF
                 && inRange(y + 1, x) && dstToSrc[y + 1][x] != INF) {
                    ret = min(ret, srcToDst[y - 1][x] + dstToSrc[y + 1][x] + 1);
                }
                if (inRange(y + 1, x) && srcToDst[y + 1][x] != INF
                 && inRange(y, x - 1) && dstToSrc[y][x - 1] != INF) {
                    ret = min(ret, srcToDst[y + 1][x] + dstToSrc[y][x - 1] + 1);
                }
                if (inRange(y + 1, x) && srcToDst[y + 1][x] != INF
                 && inRange(y, x + 1) && dstToSrc[y][x + 1] != INF) {
                    ret = min(ret, srcToDst[y + 1][x] + dstToSrc[y][x + 1] + 1);
                }
                if (inRange(y, x - 1) && srcToDst[y][x - 1] != INF
                 && inRange(y, x + 1) && dstToSrc[y][x + 1] != INF) {
                    ret = min(ret, srcToDst[y][x - 1] + dstToSrc[y][x + 1] + 1);
                }
            }
        }
    }

    ret = min(ret, srcToDst[N - 1][M - 1]);
    cout << (ret == INF ? -1 : ret) << '\n';
    
    return 0;
}
