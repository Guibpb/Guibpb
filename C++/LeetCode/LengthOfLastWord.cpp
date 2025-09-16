#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string a = s.substr(' ');
        return 2;
    }
};

int main(){
    Solution solution;
    string s = "que que ta acontecendo";
    string palavra = s.substr(' ');
    cout << palavra << endl;


    return 0;
}