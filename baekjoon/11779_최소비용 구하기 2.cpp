// https://www.acmicpc.net/problem/11779

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

int n;
int prices[1001][1001];

int INF = numeric_limits<int>::max();
int heads[1001];
int dists[1001];

void init() {
    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            prices[i][j] = INF;
        }
    }
    for (int i = 0; i < 1001; ++i) {
        dists[i] = INF;
    }
}

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

vector<int> searching(int src, int dst) {
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));

    dists[src] = 0;

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();

        int here = p.second;
        int dist = -p.first;

        if (dists[here] < dist) {
            continue;
        }

        for (int there = 1; there <= n; ++there) {
            if (prices[here][there] != INF) {
                int cost = dist + prices[here][there];
                if (cost < dists[there]) {
                    dists[there] = cost;
                    heads[there] = here;
                    pq.push(make_pair(-cost, there));
                }
            }
        }
    }

    vector<int> ret;
    while(src != dst) {
        ret.push_back(dst);
        dst = heads[dst];
    }
    ret.push_back(src);

    reverse(ret.begin(), ret.end());

    return ret;
}


int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(heads, -1, sizeof(heads));
    
    init();

    int m;
    cin >> n >> m;

    int u, v, p;
    while (m--) {
        cin >> u >> v >> p;
        prices[u][v] = min(prices[u][v], p);
    }

    int from, to;
    cin >> from >> to;

    vector<int> ret = searching(from, to);

    cout << dists[to] << '\n';
    cout << ret.size() << '\n';
    for (int i : ret) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
