#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool setSchedule(priority_queue<pair<int, int> > &pq, map<pair<int, int>, char> &m) {
    priority_queue<pair<int, int> > pq2;
    
    m[pq.top()] = 'J';
    
    pair<int, int> J = pq.top();
    int JStart = J.second;
    
    pq.pop();
    
    while (!pq.empty()) {
        pair<int, int> candi = pq.top();
        pq.pop();
        
        int start = candi.second;
        int end = candi.first;
        
        if (JStart >= end) {
            m[candi] = 'J';
            JStart = start;
        }
        else
            pq2.push(candi);
    }
    
    if (pq2.empty()) return true;
    
    
    m[pq2.top()] = 'C';
    
    pair<int, int> C = pq2.top();
    int CStart = C.second;
    
    pq2.pop();

    while (!pq2.empty()) {
        pair<int, int> candi = pq2.top();
        pq2.pop();
        
        int start = candi.second;
        int end = candi.first;
        
        if (CStart >= end) {
            m[candi] = 'C';
            CStart = start;
        }
        else
            return false;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    int T; cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        
        map<pair<int, int>, char> m;
        priority_queue<pair<int, int>> pq;
        
        vector<pair<int, int> > schedule(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> schedule[i].second >> schedule[i].first;
            pq.push(schedule[i]);
        }
        
        string ret = "IMPOSSIBLE";
        if (setSchedule(pq, m)) {
            ret = "";
            for (pair<int, int> p : schedule) {
                int parent = m[p];
                ret += parent;
                m[p] = (parent == 'J' ? 'C' : 'J');
            }
        }
        
        cout << "Case #" << t << ": " << ret << '\n';
    }
    
    return 0;
}
