#include <iostream>
#include <vector>

#define matrix vector<vector<int>>

using namespace std;

matrix getIdentity(int n) {
    matrix ret;
    
    for (int i = 0; i < n; ++i) {
        vector<int> row = vector<int>(n, 0);
        
        row[i] = 1;
        ret.push_back(row);
    }
    
    return ret;
}

matrix multiply(matrix & A, matrix &B) {
    matrix ret;
    
    for (int jA = 0; jA < A.size(); ++jA) {
        vector<int> row(B[0].size());
        
        for (int iB = 0; iB < B[0].size(); ++iB) {
            int tmp = 0;
            
            for (int iA = 0; iA < A[0].size(); ++iA) {
                tmp += (A[jA][iA] * B[iA][iB]);
            }
            
            row[iB] = tmp % 1000;
        }
        
        ret.push_back(row);
    }
    
    return ret;
}

matrix pow(matrix & A, long long n) {
    if (n == 1)
        return A;
    
    if (n % 2) {
        matrix tmp =  pow(A, n - 1);
        
        return multiply(A, tmp);
    }
    
    
    matrix tmp =  pow(A, n / 2);
    
    return multiply(tmp, tmp);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; long long B;
    cin >> N >> B;
    
    matrix A(N, vector<int>(N, 0));
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            cin >> A[j][i];
            A[j][i] %= 1000;
        }
    }
    
    for (vector<int> row : pow(A, B)) {
        for (int i : row)
            cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}
