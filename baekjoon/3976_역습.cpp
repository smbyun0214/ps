// https://www.acmicpc.net/problem/3976

#include <iostream>
#include <cstring>

using namespace std;

int n;

int defenders[2];           // 수비수가 스트라이커에게 긴 패스를 할 때 난이도
int strikers[2];            // 스트라이커가 슛을 할 때의 난이도
int dribbles[2][100000];    // 스트라이커가 드리블 할 때의 난이도
int passes[2][100000];      // 스트라이커가 패스 할 때의 난이도

int cache[2][100001];

int solve(int player, int step) {
    if (step == 0)
        return min(defenders[0] + solve(0, step + 1),
                   defenders[1] + solve(1, step + 1));
    if (step == n)
        return strikers[player];
    
    int& ret = cache[player][step];
    if (ret != -1) return ret;
    
    return ret = min(dribbles[player][step] + solve(player, step + 1),
               passes[player][step] + solve((player + 1) % 2, step + 1));
}

int counterattack() {
    int ret = 0;
    for (int defender = 0; defender < 2; ++defender) {
        for (int striker = 0; striker < 2; ++striker) {
            ret = min(ret, defenders[defender] + strikers[striker]);
        }
    }
    return ret;
}

int main (int argc, char *argv[]) {
    
    int testcase;
    cin >> testcase;
    
    while (testcase--) {
        memset(cache, -1, sizeof(cache));
        
        cin >> n;
        cin >> defenders[0] >> defenders[1];
        cin >> strikers[0] >> strikers[1];
        
        for (int i = 1; i < n; ++i) cin >> passes[0][i];
        for (int i = 1; i < n; ++i) cin >> dribbles[0][i];
        for (int i = 1; i < n; ++i) cin >> passes[1][i];
        for (int i = 1; i < n; ++i) cin >> dribbles[1][i];
        
        cout << solve(-1, 0) << '\n';
    }
    
    return 0;
}
