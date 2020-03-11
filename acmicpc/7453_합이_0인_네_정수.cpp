#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    
    vector<int> A(N), B(N), C(N), D(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    vector<int> AB(N * N), CD(N * N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            AB[i * N + j] = A[i] + B[j];
            CD[i * N + j] = C[i] + D[j];
        }
    }
    
    sort(CD.begin(), CD.end());
    
    long long ret = 0;
    
    for (int i = 0; i < N * N; ++i) {
        ret += (upper_bound(CD.begin(), CD.end(), -AB[i]) - lower_bound(CD.begin(), CD.end(), -AB[i]));
    }
    
    cout << ret << '\n';
    
    return 0;
}
