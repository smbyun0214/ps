// https://www.acmicpc.net/problem/1029

#include <iostream>
#include <cstring>

using namespace std;

#define SELLER 15
#define BUYER 15
#define VISITED 1<<15
#define LAST_PRICE 10

int prices[SELLER][BUYER];
int cache[SELLER][VISITED][LAST_PRICE];

int getHasCount(int seller, int visited, int lastPrice, int N) {
    int &ret = cache[seller][visited][lastPrice];

    if (ret != -1){
        return ret;
    }

    ret = 0;

    for (int buyer = 0; buyer < N; ++buyer) {
        if (!(visited & (1<<buyer)) && lastPrice <= prices[seller][buyer]) {
            ret = max(ret, 1 + getHasCount(buyer, (visited | (1<<buyer)), prices[seller][buyer], N));
        }
    }

    return ret;
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    int N;
    cin >> N;

    char c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> c;
            prices[i][j] = c - '0';
        }
    }

    cout << 1 + getHasCount(0, 1, 0, N) << '\n';
    
    return 0;
}
