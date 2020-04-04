#include <iostream>

using namespace std;

int decimalDigitSum(int n, int digit) {
    int ret = 0;
    
    while (n) {
        ret += (n % digit);
        
        n /= digit;
    }
    
    return ret;
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    for (int i = 1000; i <= 9999; ++i) {
        int duoSum = decimalDigitSum(i, 12);
        if (duoSum == -1) continue;
        
        int hexaSum = decimalDigitSum(i, 16);
        if (hexaSum == -1) continue;
        
        int decimalSum = decimalDigitSum(i, 10);
        
        if (decimalSum == duoSum && decimalSum == hexaSum)
            cout << i << '\n';
    }
    
    return 0;
}
