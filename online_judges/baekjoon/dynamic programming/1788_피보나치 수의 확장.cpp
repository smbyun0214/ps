// https://www.acmicpc.net/problem/1788

#include <iostream>

using namespace std;

const int MOD = 1000000000;
const int BASELINE = 1000000;

int cache[2000001];

int solve(int n, bool reversed = false) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int& ret = cache[n + 1000000];
    if (ret != MOD) return ret;
    
    if (reversed) {
        int revRet = solve(n + 2) - solve(n + 1);
        return ret = (revRet < 0 ? -(abs(revRet) % MOD) : revRet % MOD);
    }
        
    return ret = (solve(n - 1) + solve(n - 2)) % MOD;
}

int main (int argc, char *argv[]) {
    for (int i = 0; i < 2 * BASELINE + 1; ++i) {
        cache[i] = MOD;
    }
    
    for (int i = 0; i < BASELINE + 1; ++i) {
        solve(i);
        solve(-i, true);
    }
    
    int n;
    cin >> n;
    
    bool reversed = cache[n + BASELINE] > 0 ? true : false;
    int ret = solve(n, reversed);
    
    cout << (ret == 0 ? 0 : (ret > 0 ? 1 : -1))  << '\n';
    cout << abs(ret);
    
    return 0;
}
