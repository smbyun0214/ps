#include <string>
#include <vector>

using namespace std;

int getLength(vector<pair<int, int> >& pos, int here, int next) {
    return abs(pos[here].first - pos[next].first) + abs(pos[here].second - pos[next].second);
}

string solution(vector<int> numbers, string hand) {
    vector<pair<int, int> > pos = {
        {3, 1},
        {0, 0}, {0, 1}, {0, 2},
        {1, 0}, {1, 1}, {1, 2},
        {2, 0}, {2, 1}, {2, 2},
        {3, 0},         {3, 2}
    };
    
    int left = 10, right = 11;
    
    string answer = "";

    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            left = num;
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            right = num;
        }
        else if (getLength(pos, left, num) < getLength(pos, right, num)) {
            answer += "L";
            left = num;
        }
        else if (getLength(pos, left, num) > getLength(pos, right, num)) {
            answer += "R";
            right = num;
        }
        else if (hand == "left") {
            answer += "L";
            left = num;
        }
        else {
            answer += "R";
            right = num;
        }
    }
    return answer;
}
