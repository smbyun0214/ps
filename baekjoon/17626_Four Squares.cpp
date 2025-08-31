// https://www.acmicpc.net/problem/17626

#include <iostream>
#include <cstring>

using namespace std;

int INF = 50001;
int cache[50001];

int solve(int n) {
    if (n == 0) return 0;
    
    int& ret = cache[n];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int div = 1; div * div <= n; ++div) {
        ret = min(ret, 1 + solve(n - div * div));
    }
    
    return ret;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int n;
    cin >> n;
    
    cout << solve(n, 1);
    
    return 0;
}
