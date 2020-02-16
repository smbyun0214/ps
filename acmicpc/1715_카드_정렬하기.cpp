#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, n;
    cin >> N;

    int size = N;
    priority_queue<int, vector<int>, greater<int>> cache;

    while (N--) {
        cin >> n;
        cache.push(n);
    }
    
    int ret = 0;
    while (size > 1) {
        int first = cache.top(); cache.pop();
        int second = cache.top(); cache.pop();
        
        ret += (first + second);
        
        cache.push(first + second);
        --size;
    }
    
    cout << ret << '\n';
    
    return 0;
}
