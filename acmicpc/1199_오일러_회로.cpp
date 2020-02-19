#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getEulerCircuit(int here, vector<vector<int>> &adjacent, vector<int> &circuit) {
    
    for (int there = 0; there < adjacent[here].size(); ++there) {
        if (adjacent[here][there]) {
            --adjacent[here][there];
            --adjacent[there][here];
            getEulerCircuit(there, adjacent, circuit);
        }
    }
    
    circuit.push_back(here + 1);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    
    vector<vector<int>> adjacent(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; ++i) {
        int degree = 0;
        for (int j = 0; j < N; ++j) {
            cin >> adjacent[i][j];
            degree += adjacent[i][j];
        }
        
        if (degree % 2) {
            cout << -1 << '\n';
            return 0;
        }
    }
    
    vector<int> circuit;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (adjacent[i][j]) {
                getEulerCircuit(i, adjacent, circuit);
                break;
            }
        }
    }
    
    reverse(circuit.begin(), circuit.end());
    
    for (int i : circuit) {
        cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}

