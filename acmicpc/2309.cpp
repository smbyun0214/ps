#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dwarf[9];
bool used[9];

bool search(int start, int n, int height) {
    if (height == 0 && n == 0)
        return true;
    
    for (int i = start; i < 9; ++i) {
        if (used[i] == false) {
            used[i] = true;
            
            if (search(i + 1, n - 1, height - dwarf[i]))
                return true;
        }
        
        used[i] = false;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(used, 0, sizeof(used));

    for (int i = 0; i < 9; ++i)
        cin >> dwarf[i];

    sort(dwarf, dwarf + 9);
    
    search(0, 7, 100);
    
    for (int i = 0; i < 9; ++i) {
        if (used[i])
            cout << dwarf[i] << '\n';
    }

    return 0;
}
