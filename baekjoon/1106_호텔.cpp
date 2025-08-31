// https://www.acmicpc.net/problem/1106

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;

vector<pair<int, int> > prices;

int cache[1001];

int solve(int toCustomer) {
    if (toCustomer <= 0) return 0;
    
    int& ret = cache[toCustomer];
    if (ret != -1) return ret;
    
    ret = INF;
    
    for (int i = 0; i < prices.size(); ++i) {
        int price = prices[i].first;
        int customer = prices[i].second;
        
        ret = min(ret, price + solve(toCustomer - customer));
    }
    
    return ret;
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int toCustomer, cities;
    cin >> toCustomer >> cities;
    
    while (cities--) {
        int price, customer;
        cin >> price >> customer;
        prices.push_back(make_pair(price, customer));
    }
    
    cout << solve(toCustomer);
    
    return 0;
}
