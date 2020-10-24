#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<int> weights;
    vector<pair<int, int>> cars;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> parkingLot;
    queue<int> waiting;
    
    int T; cin >> T;
    
    int N, M, price, idx, ret;
    
    for (int t = 1; t <= T; ++t) {
        weights.clear();
        cars.clear();
        while (!parkingLot.empty()) parkingLot.pop();
        while (!waiting.empty()) waiting.pop();
        
        ret = 0;
        
        cin >> N >> M;
        
        for (int n = 0; n < N; ++n) {
            cin >> price;
            parkingLot.push(make_pair(n, price));
        }
        
        weights.resize(M + 1);
        cars.resize(M + 1);
        
        for (int m = 1; m <= M; ++m) cin >> weights[m];
        
        for (int m = 0; m < 2 * M; ++m) {
            cin >> idx;
            
            if (idx > 0)
                waiting.push(idx);
            else {
                ret += weights[-idx] * cars[-idx].second;
                parkingLot.push(cars[-idx]);
            }

            while (!waiting.empty() && !parkingLot.empty()) {
                cars[waiting.front()] = parkingLot.top();
                waiting.pop();
                parkingLot.pop();
            }
        }
        
        cout << '#' << t << ' ' << ret << '\n';
    }
    
    return 0;
}
