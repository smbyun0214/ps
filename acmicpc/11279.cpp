#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; uint n;
    cin >> N;
    
    priority_queue<uint> cache;
    
    while (N--) {
        cin >> n;
        
        if (n == 0) {
            if (cache.empty())
                cout << 0 << '\n';
            else {
                cout << cache.top() << '\n';
                cache.pop();
            }
            
            continue;
        }
        
        cache.push(n);
    }
    
    return 0;
}
