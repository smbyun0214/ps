#include <string>
#include <vector>

using namespace std;

bool inRange(int y, int x, vector<vector<int> >& cache) {
    return 0 <= y && y < cache.size() && 0 <= x && x < cache[y].size() && cache[y][x] == 0;
}

vector<int> solution(int n) {
    vector<vector<int> > cache(n);
    for (int i = 0; i < n; ++i) {
        cache[i] = vector<int>(i + 1);
    }

    int y = -1, x = 0;
    int order = 0, end = n * (n + 1) / 2;

    while (order != end) {
        while (inRange(y + 1, x, cache)) {
            ++y;
            cache[y][x] = ++order;
        }
        while (inRange(y, x + 1, cache)) {
            ++x;
            cache[y][x] = ++order;
        }
        while (inRange(y - 1, x - 1, cache)) {
            --y; --x;
            cache[y][x] = ++order;
        }
    }
    
    vector<int> ret;
    for (vector<int>& v : cache) {
        for (int i : v) {
            ret.push_back(i);
        }
    }

    return ret;
}
