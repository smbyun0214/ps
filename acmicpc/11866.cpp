#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, Kth;
    cin >> N >> Kth;
    
    queue<int> cache;
    vector<int> ret;
    
    for (int i = 1; i <= N; ++i)
        cache.push(i);
    
    while (!cache.empty()) {
        for (int i = 0; i < Kth - 1; ++i) {
            cache.push(cache.front());
            cache.pop();
        }
        
        ret.push_back(cache.front());
        cache.pop();
    }
    
    cout << '<';
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i];
        if (i == ret.size() - 1)
            break;
        
        cout << ", ";
    }
    cout << '>' << '\n';
    
    return 0;
}
