#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int T; cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N, K;
        cin >> N >> K;
        
        vector<int> fitness(N);
        vector<int> sub(N - 1);
        
        for (int i = 0; i < N; ++i)
            cin >> fitness[i];
        
        for (int i = 1; i < N; ++i)
            sub[i - 1] = -(fitness[i] - fitness[i - 1]);
        
        sort(sub.begin(), sub.end());
        
        for (int i = 0; i < N - 1; ++i) {
            int sub
            if (sub[i])
        }
        
        
        cout << "Case #" << t << ": " << maximum(0, P, psum) << '\n';
    }
    
    return 0;
}
