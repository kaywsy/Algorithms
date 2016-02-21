#include <iostream>
#include <string>

using namespace std;

string compress(string str) {
    int len = (int)str.size(), count = 1;
    string result;
    char t = str[0];
    for (int i = 1; i <= len; ++i) {
        if (str[i] == t) {
            count++;
        } else {
            if (count > 1) {
                result += to_string(count) + str[i-1];
            } else {
                result += str[i-1];
            }
            t = str[i];
            count = 1;
        }
    }
    return result.size() > len ? str : result;
}

int main(int argc, const char * argv[]) {
    string test1 = "aaaaaasssbvkdslllsddssasda";
    string test2 = "abcde";
    string test3 = "aabbccddeeff";
    cout <<compress(test1) << endl;
    cout <<compress(test2) << endl;
    cout <<compress(test3) << endl;
}
