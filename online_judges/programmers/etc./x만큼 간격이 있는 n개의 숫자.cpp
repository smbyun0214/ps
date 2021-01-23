#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(1, x);
    while (--n) {
        answer.push_back(answer.back() + x);
    }
    return answer;
}
