#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    
    int position, destination, oil;
    vector<pair<int, int>> stations;
    
    while (N--) {
        cin >> position >> oil;
        stations.push_back(make_pair(position, oil));
    }
    sort(stations.begin(), stations.end());
    
    cin >> destination >> oil;
    
    int ret = 0;
    vector<pair<int, int>>::iterator it = stations.begin();
    priority_queue<int> candOils;
    
    while (oil < destination) {
        while (it != stations.end() && it->first <= oil) {
            candOils.push(it->second);
            ++it;
        }
        
        if (candOils.empty()) {
            ret = -1;
            break;
        }
        
        oil += candOils.top(); candOils.pop();
        
        ++ret;
    }
    
    cout << ret << '\n';
    
    return 0;
}
