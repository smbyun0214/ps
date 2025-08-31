#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    int num = -1;
	
    vector<int> answer;
    for (int i : arr) {
        if (i != num) {
            answer.push_back(i);
            num = i;
        }
    }
    
    return answer;
}
