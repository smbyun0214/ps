#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const long long INF = 9876543210;

long long cache[500][500];

long long cost(int start, int end, const vector<pair<int, int> > &matrices) {
    if (start == end)
        return 0;
    if (end == start + 1)
        return matrices[start].first * matrices[start].second * matrices[end].second;
    
    long long &ret = cache[start][end];
    if (ret != -1)
        return ret;
    
    ret = INF;
    
    for (int mid = start; mid < matrices.size(); ++mid) {
        ret = min(ret, cost(start, mid, matrices) + cost(mid + 1, end, matrices) + matrices[start].first * matrices[mid].second * matrices[end].second);
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N;
    cin >> N;
    
    vector<pair<int, int> > matrices(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> matrices[i].first >> matrices[i].second;
    }
    
    cout << cost(0, matrices.size() - 1, matrices) << '\n';
    
    return 0;
}
