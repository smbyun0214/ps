#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    vector<vector<int>> ret(A.size(), vector<int>(B[0].size(), 0));
    
    for (int jA = 0; jA < A.size(); ++jA) {
        for (int iB = 0; iB < B[0].size(); ++iB) {
            int &tmp = ret[jA][iB];

            for (int iA = 0; iA < A[0].size(); ++iA) {
                tmp += (A[jA][iA] * B[iA][iB]);
            }
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M;
    
    cin >> N >> M;
    vector<vector<int>> A(N);
    for (int j = 0; j < N; ++j) {
        vector<int> row(M);
        for (int i = 0; i < M; ++i) {
            cin >> row[i];
        }
        A[j] = row;
    }
    
    cin >> N >> M;
    vector<vector<int>> B(N);
    for (int j = 0; j < N; ++j) {
        vector<int> row(M);
        for (int i = 0; i < M; ++i) {
            cin >> row[i];
        }
        B[j] = row;
    }
    
    for (vector<int> row : multiply(A, B)) {
        for (int i : row)
            cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}
