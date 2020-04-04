#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    double A, B;
    
    cin >> A >> B;
    
    cout.precision(13);
    cout << fixed << A / B << '\n';
    
    
    return 0;
}
