// https://www.acmicpc.net/problem/14938

#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>

using namespace std;

bool visited[101];
int score[101];
int traj[101][101];

unordered_set<int> set;

void farming(int here, int step, vector<int>& nodes, int numNodes, int maxStep) {
    if (step <= maxStep) {
        for (int i : nodes) {
            set.insert(i);
        }
    }
    else {
        return;
    }

    for (int there = 1; there <= numNodes; ++there) {
        if (!visited[there] && traj[here][there] != 0 && step + traj[here][there] <= maxStep) {
            visited[there] = true;
            nodes.push_back(there);
            farming(there, step + traj[here][there], nodes, numNodes, maxStep);
            nodes.pop_back();
            visited[there] = false;
        }
    }
    return;
}

int sumOfSet(unordered_set<int>& set) {
    int ret = 0;
    for (unordered_set<int>::iterator it = set.begin(); it != set.end(); ++it) {
        ret += score[*it];
    }
    return ret;
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; ++i) {
        cin >> score[i];
    }

    for (int i = 0, v, w, s; i < r; ++i) {
        cin >> v >> w >> s;
        traj[v][w] = traj[w][v] = s;
    }
    
    int ret = 0;
    for (int start = 1; start <= n; ++start) {
        set.clear();
        vector<int> tmp = { start };
        visited[start] = true;
        farming(start, 0, tmp, n, m);
        ret = max(ret, sumOfSet(set));
        visited[start] = false;
    }

    cout << ret << '\n';

    return 0;
}
