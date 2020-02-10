#include <iostream>
#include <vector>

using namespace std;

int K;

void print(const vector<int>& picked) {
    for (int i : picked) {
        cout << i << ' ';
    }
    
    cout << '\n';
}

void candidate(int next, vector<int>& picked, const vector<int>& set) {
    if (picked.size() == 6) {
        print(picked);
        return;
    }
    
    for (int i = next; i < K; ++i) {
        picked.push_back(set[i]);
        candidate(i + 1, picked, set);
        picked.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    while (true) {
        cin >> K;
        
        if (K == 0)
            break;
        
        vector<int> set(K);
        vector<int> picked;
        
        for (int i = 0; i < K; ++i)
            cin >> set[i];
        
        candidate(0, picked, set);
        
        cout << '\n';
    }
    
    return 0;
}
