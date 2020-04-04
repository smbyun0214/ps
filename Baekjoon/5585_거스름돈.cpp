#include <iostream>

using namespace std;

const int MONEY = 1000;
const int coins[] = {500, 100, 50, 10, 5, 1};

int change(int money) {
    int ret = 0;
    
    for (int type = 0; type < 6; ++type) {
        int coin = coins[type];
        
        while (money / coin) {
            ret += (money / coin);
            money %= coin;
        }
    }
    
    return ret + money;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int price; cin >> price;
    
    cout << change(MONEY - price) << '\n';
    
    return 0;
}
