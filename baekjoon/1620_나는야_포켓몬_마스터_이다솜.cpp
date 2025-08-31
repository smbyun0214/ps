#include <iostream>
#include <map>
#include <string>

using namespace std;

bool inInteger(char c) {
    return '0' <= c && c <= '9';
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M;
    string name;
    
    cin >> N >> M;
    
    map<int, string> idx2Name;
    map<string, int> name2Idx;
    
    for (int i = 1; i <= N; ++i) {
        cin >> name;
    
        idx2Name[i] = name;
        name2Idx[name] = i;
    }
    
    while (M--) {
        cin >> name;
        
        if (inInteger(name[0])) {
            int num = stoi(name);
            cout << idx2Name[num] << '\n';
        }
        else {
            cout << name2Idx[name] << '\n';
        }
    }
    
    return 0;
}
