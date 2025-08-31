// https://www.acmicpc.net/problem/9657

#include <iostream>
#include <cstring>

using namespace std;

const int WIN = 1;
const int LOSE = 0;

int cache[2][1001];

int solve(int player, int stones) {
    if (stones == 1 || stones == 3 || stones == 4)
        return WIN;
    
    int& ret = cache[player][stones];
    if (ret != -1) return ret;
    
    ret = LOSE;
    
    for (int pick = 1; pick <= 4; ++pick) {
        if (pick == 2 || stones - pick < 0) continue;
        int cand = solve((player + 1) % 2, stones - pick) == WIN ? LOSE : WIN;
        ret |= cand;
    }
    
    return ret;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int stones;
    cin >> stones;
    
    cout << (solve(0, stones) == 1 ? "SK" : "CY");
    
    return 0;
}
