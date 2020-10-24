#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T; cin >> T;
    
    int ret = 0;
    int N, maxWeight;
    vector<int> bags;
    
    for (int t = 1; t <= T; ++t) {
        ret = -1;
        bags.clear();
        
        cin >> N >> maxWeight;
        
        bags.resize(N);
        
        for (int i = 0; i < N; ++i) cin >> bags[i];
        
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (ret < (bags[i] + bags[j]) && (bags[i] + bags[j]) <= maxWeight)
                    ret = (bags[i] + bags[j]);
            }
        }
        
        cout << '#' << t << ' ' << ret << '\n';
    }
    
    return 0;
}
