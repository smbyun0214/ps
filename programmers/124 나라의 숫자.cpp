#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string digit124(int n) {
    if (n == 1)
        return "1";
    
    n -= 1;
    string ret = "";

    while (0 <= n) {
        if (n % 3 == 0) {
            ret += '1';
        }
        else if (n % 3 == 1) {
            ret += '2';
        }
        else if (n % 3 == 2) {
            ret += '4';
        }
        
        n /= 3;
        n -= 1;
    }
    
    reverse(ret.begin(), ret.end());
    
    return ret;
}

string solution(int n) {    
    return digit124(n);
}