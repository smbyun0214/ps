// https://codeforces.com/gym/102556/problem/B
#include <iostream>
#include <string>

#define ull unsigned long long

using namespace std;

const int MOD = 104206969;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

ull A, B;

ull countDiv(int n) {
    if (A != 0)
        return B / n - (A - 1) / n;
    
    return B / n + 1;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    ull cacheSum = 0;
    
    for (int month = 1; month <= 12; ++month) {
        cacheSum += (45 + ((days[month - 1] - 9) * (days[month - 1] + 10) / 2)) + (90 * month + (days[month - 1] - 9) * 100 * month);;
    }
    
    cin >> A >> B;
    
    ull cntLeap = countDiv(4) - countDiv(100) + countDiv(400);
    ull ret = (((B - A + 1) % MOD) * cacheSum + (cntLeap % MOD) * 229) % MOD;
    
    cout << ret << '\n';
    
    return 0;
}
