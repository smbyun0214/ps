#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, n;
    cin >> N;
    
    priority_queue<int> periods;
    
    while (N--) {
        cin >> n;
        periods.push(n);
    }
    
    int ret = 1, period = 0;
    while (!periods.empty()) {
        period = max(period - 1, periods.top());
        periods.pop();
        
        ++ret;
    }
    
    cout << ret + period << '\n';
    
    return 0;
}
