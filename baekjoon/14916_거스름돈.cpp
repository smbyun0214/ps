// https://www.acmicpc.net/problem/14916

#include <iostream>
#include <cstring>

using namespace std;

int INF = 100000;
int cache[100001];

int solve(int n) {
    if (n == 0) return 0;
    if (n < 0) return INF;
    
    int& ret = cache[n];
    if (ret != -1) return ret;
    
    return ret = min(1 + solve(n - 2), 1 + solve(n - 5));
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int n;
    cin >> n;
    
    int ret = solve(n);
    cout << (ret < INF ? ret : -1);
    
    return 0;
}
