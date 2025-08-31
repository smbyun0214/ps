// https://www.acmicpc.net/problem/14425

#include <iostream>
#include <cstring>

using namespace std;

int N;
bool adj[1001][1001];

bool isVisited[1001];
int degree[1001];

int solve(int here) {
    isVisited[here] = true;

    int ret = 1;
    for (int there = 1; there <= N; ++there) {
        if (!isVisited[there]) {
            ret += solve(there);
        }
    }

    return ret;
}

int main (int argc, char *argv[]) {
    
    int testcase;
    cin >> testcase;

    int M, u, v;
    while (testcase--) {
        cin >> N >> M;
        memset(adj, 0, sizeof(adj));
        memset(isVisited, 0, sizeof(isVisited));
        memset(degree, 0, sizeof(degree));

        for (int i = 0; i < M; ++i) {
            cin >> u >> v;
            adj[u][v] = adj[v][u] = true;
            degree[u] += 1;
            degree[v] += 1;
        }

        int start = 1, minDegree = 1001;
        for (int i = 1; i <= N; ++i) {
            if (degree[i] != 0 && degree[i] < minDegree) {
                minDegree = degree[i];
                start = i;
            }
        }
        cout << solve(start) - 1 << '\n';
    }
    
    return 0;
}
