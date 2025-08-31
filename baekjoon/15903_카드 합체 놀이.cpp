// https://www.acmicpc.net/problem/15903

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main (int argc, char *argv[]) {
    
    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long> > pq;

    int num;
    while (n--) {
        cin >> num;
        pq.push(num);
    }

    while (m--) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }

    long long ret = 0;
    while (!pq.empty()) {
        ret += pq.top();
        pq.pop();
    }

    cout << ret;

    return 0;
}
