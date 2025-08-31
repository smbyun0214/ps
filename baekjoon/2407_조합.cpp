// https://www.acmicpc.net/problem/2407

#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int> > > cache(101, vector<vector<int> >(101, vector<int>(1, -1)));

void normalize(vector<int>& A) {
    A.push_back(0);
    
    for (int i = 0; i < A.size(); ++i) {
        if (10 <= A[i]) {
            A[i + 1] += A[i] / 10;
            A[i] %= 10;
        }
    }
    
    while (A.size() > 1 && A.back() == 0) A.pop_back();
}

vector<int> add(vector<int>& A, vector<int>& B) {
    if (A.size() < B.size())
        swap(A, B);
    
    for (int i = 0; i < B.size(); ++i) {
        A[i] += B[i];
    }
    
    normalize(A);
    
    return A;
}

vector<int> solve(int n, int m) {
    if (n == m || m == 0) return vector<int>(1, 1);
    
    vector<int>& ret = cache[n][m];
    if (ret[0] != -1) return ret;
    
    vector<int> A = solve(n - 1, m);
    vector<int> B = solve(n - 1, m - 1);
    return ret = add(A, B);
}

int main (int argc, char *argv[]) {
    
    int n, m;
    cin >> n >> m;

    vector<int> ret = solve(n, m);

    for (int i = ret.size() - 1; 0 <= i; --i) {
        cout << ret[i];
    }
    
    return 0;
}
