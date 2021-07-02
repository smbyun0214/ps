// https://www.acmicpc.net/problem/1865

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int INF = 987654321;
int times[501];

void init() {
    for (int i = 0; i < 501; ++i) {
        times[i] = INF;
    }
}

bool BellmanFord(vector<vector<pair<int, int>> > &board, int N) {
    bool isCycle = false;

    for (int i = 0; i < N; ++i) {
        for (int here = 1; here <= N; ++here) {
            for (pair<int, int>& p : board[here]) {
                int there = p.first;
                int cost = times[here] + p.second;
                
                if (cost < times[there]) {
                    times[there] = cost;

                    if (i + 1 == N) {
                        isCycle = true;
                    }
                }
            }
        }
    }

    return !isCycle;
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int testcase;
    cin >> testcase;

    while (testcase--) {
        init();

        int N, M, W, S, E, T;
        cin >> N >> M >> W;

        vector<vector<pair<int, int>> > board(N + 1);

        for (int i = 0; i < M; ++i) {
            cin >> S >> E >> T;
            board[S].push_back(make_pair(E, T));
            board[E].push_back(make_pair(S, T));

        }
        for (int i = 0; i < W; ++i) {
            cin >> S >> E >> T;
            board[S].push_back(make_pair(E, -T));
        }

        cout << (BellmanFord(board, N) ? "NO" : "YES") << '\n';
    }
    
    return 0;
}
