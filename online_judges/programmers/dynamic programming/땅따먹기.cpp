#include <vector>
#include <cstring>

using namespace std;

int cache[100001][4];

int getMaxScore(int here, int height, const vector<vector<int> >& land) {
    if (height == land.size())
        return 0;
    
    int& score = cache[height][here];
    if (score != -1) {
        return score;
    }
    
    for (int there = 0; there < land[height].size(); ++there) {
        if (here == there)
            continue;
        score = max(score, land[height][here] + getMaxScore(there, height + 1, land));
    }

    return score;
}

int solution(vector<vector<int> > land) {
    memset(cache, -1, sizeof(cache));
    
    int ret = 0;
    
    for (int here = 0; here < land[0].size(); ++here) {
        ret = max(ret, getMaxScore(here, 0, land));
    }
    
    return ret;
}
