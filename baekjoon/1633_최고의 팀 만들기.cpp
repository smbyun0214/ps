// https://www.acmicpc.net/problem/1633

#include <iostream>
#include <cstring>

using namespace std;

int N = 0;
int ability[2][1001];

int cache[16][16][1001];

int solve(int player, int black, int white) {
    if (player == N)
        return 0;
    
    int& ret = cache[black][white][player];
    if (ret != -1) return ret;
    
    ret = solve(player + 1, black, white);
    
    if (black != 0)
        ret = max(ret, ability[0][player] + solve(player + 1, black - 1, white));
    if (white != 0)
        ret = max(ret, ability[1][player] + solve(player + 1, black, white - 1));
    
    return ret;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    while (!cin.eof()) {
        cin >> ability[0][N] >> ability[1][N];
        ++N;
    }
    
    cout << solve(0, 15, 15);
    
    return 0;
}
