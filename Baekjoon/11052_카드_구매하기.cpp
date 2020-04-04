#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MIN = -987654321;

int N;
int cache[10001];

int buyCards(int start, int numOfCards, const vector<int> &prices) {
    if (numOfCards == 0)
        return 0;
    if (numOfCards < 0 || start == prices.size())
        return MIN;
    
    int &ret = cache[numOfCards];
    if (ret != -1)
        return ret;
    
    if (start == -1)
        return buyCards(start + 1, numOfCards, prices);
    
    int ret0 = prices[start] + buyCards(start, numOfCards - (start + 1), prices);
    int ret1 = buyCards(start + 1, numOfCards, prices);
    
    ret = max(ret0, ret1);
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    
    vector<int> prices(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }
    
    cout << buyCards(-1, N, prices) << '\n';
    
    return 0;
}
