// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int fishes[20][20];
int visited[20][20];

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

int inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

tuple<int, pair<int, int>> search(int y, int x, int value) {
    pair<int, int> pos(-y, -x);
    int step = 0;
    visited[y][x] = 1;

    priority_queue<tuple<int, pair<int, int>> > pq;
    priority_queue<tuple<int, pair<int, int>> > candidates;

    pq.push(make_tuple(step, pos));

    while (!pq.empty()) {
        tuple<int, pair<int, int>> here = pq.top();
        pq.pop();

        step = -get<0>(here);

        pos = get<1>(here);
        y = -pos.first;
        x = -pos.second;

        for (int direction = 0; direction < 4; ++direction) {
            int nextY = y + dy[direction], nextX = x + dx[direction];

            if (inRange(nextY, nextX) && !visited[nextY][nextX]) {
                if (fishes[nextY][nextX] == 0 || fishes[nextY][nextX] == value) {
                    visited[nextY][nextX] = visited[y][x] + 1;
                    pq.push(make_tuple(-(step + 1), make_pair(-nextY, -nextX)));
                }
                else if (fishes[nextY][nextX] < value) {
                    visited[nextY][nextX] = visited[y][x] + 1;
                    candidates.push(make_tuple(-(step + 1), make_pair(-nextY, -nextX)));
                }
            }
        }
    }

    if (candidates.empty()) {
        return make_tuple(-1, make_pair(-1, -1));
    }

    tuple<int, pair<int, int>> ret = candidates.top();
    int retSteps = -get<0>(ret);
    
    pair<int, int> retPos = get<1>(ret);
    int retY = -retPos.first;
    int retX = -retPos.second;

    fishes[retY][retX] = 0;

    return make_tuple(retSteps, make_pair(retY, retX));
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int y, x;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> fishes[i][j];
            if (fishes[i][j] == 9) {
                y = i; x = j;
                fishes[i][j] = 0;
            }
        }
    }

    int ret = 0;
    
    int steps = 0;
    int value = 2;
    int eatten = 0;
    pair<int, int> here(y, x);
    tuple<int, pair<int, int>> info;

    for (int i = 0; i < N*N; ++i) {
        memset(visited, 0, sizeof(visited));

        y = here.first;
        x = here.second;

        info = search(y, x, value);
        
        steps = get<0>(info);
        here = get<1>(info);

        if (steps == -1) {
            break;
        }
        eatten += 1;
        if (eatten == value) {
            value += 1;
            eatten = 0;
        }

        ret += steps;
    }

    cout << ret << '\n';

    return 0;
}
