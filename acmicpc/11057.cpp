#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 10007;
int N;
int cache[11][1001];

int countUphill(int stair, int n) {
    if (n == 0)
        return 1;
    
    if (stair == -1)
        return countUphill(stair + 1, n);
    
    int &ret = cache[stair + 1][n];
    
    if (ret != -1)
        return ret;
    
    ret = 0;
    
    for (int i = 0; stair + i < 10; ++i) {
        ret += (countUphill(stair + i, n - 1) % MOD);
    }
    
    return ret % MOD;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    
    cout << countUphill(-1, N) << '\n';
    
    return 0;
}
