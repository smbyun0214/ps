// https://www.acmicpc.net/problem/15810

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, M;
    cin >> N >> M;

    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    
    int cost;
    while (N--) {
        cin >> cost;
        pq.push(make_pair(cost, cost));
    }

    long long ret = 0;
    for (int i = 0; i < M; ++i) {
        pair<long long, int> p = pq.top(); pq.pop();
        ret = p.first;
        p.first += p.second;
        pq.push(p);
    }
    
    cout << ret;

    return 0;
}
