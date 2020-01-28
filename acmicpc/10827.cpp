#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void normalize(vector<int> &num) {
    num.push_back(0);
    
    for (int i = 1; i < num.size(); ++i) {
        num[i] += num[i - 1] / 10;
        num[i - 1] %= 10;
    }
    
    while (num.size() > 1 && num[num.size() - 1] == 0) num.pop_back();
}

vector<int> multiply(const vector<int> &num1, const vector<int> &num2) {
    vector<int> ret(num1.size() + num2.size(), 0);
    
    for (int i = 0; i < num1.size(); ++i) {
        for (int j = 0; j < num2.size(); ++j) {
            ret[i + j] += num1[i] * num2[j];
        }
    }
    
    normalize(ret);
    
    return ret;
}

vector<int> powNumber(const vector<int> &nums, int power) {
    if (power == 1)
        return nums;
    
    if (power % 2) return multiply(nums, powNumber(nums, power - 1));
    
    vector<int> ret = powNumber(nums, power / 2);
    
    return multiply(ret, ret);
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int decimalPointCount;
    int power;
    string str;
    
    cin >> str >> power;
    
    vector<int> nums;
    
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '.')
            decimalPointCount = i;
        else
            nums.push_back(str[i] - '0');
    }
    
    decimalPointCount = nums.size() - decimalPointCount;
    decimalPointCount = power * decimalPointCount;
    
    reverse(nums.begin(), nums.end());
    
    vector<int> ret = powNumber(nums, power);
    
    reverse(ret.begin(), ret.end());
    
    if (ret.size() < decimalPointCount) {
        cout << 0 << '.';
        for (int i = 0; i < decimalPointCount - ret.size(); ++i)
            cout << 0;
        for (int i : ret)
            cout << i;
    }
    else {
        for (int i = 0; i < ret.size() - decimalPointCount; ++i)
            cout << ret[i];
        cout << '.';
        for (int i = ret.size() - decimalPointCount; i < ret.size(); ++i)
            cout << ret[i];
    }
    cout << '\n';
    
    return 0;
}
