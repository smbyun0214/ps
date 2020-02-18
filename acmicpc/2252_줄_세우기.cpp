#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<bool> seen;
vector<list<int>> adjacent;
vector<int> order;

void dfs(int here) {
    seen[here] = true;
    
    if (here < adjacent.size()) {
        for (int there : adjacent[here]) {
            if (!seen[there])
                dfs(there);
        }
    }
    
    order.push_back(here);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    seen = vector<bool>(N + 1, false);
    adjacent = vector<list<int>>(N + 1);
    
    int A, B;
    
    while (M--) {
        cin >> A >> B;
        adjacent[A].push_back(B);
    }
    
    for (int i = 1; i <= N; ++i) { if (!seen[i]) dfs(i); }
    
    reverse(order.begin(), order.end());
    
    for (int i : order) {
        cout << i << ' ';
    }
    
    return 0;
}
