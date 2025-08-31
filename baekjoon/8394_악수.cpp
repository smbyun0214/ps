// https://www.acmicpc.net/problem/8394

#include <iostream>
#include <cstring>

using namespace std;

int n;
char cache[10000000];

char solve(int here) {
    if (n == here) return 1;
    if (n < here) return 0;
    
    char& ret = cache[here];
    if (ret != -1) return ret;
    
    return ret = (solve(here + 2) + solve(here + 1)) % 10;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    cin >> n;
    
    for (int i = n; 0 <= i; --i) {
        solve(i);
    }
    
    cout << int(solve(0));
    
    return 0;
}
