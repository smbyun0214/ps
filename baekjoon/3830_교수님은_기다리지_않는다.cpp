#include <iostream>
#include <climits>
#include <cstring>
#include <map>

#define ll long long

using namespace std;

const ll INF = LLONG_MAX;

int treeNo[100001];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M, a, b, weight;
    char command;
    
    map<int, ll> samples;
    
    while (true) {
        cin >> N >> M;
        
        if (N == 0 && M == 0)
            break;
        
        samples.clear();
        memset(treeNo, -1, sizeof(treeNo));
        
        int no = 0;
        
        while (M--) {
            cin >> command;
            
            switch (command) {
                case '!': {
                    cin >> a >> b >> weight;

                    if (samples.find(a) == samples.end()) samples[a] = INF;
                    if (samples.find(b) == samples.end()) samples[b] = INF;
                    
                    int &treeNoA = treeNo[a], &treeNoB = treeNo[b];
                    ll &weightA = samples[a], &weightB = samples[b];
                    
                    if (treeNoA == -1 && treeNoB == -1) {
                        treeNoA = treeNoB = no++;
                        
                        weightA = 0;
                        weightB = weightA + weight;
                    }
                    else if (treeNoA == -1) {
                        treeNoA = treeNoB;
                        weightA = weightB - weight;
                    }
                    else if (treeNoB == -1) {
                        treeNoB = treeNoA;
                        weightB = weightA + weight;
                    }
                    else {
                        ll diff = weightA + weight - weightB;
                        
                        for (int i = 1, no = treeNoB; i <= N; ++i) {
                            if (treeNo[i] == no) {
                                samples[i] += diff;
                                treeNo[i] = treeNoA;
                            }
                        }
                    }
                    
                    break;
                }

                case '?': {
                    cin >> a >> b;

                    if (samples.find(a) == samples.end()) samples[a] = INF;
                    if (samples.find(b) == samples.end()) samples[b] = INF;
                    
                    int &treeNoA = treeNo[a], &treeNoB = treeNo[b];
                    const ll &weightA = samples[a], &weightB = samples[b];
                    
                    if (treeNoA != treeNoB || (treeNoA == -1 || treeNoB == -1))
                        cout << "UNKNOWN" << '\n';
                    else
                        cout << weightB - weightA << '\n';
                    
                    break;
                }
            }
        }
        
    }
    
    return 0;
}
