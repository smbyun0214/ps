#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int T; cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N, budget;
        cin >> N >> budget;
        
        vector<int> costs(N);
        for (int i = 0; i < N; ++i)
            cin >> costs[i];
        
        sort(costs.begin(), costs.end());
        
        int cnt = 0;
        for (cnt = 0; cnt < N; ++cnt) {
            if (budget < costs[cnt])
                break;
            budget -= costs[cnt];
        }
        
        cout << "Case #" << t << ": " << cnt << '\n';
    }
    
    return 0;
}
