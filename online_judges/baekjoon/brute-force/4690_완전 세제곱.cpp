// https://www.acmicpc.net/problem/4690

#include <iostream>
#include <vector>

using namespace std;

int cache[101];
int SIZE = 101;

void solution(int, int, vector<int>&);
bool isValid(int, vector<int>&);
void print(int, vector<int>&);

int main (int argc, char *argv[]) {
    for (int i = 0; i < SIZE; ++i) {
        cache[i] = i * i * i;
    }
    
    vector<int> picked;
    for (int i = 0; i < SIZE; ++i) {
        solution(i, 3, picked);
    }
    
    return 0;
}

void solution(int end, int toPick, vector<int>& picked) {
    if (toPick == 0) {
        if (isValid(end, picked)) {
            print(end, picked);
        }
        return;
    }
    
    int smallest = picked.empty() ? 2 : picked.back() + 1;
    
    for (int i = smallest; i < end; ++i) {
            picked.push_back(i);
            solution(end, toPick - 1, picked);
            picked.pop_back();
    }
}

bool isValid(int end, vector<int>& picked) {
    return cache[end] == cache[picked[0]] + cache[picked[1]] + cache[picked[2]];
}

void print(int end, vector<int>& picked) {
    cout << "Cube = " << end << ", ";
    cout << "Triple = (" << picked[0] << "," << picked[1] << "," << picked[2] << ") \n";
}
