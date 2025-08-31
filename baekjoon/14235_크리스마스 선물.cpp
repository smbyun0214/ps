// https://www.acmicpc.net/problem/14235

#include <iostream>
#include <queue>

using namespace std;

int main (int argc, char *argv[]) {
    
    int n, a;
    cin >> n;

    priority_queue<int> pq;

    int gift;

    while (n--) {
        cin >> a;

        if (a == 0) {
            if (pq.empty())
                cout << -1 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        
        for (int i = 0; i < a; ++i) {
            cin >> gift;
            pq.push(gift);
        }

    }
    
    return 0;
}
