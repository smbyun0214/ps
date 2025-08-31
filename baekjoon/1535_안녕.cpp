// https://www.acmicpc.net/problem/1535

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int lifes[20];
int joy[20];

int cache[20][101];

int solve(int meet, int life) {
    if (meet == N) return 0;
    
    int& ret = cache[meet][life];
    if (ret != -1)
        return ret;
    
    if (0 < life - lifes[meet])
        return ret = max(solve(meet + 1, life), joy[meet] + solve(meet + 1, life - lifes[meet]));
    
    return ret = solve(meet + 1, life);
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> lifes[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> joy[i];
    }
    
    cout << solve(0, 100);
    
    return 0;
}
