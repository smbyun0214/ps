#include <iostream>

using namespace std;

const int INF = 2000;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int minBurger = INF, minDrink = INF;
    
    int burger, drink;
    for (int i = 0; i < 3; ++i) {
        cin >> burger;
        minBurger = min(minBurger, burger);
    }
    
    for (int i = 0; i < 2; ++i) {
        cin >> drink;
        minDrink = min(minDrink, drink);
    }
    
    cout << minBurger + minDrink - 50 << '\n';
    
    return 0;
}
