// https://www.acmicpc.net/problem/15624

#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int cache[1000001];

int solve(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int& ret = cache[n];
    if (ret != -1) return ret;
    
    return ret = (solve(n - 1) + solve(n - 2)) % MOD;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        solve(i);
    }
    
    cout << solve(n);
    
    return 0;
}
