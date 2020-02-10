#include <iostream>

using namespace std;

long long pow(int A, int B, int mod) {
    if (B == 1)
        return A % mod;
    
    if (B % 2)
        return (A * pow(A, B - 1, mod)) % mod;
    
    long long tmp = pow(A, B / 2, mod) % mod;
    
    return (tmp * tmp) % mod;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int A, B, mod;
    cin >> A >> B >> mod;
    
    cout << pow(A, B, mod) << '\n';
    
    return 0;
}
