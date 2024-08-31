#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        
        return haystack.find(needle);
    }
};

int main(){
    string a, b;
    a = "sadbutsad";
    b = "sad";

    Solution solution;
    cout << solution.strStr(a, b);


    return 0;
}