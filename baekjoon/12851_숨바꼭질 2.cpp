// https://www.acmicpc.net/problem/12851

#include <iostream>
#include <queue>

using namespace std;

int costs[200000];

int INF = 987654321;

void init() {
    for (int i = 0; i < 200000; ++i) {
        costs[i] = INF;
    }
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();

    int N, K;
    cin >> N >> K;

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, N));

    int retCost = INF;
    int retVisitedCnt = 0;

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();

        int here = p.second;
        int cost = -p.first;

        if (costs[here] < cost || retCost < cost) {
            continue;
        }

        costs[here] = cost;

        if (here == K) {
            retCost = cost;
            ++retVisitedCnt;
        }

        if (here + 1 <= K) {
            pq.push(make_pair(-(cost + 1), here + 1));
        }
        if (0 <= here - 1) {
            pq.push(make_pair(-(cost + 1), here - 1));
        }
        if (here < K) {
            pq.push(make_pair(-(cost + 1), 2 * here));
        }
    }

    cout << retCost << '\n';
    cout << retVisitedCnt << '\n';
    
    return 0;
}
