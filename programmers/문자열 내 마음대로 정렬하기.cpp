#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<vector<string> > arrCands('z'-'a'+1, vector<string>());
    
    for (string str : strings) {
        arrCands[str[n] - 'a'].push_back(str);
    }
    
    vector<string> answer;
    for (int i = 0; i < 'z'-'a'+1; ++i) {
        vector<string>& cands = arrCands[i];
        sort(cands.begin(), cands.end());
        answer.insert(answer.end(), cands.begin(), cands.end());
    }
    
    return answer;
}
