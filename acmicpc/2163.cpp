#include <iostream>
#include <fstream>

using namespace std;

int splitChocolate(int h, int w) {
    if (h == 1)
        return w - 1;
    
    if (w == 0 || h == 0)
        return 0;
    
    if (h > w)
        return splitChocolate(w, h);
    
    return 1 + splitChocolate(h, w / 2) + splitChocolate(h, w - (w / 2));
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int h, w;
    cin >> h >> w;
    
    cout << splitChocolate(h, w) << '\n';
    
    return 0;
}
