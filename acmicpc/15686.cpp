#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(int currentDistance, const vector<bool>& used, const vector<pair<int, int>>& chicken, const vector<pair<int, int>>& home) {
    int ret = 0;
    
    for (int i = 0; i < home.size(); ++i) {
        int minDist = 10000;
        
        for (int j = 0; j < used.size(); ++j) {
            if (!used[j]) continue;
            
            int dist = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
            minDist = min(minDist, dist);
        }
        
        ret += minDist;
        
        if (ret >= currentDistance)
            return ret;
    }
    
    return ret;
}

int shortestPath(int idx, int toPick, int currentDistance, vector<bool>& used,
                 const vector<pair<int, int>>& chicken, const vector<pair<int, int>>& home) {
    if (toPick == 0)
        return minDistance(currentDistance, used, chicken, home);
    
    int ret = currentDistance;
    
    for (int start = idx; start < used.size(); ++start) {
        used[start] = true;
        ret = min(ret, shortestPath(start + 1, toPick - 1, ret, used, chicken, home));
        used[start] = false;
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M;
    
    cin >> N >> M;
    
    vector<pair<int, int>> home, chicken;
    
    int type;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> type;
            
            if (type == 1)
                home.push_back(make_pair(i, j));
            else if (type == 2)
                chicken.push_back(make_pair(i, j));
        }
    }
    
    vector<bool> used(chicken.size(), false);
    
    cout << shortestPath(0, M, 100000, used, chicken, home) << '\n';
    
    return 0;
}
