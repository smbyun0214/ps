// https://www.acmicpc.net/problem/14675

#include <iostream>

using namespace std;

int degree[100001];

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    int u, v;
    while(--N) {
        cin >> u >> v;
        degree[u] += 1;
        degree[v] += 1;
    }

    int q, t, k;
    cin >> q;

    while(q--) {
        cin >> t >> k;
        if (t == 1) {
            cout << (degree[k] > 1 ? "yes" : "no") << '\n';
        }
        else {
            cout << "yes" << '\n';
        }
    }
    
    return 0;
}
