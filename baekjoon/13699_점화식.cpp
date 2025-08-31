// https://www.acmicpc.net/problem/13699

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(36, vector<int>(1, -1));

void normalize(vector<int>& num) {
    num.push_back(0);
    
    for (int i = 0; i < num.size(); ++i) {
        if (10 <= num[i]) {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    
    while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j];
        }
    }
    
    normalize(c);
    
    return c;
}

vector<int> add(vector<int>& a, vector<int>& b) {
    if (a.size() < b.size())
        return add(b, a);
    
    while (a.size() > b.size()) b.push_back(0);
    
    vector<int> c(a.size() + 1);
    
    for (int i = 0; i < a.size(); ++i) {
        c[i] = a[i] + b[i];
    }
    
    normalize(c);
    
    return c;
}

vector<int> solve(int n) {
    if (n == 0) return vector<int>(1, 1);
    
    vector<int>& ret = cache[n];
    if (ret[0] != -1) return ret;
    
    ret = vector<int>(1, 0);
    
    for (int i = 0; i < n; ++i) {
        vector<int> a = solve(i);
        vector<int> b = solve(n - 1 - i);
        vector<int> mul = multiply(a, b);
        ret = add(ret, mul);
    }
    
    return ret;
}

int main (int argc, char *argv[]) {
    
    int n;
    cin >> n;
    
    vector<int> ret = solve(n);
    for (int j = ret.size() - 1; 0 <= j; --j) {
        cout << ret[j];
    }
    
    return 0;
}
