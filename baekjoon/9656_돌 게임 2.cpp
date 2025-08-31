// https://www.acmicpc.net/problem/9656

#include <iostream>
#include <cstring>

using namespace std;

int cache[2][1001];

int game(int player, int n) {
    if (n == 1 || n == 3) return player;
    if (n == 2) return (player + 1) % 2;
    
    int& ret = cache[player][n];
    if (ret != -1) return ret;
    
    return ret = game((player + 1) % 2, n - 1) | game((player + 1) % 2, n - 3);
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int N;
    cin >> N;
    
    cout << (game(0, N) == 0 ? "CY" : "SK");
    
    return 0;
}
