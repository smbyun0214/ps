#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N;
int board[20][20];

int calcAbility(const vector<bool>& used, bool flag) {
    int ability = 0;
    
    for (int i = 0; i < N; ++i) {
        if (used[i] != flag) continue;
        
        for (int j = i + 1; j < N; ++j) {
            if (used[j] != flag) continue;
            
            ability += board[i][j] + board[j][i];
        }
    }
    
    return ability;
}

int minTeamAbility(int start, vector<bool> &used, int size) {
    if (size == 0)
        return abs(calcAbility(used, false) - calcAbility(used, true));
    if (start == N)
        return INF;
    
    int ret = INF;
    
    for (int i = start; i < N; ++i) {
        used[i] = true;
        ret = min(ret, minTeamAbility(i + 1, used, size - 1));
        used[i] = false;
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    
    vector<bool> used(N, false);
    
    int ret = INF;
    
    for (int i = 0; i < N / 2; ++i) {
        ret = min(ret, minTeamAbility(i, used, N / 2));
    }
    
    cout << ret << '\n';
    
    return 0;
}
