#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    long long n;
    cin >> n;
    
    if (n <= 1) {
        if (n == 0)
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
        
        return 0;
    }
    
    int mod = 1000000;
    
    vector<int> cache(15 * mod / 10, -1);
    
    cache[0] = 0;
    cache[1] = 1;
    
    for (long long i = 1; i < n; ++i) {
        if (i + 1 >= cache.size() || cache[i + 1] != -1)
            break;
        
        cache[i + 1] = (cache[i - 1] + cache[i]) % mod;
    }
    
    cout << cache[n % cache.size()] << '\n';
    
    return 0;
}
