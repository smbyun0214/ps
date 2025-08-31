// https://www.acmicpc.net/problem/13706

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class BigInteger {
    
private:
    vector<int> num;
    
    void Normalize(vector<int>& num) {
        num.push_back(0);
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] < 0) {
                int borrow = (abs(num[i]) + 9) / 10;
                num[i + 1] -= borrow;
                num[i] += borrow * 10;
            }
            else {
                num[i + 1] += num[i] / 10;
                num[i] = num[i] % 10;
            }
        }
        while (num.size() > 1 && num.back() == 0) num.pop_back();
    }
    
    // -1: num > op.num
    //  0: num == op.num
    //  1: num < op.num
    int Compare(const BigInteger& op) {
        if (num.size() < op.num.size())
            return 1;
        else if (num.size() > op.num.size())
            return -1;
        
        for (int i = num.size() - 1; 0 <= i; --i) {
            if (num[i] < op.num[i])
                return 1;
            else if (num[i] > op.num[i])
                return -1;
        }
        
        return 0;
    }
    
public:
    BigInteger() {};
    
    BigInteger(const string& str) {
        for (int i = str.size() - 1; 0 <= i; --i) {
            num.push_back(str[i] - '0');
        }
    };
    
    BigInteger(vector<int>& num) : num(num) { };
    
    BigInteger(int n) {
        while (n / 10) {
            num.push_back(n % 10);
            n /= 10;
        }
        num.push_back(n);
    };

    size_t Size() {
        return num.size();
    };
    
    BigInteger operator+(int n) {
        vector<int> add(num);
        add[0] += n;
        
        Normalize(add);
        
        return BigInteger(add);
    }
    
    BigInteger operator+(const BigInteger& op) {
        size_t size = max(num.size(), op.num.size());
        vector<int> add(size + 1, 0);
        for (int i = 0; i < size; ++i) {
            if (i < num.size())
                add[i] += num[i];
            if (i < op.num.size())
                add[i] += op.num[i];
        }
        
        Normalize(add);
        
        return BigInteger(add);
    }
    
    BigInteger operator-(int n) {
        vector<int> sub(num);
        sub.push_back(0);
        sub[0] -= n;
        
        Normalize(sub);
        
        return BigInteger(sub);
    }
    
    BigInteger operator*(const BigInteger& op) {
        vector<int> mul(num.size() + op.num.size(), 0);
        for (int i = 0; i < num.size(); ++i) {
            for (int j = 0; j < op.num.size(); ++j) {
                mul[i + j] += num[i] * op.num[j];
            }
        }
        
        Normalize(mul);
        
        return BigInteger(mul);
    }
    
    BigInteger operator/(const int n) {
        vector<int> div(num);
        for (int i = num.size() - 1; 0 <= i; --i) {
            if (0 <= i - 1)
                div[i - 1] += (div[i] % n) * 10;
            div[i] /= n;
        }
        
        Normalize(div);
        
        return BigInteger(div);
    }
    
    bool operator<(const BigInteger& op) {
        if (Compare(op) == 1)
            return true;
        return false;
    }
    
    bool operator>(const BigInteger& op) {
        if (Compare(op) == -1)
            return true;
        return false;
    }
    
    bool operator==(const BigInteger& op) {
        if (Compare(op) == 0)
            return true;
        return false;
    }
    
    void print() {
        for (int i = num.size() - 1; 0 <= i; --i) {
            cout << num[i];
        }
        cout << '\n';
    }
};


int main (int argc, char *argv[]) {
    
    string N;
    cin >> N;
    
    BigInteger left(0), right(N);
    BigInteger square(N);
    
    BigInteger mid;
    while (true) {
        mid = (left + right) / 2;
        BigInteger midSquare = mid * mid;
        
        if (midSquare < square)
            left = mid + 1;
        else if (midSquare > square)
            right = mid - 1;
        else
            break;
    }
    
    mid.print();
    
    return 0;
}
