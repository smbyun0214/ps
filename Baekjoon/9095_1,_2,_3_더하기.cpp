#include <iostream>
#include <cstring>

using namespace std;

int cache[11];

int add123(int n) {
    if (n < 0) return 0;
    
    int &ret = cache[n];
    
    if (ret != -1)
        return ret;
    
    return ret = add123(n - 1) + add123(n - 2) + add123(n - 3);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    cache[0] = 1;
    cache[1] = 1;
    
    add123(10);
    
    int T, n;
    cin >> T;
    
    while (T--) {
        cin >> n;    
        cout << cache[n] << '\n';
    }
    
    return 0;
}
