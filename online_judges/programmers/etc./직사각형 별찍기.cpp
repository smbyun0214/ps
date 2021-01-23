#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int width, height;
    cin >> width >> height;
    
    string star(width, '*');
    while (height--) {
        cout << star << endl;
    }

    return 0;
}
