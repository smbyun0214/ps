#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int prior[11];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(prior, 0, sizeof(prior));
    
    int T, N, M, p;
    cin >> T;
    
    int ret, idx;
    queue<pair<int, int>> cache;
    
    while (T-- > 0) {
        ret = idx = 0;
        
        cin >> N >> M;
        
        for (int i = 0; i < N; ++i) {
            cin >> p;
            
            ++prior[p];
            idx = max(idx, p);
            
            cache.push(make_pair(i, p));
        }
        
        while (true) {
            pair<int, int> info = cache.front();
            
            if (info.first == M && info.second == idx)
                break;
            
            if (info.second == idx) {
                ++ret;
                --prior[idx];
            }
            else
                cache.push(info);
            
            cache.pop();
            
            while (prior[idx] == 0) --idx;
        }
        
        cout << ret + 1 << '\n';
        
        while (!cache.empty()) cache.pop();
        memset(prior, 0, sizeof(prior));
    }
    
    return 0;
}
