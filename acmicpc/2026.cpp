#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;

bool areFriends[901][901];

bool arePairings(vector<bool>& taken, int lastFree, int remainder) {
    for (int i = 1; i < lastFree; ++i) {
        if (taken[i] && !areFriends[i][lastFree])
            return false;
    }
    
    if (remainder == 0) return true;
    
    for (int pairWith = lastFree + 1; pairWith <= N; ++pairWith) {
        if (!taken[pairWith] && areFriends[lastFree][pairWith]) {
            taken[pairWith] = true;
            
            if (arePairings(taken, pairWith, remainder - 1))
                return true;
            
            taken[pairWith] = false;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(areFriends, 0, sizeof(areFriends));
    for (int i = 0; i < 901; ++i)
        areFriends[0][i] = areFriends[i][0] = true;
    
    int K, F, i, j;
    
    cin >> K >> N >> F;
    
    vector<bool> taken(N + 1, false);
    
    while (F--) {
        cin >> i >> j;
        areFriends[i][j] = areFriends[j][i] = true;
    }
    
    taken[0] = true;
    
    if (arePairings(taken, 0, K)) {
        for (int i = 1; i <= N; ++i) {
            if (taken[i])
                cout << i << '\n';
        }
    }
    else
        cout << -1 << '\n';

    return 0;
}
