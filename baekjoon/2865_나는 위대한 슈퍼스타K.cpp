// https://www.acmicpc.net/problem/2865

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main (int argc, char *argv[]) {
    int N, M, K;
    cin >> N >> M >> K;

    vector<bool> picked(K + 1, false);
    priority_queue<pair<double, int> > cands;

    int i;
    double s;
    while (M--) {
        for (int j = 0; j < N; ++j) {
            cin >> i >> s;
            cands.push(make_pair(s, i));
        }
    }

    double ret = 0;
    while (K--) {
        while (picked[cands.top().second]) {
            cands.pop();
        }
        
        pair<double, int> cand = cands.top();
        picked[cand.second] = true;
        ret += cand.first;
    }

    cout.precision(1);
    cout << fixed << ret;
    
    return 0;
}
