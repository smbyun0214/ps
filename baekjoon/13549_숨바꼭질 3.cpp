// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visited[200001];

int searching(int src, int dst) {
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, -src));

    visited[src] = true;

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();

        int cost = -p.first;
        int here = -p.second;

        if (here == dst) {
            return cost;
        }

        if (0 < here && here < dst && !visited[2 * here]) {
            visited[2 * here] = true;
            pq.push(make_pair(-cost, -(2 * here)));
        }
        if (here < dst && !visited[here + 1]) {
            visited[here + 1] = true;
            pq.push(make_pair(-(cost + 1), -(here + 1)));
        }
        if (0 < here && !visited[here - 1]) {
            visited[here - 1] = true;
            pq.push(make_pair(-(cost + 1), -(here - 1)));
        }
    }

    return -1;
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(visited, false, sizeof(visited));

    int N, K;
    cin >> N >> K;

    cout << searching(N, K) << '\n';
    
    return 0;
}
