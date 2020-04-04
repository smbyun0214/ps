#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[51][1501];

int maximum(int row, int rem, const vector<vector<int> > &psum) {
    if (row == psum.size())
        return 0;
    
    int &ret = cache[row][rem];
    if (ret != -1)
        return ret;
    
    ret = 0;
    
    for (int col = 0; col < psum[row].size() && col <= rem; ++col) {
        ret = max(ret, psum[row][col] + maximum(row + 1, rem - col, psum));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    int T; cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        memset(cache, -1, sizeof(cache));
        
        int N, K, P;
        cin >> N >> K >> P;
        
        vector<vector<int> > psum(N, vector<int>(K + 1, 0));
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < K; ++j) {
                cin >> psum[i][j + 1];
                psum[i][j + 1] = psum[i][j] + psum[i][j + 1];
            }
        }
        
        cout << "Case #" << t << ": " << maximum(0, P, psum) << '\n';
    }
    
    return 0;
}
