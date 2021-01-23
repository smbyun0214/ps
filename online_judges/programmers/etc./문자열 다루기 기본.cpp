#include <string>
#include <vector>

using namespace std;

bool isAllDigits(string& str) {
    for (char c : str) {
        if (c < '0' || '9' < c) {
            return false;
        }
    }
    return true;
}

bool solution(string s) {
    if ((s.size() == 4 || s.size() == 6)
        && isAllDigits(s)) {
        return true;
    }
    return false;
}
