// https://codeforces.com/contest/1305/problem/A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T; cin >> T;
    
    while (T--) {
        int N; cin >> N;
        
        vector<int> necklaces(N);
        vector<int> bracelets(N);
        
        for (int i = 0; i < N; ++i) cin >> necklaces[i];
        for (int i = 0; i < N; ++i) cin >> bracelets[i];
        
        sort(necklaces.begin(), necklaces.end());
        sort(bracelets.begin(), bracelets.end());
        
        for (int i : necklaces)
            cout << i << ' ';
        cout << '\n';
        for (int i : bracelets)
            cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}
