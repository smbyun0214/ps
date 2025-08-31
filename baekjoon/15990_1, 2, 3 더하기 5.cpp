// https://www.acmicpc.net/problem/15990

#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000009;

int cache[5][100001];

int solve(int n, int used) {
    if (n == 0) return 1;
    
    int& ret = cache[used + 1][n];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int i = 1; i <= 3; ++i) {
        if (used == -1 || (i != used && 0 <= n - i)) {
            ret = (ret + solve(n - i, i)) % MOD;
        }
    }
    
    return ret ;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int testcase, n;
    cin >> testcase;
    
    while (testcase--) {
        cin >> n;
        cout << solve(n, -1) << '\n';
    }
    
    return 0;
}
