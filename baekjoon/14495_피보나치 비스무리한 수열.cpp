// https://www.acmicpc.net/problem/14495

#include <iostream>
#include <cstring>

using namespace std;

long long cache[117];

long long solve(int n) {
    if (n == 1 || n == 2 || n == 3) return 1;
    
    long long& ret = cache[n];
    if (ret != -1) return ret;
    
    return ret = solve(n - 1) + solve(n - 3);
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int n = 0;
    cin >> n;
    
    cout << solve(n);
    
    return 0;
}
