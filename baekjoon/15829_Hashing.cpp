// https://www.acmicpc.net/problem/15829

#include <iostream>
#include <cstring>

using namespace std;

const int R = 31;
const int M = 1234567891;

long long cache[50];

long long solve(string s) {
    long long ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        ret = (ret + (s[i] - 'a' + 1) * cache[i]) % M;
    }
    return ret;
}

int main (int argc, char *argv[]) {
    memset(cache, 0, sizeof(cache));
    cache[0] = 1;
    for (int i = 1; i < 50; ++i) {
        cache[i] = (cache[i - 1] * R) % M;
    }
    
    string s;
    cin >> s >> s;
    
    cout << solve(s);
    
    return 0;
}

//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
//1016023867
