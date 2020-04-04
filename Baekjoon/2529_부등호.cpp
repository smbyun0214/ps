#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int adjacent[10][10];
vector<bool> seen;
vector<char> sign;
vector<vector<int>> orders;

void dfs(int here, vector<int>& order, const vector<char>::iterator iter) {
    if (iter == sign.end()) {
        if (order.size() == sign.size() ) {
            order.push_back(here);
            orders.push_back(order);
            order.pop_back();
        }
        
        return;
    }
    
    seen[here] = true;
    
    for (int there = 0; there < seen.size(); ++there) {
        if (!seen[there] && ((*iter == '<' && adjacent[here][there]) || (*iter == '>' && adjacent[there][here]))) {
            order.push_back(here);
            
            dfs(there, order, iter + 1);
            
            order.pop_back();
        }
    }
    
    seen[here] = false;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i < j) adjacent[i][j] = 1;
        }
    }
    
    int K; cin >> K;
    
    seen = vector<bool>(10, false);
    sign = vector<char>(K);
    
    for (int i = 0; i < K; ++i) cin >> sign[i];
    
    vector<int> order;
    for (int i = 0; i < 10; ++i) {
        if (!seen[i])
            dfs(i, order, sign.begin());
    }
    
    for (int i : orders[orders.size() - 1])
        cout << i;
    cout << '\n';
    
    for (int i : orders[0])
        cout << i;
    cout << '\n';
    
    return 0;
}
