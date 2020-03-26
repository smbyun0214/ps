#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int X, Y;
    
    cin >> X >> Y;
    
    if (0 < X && 0 < Y)
        cout << 1 << '\n';
    else if (X < 0 && 0 < Y)
        cout << 2 << '\n';
    else if (X < 0 && Y < 0)
        cout << 3 << '\n';
    else
        cout << 4 << '\n';
        
    return 0;
}
