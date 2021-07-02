// https://www.acmicpc.net/problem/1167

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visited[100001];

pair<int, int> getEdgeNodeIndex(int here, int step, vector<vector<pair<int, int>> > &tree) {
    visited[here] = true;

    pair<int, int> ret(step, here);
    for (int i = 0; i < tree[here].size(); ++i) {
        int there = tree[here][i].first;
        int dist = tree[here][i].second;
        if (!visited[there]) {
            pair<int, int> subRet = getEdgeNodeIndex(there, step + dist, tree);
            if (ret.first < subRet.first) {
                ret.first = subRet.first;
                ret.second = subRet.second;
            }
        }
    }

    return ret;
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // memset(cache, -1, sizeof(cache));
    memset(visited, false, sizeof(visited));

    int N;
    cin >> N;

    vector<vector<pair<int, int>> > trees(N + 1);

    int u, v, dist;
    for (int i = 0; i < N; ++i) {
        cin >> u;
        while (true) {
            cin >> v;

            if (v == -1) {
                break;
            }

            cin >> dist;
            
            trees[u].push_back(make_pair(v, dist));
        }
    }

    memset(visited, false, sizeof(visited));
    pair<int, int> ret = getEdgeNodeIndex(N - 1, 0, trees);
    int edgeNode = ret.second;

    memset(visited, false, sizeof(visited));
    ret = getEdgeNodeIndex(edgeNode, 0, trees);
    cout << ret.first << '\n';

    return 0;
}
