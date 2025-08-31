#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 9901;

int cache[100001][2];

int zoo(int height, int isNeighbor) {
    if (height <= 0) return 1;
    
    int &ret = cache[height][isNeighbor];
    if (ret != -1)
        return ret;
    
    if (isNeighbor)
        ret = (zoo(height - 1, 0) + zoo(height - 1, 1)) % MOD;
    else
        ret = (zoo(height - 1, 0) + 2 * zoo(height - 1, 1)) % MOD;
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N; cin >> N;
    
    cout << zoo(N, false) << '\n';

    return 0;
}
