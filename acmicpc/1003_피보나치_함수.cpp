#include <iostream>

using namespace std;

int cache[41], zeros[41], ones[41];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cache[0] = 0; cache[1] = 1;
    zeros[0] = 1; zeros[1] = 0;
    ones[0] = 0; ones[1] = 1;
    
    for (int i = 2; i < 41; ++i) {
        cache[i] = cache[i - 1] + cache[i - 2];
        zeros[i] = zeros[i - 1] + zeros[i - 2];
        ones[i] = ones[i - 1] + ones[i - 2];
    }
    
    int T, n;
    cin >> T;
    
    while (T-- > 0) {
        cin >> n;
        
        cout << zeros[n] << ' ' << ones[n] << '\n';
    }
    
    return 0;
}
