// https://www.acmicpc.net/problem/1759

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void print(vector<int>& picked, vector<char>& cases) {
    for (int i : picked)
        cout << cases[i];
    cout << '\n';
}

void findPassword(int vowel, int consonant, int toPick, vector<int>& picked, vector<char>& cases) {
    if (toPick == 0) {
        if (vowel <= 0 && consonant <= 0)
            print(picked, cases);
        return;
    }
    
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    
    for (int i = smallest; i < cases.size(); ++i) {
        if (isVowel(cases[i])) {
            picked.push_back(i);
            findPassword(vowel - 1, consonant, toPick - 1, picked, cases);
            picked.pop_back();
        }
        else {
            picked.push_back(i);
            findPassword(vowel, consonant - 1, toPick - 1, picked, cases);
            picked.pop_back();
        }
    }
}

int main (int argc, char *argv[]) {
    int letter, N;
    cin >> letter >> N;
    
    vector<char> cases(N, ' ');
    for (int i = 0; i < N; ++i) {
        cin >> cases[i];
    }
    
    sort(cases.begin(), cases.end());
    
    vector<int> picked;
    findPassword(1, 2, letter, picked, cases);
    
    return 0;
}
