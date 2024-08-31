#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector <int> notval;

        for(int num : nums){
            if(num != val)
                notval.push_back(num);
        }

        nums.swap(notval);

        return nums.size();
    }
};

int main(){
    Solution solution;
    vector<int> nums;
    int val = 2;

    for(int i = 0; i < 15; i++){
        if(i%2 == 0)
            nums.push_back(2);
            
        else
            nums.push_back(3);
    }

    cout << "Vetor antes da mudança: ";

    for(int num : nums)
        cout << num << " ";

    cout << "Vetor após a mudança: ";

    solution.removeElement(nums, val);

    for(int num: nums)
        cout << num << " ";

    cout << "\n\n";

    return 0;
}
