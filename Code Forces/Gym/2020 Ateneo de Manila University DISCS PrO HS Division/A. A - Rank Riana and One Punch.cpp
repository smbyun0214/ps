// https://codeforces.com/gym/102556/problem/A
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string spaces;
    cin >> spaces;
    
    int enemies = 0, empty = 0, maxEmpty = 0;
    
    int idx = -1;
    for (int i = 0; i < spaces.size(); ++i)
        if (spaces[i] == 'X') {
            idx = i;
            break;
        }
    
    if (idx == -1) {
        cout << 0 << '\n';
        return 0;
    }
    
    for (int i = 0; i < spaces.size(); ++i) {
        if (spaces[(idx + i) % spaces.size()] == 'X') {
            ++enemies;
            maxEmpty = max(maxEmpty, empty);
            empty = 0;
        }
        else
            ++empty;
    }
    
    maxEmpty = max(maxEmpty, empty);
    
    cout << spaces.size() - maxEmpty - enemies << '\n';
    
    return 0;
}
