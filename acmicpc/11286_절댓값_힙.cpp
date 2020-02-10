#include <iostream>
#include <queue>

using namespace std;

struct compare {
    bool operator() (const int& a, const int& b) const
    {
        if (abs(a) == abs(b))
            return a > b;
        
        return abs(a) > abs(b);
    }
};

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; int n;
    cin >> N;
    
    priority_queue<int, vector<int>, compare> cache;
    
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
