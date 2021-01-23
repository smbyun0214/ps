#include <string>
#include <algorithm>

using namespace std;

string base3Reversed(int n) {
    string ret = "";
    while (n != 0) {
        ret.push_back(n % 3 + '0');
        n /= 3;
    }

    reverse(ret.begin(), ret.end());
    
    return ret;
}

int calcBase10(string base3Rev) {
    int base3 = 1;
    
    int ret = 0;
    for (int i = 0; i < base3Rev.size(); ++i) {
        ret += base3 * (base3Rev[i] - '0');
        base3 *= 3;
    }
    
    return ret;
}

int solution(int n) {
    // 3진법 역순
    string base3Rev = base3Reversed(n);
    // 10진법 계산
    int answer = calcBase10(base3Rev);
    return answer;
}
