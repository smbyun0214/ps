#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    return stol(str);
}
