#include <iostream>
#include <cstring>

using namespace std;

bool cache[101];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, false, sizeof(cache));
    
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (j % i == 0)
                cache[j] = !cache[j];
        }
    }
    
    int T; cin >> T;
    
    while (T--) {
        int N; cin >> N;
        
        int ret = 0;
        for (int i = 1; i <= N; ++i)
            if (cache[i])
                ++ret;
        
        cout << ret << '\n';
    }
    
    return 0;
}
