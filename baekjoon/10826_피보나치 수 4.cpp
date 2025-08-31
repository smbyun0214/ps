// https://www.acmicpc.net/problem/10826

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache(10001, vector<int>(1, -1));

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

vector<int> add(vector<int>& a, vector<int>& b) {
    if (a.size() < b.size())
        return add(b, a);
    
    while (a.size() > b.size()) b.push_back(0);
    
    vector<int> c(a.size() + 1, 0);
    for (int i = 0; i < a.size(); ++i) {
        c[i] = a[i] + b[i];
    }
    
    normalize(c);
    
    return c;
}

vector<int> solve(int n) {
    if (n == 0) return vector<int>(1, 0);
    if (n == 1 || n == 2) return vector<int>(1, 1);
    
    vector<int>& ret = cache[n];
    if (ret[0] != -1) return ret;
    
    vector<int> a = solve(n - 1);
    vector<int> b = solve(n - 2);
    return ret = add(a, b);
}

int main (int argc, char *argv[]) {
    
    int n;
    cin >> n;
    
    vector<int> ret = solve(n);
    for (int i = ret.size() - 1; 0 <= i; --i) {
        cout << ret[i];
    }
    
    return 0;
}
