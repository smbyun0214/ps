#include <string>

using namespace std;

string solution(string phone_number) {
    size_t length = phone_number.size();
    return string(length - 4, '*') + phone_number.substr(length - 4, 4);
}
