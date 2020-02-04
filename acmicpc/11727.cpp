#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 10007;

int cache[1001];

int tiling(int width) {
    if (width <= 1)
        return 1;
    
    int &ret = cache[width];
    if (ret != -1)
        return ret;
    
    return ret = (tiling(width - 1) + (2 * tiling(width - 2))) % MOD;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N;
    cin >> N;
    
    cout << tiling(N) << '\n';
    
    return 0;
}
