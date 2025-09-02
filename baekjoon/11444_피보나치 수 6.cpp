// https://www.acmicpc.net/problem/11444

#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1000000007;

vector<vector<long long> > fiboMatrix = {
    {1, 1},
    {1, 0}
};

vector<vector<long long> > identity = {
    {1, 0},
    {0, 1}
};

vector<vector<long long> > multiply(const vector<vector<long long> >& A, const vector<vector<long long> >& B) {
    vector<vector<long long> > newMatrix = {
        {0, 0},
        {0, 0}
    };

    newMatrix[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    newMatrix[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    newMatrix[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    newMatrix[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

    newMatrix[0][0] %= MOD;
    newMatrix[0][1] %= MOD;
    newMatrix[1][0] %= MOD;
    newMatrix[1][1] %= MOD;

    return newMatrix;
};

vector<vector<long long> > pow(vector<vector<long long> > matrix, long long m) {
    if (m == 0) {
        return identity;
    }

    if (m % 2 == 1) {
        return multiply(pow(matrix, m - 1), matrix);
    }

    vector<vector<long long> > half = pow(matrix, m / 2);
    return multiply(half, half);
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long n;
    cin >> n;

    vector<vector<long long> > ret = pow(fiboMatrix, n);
    cout << ret[0][1] << '\n';
    
    return 0;
}
