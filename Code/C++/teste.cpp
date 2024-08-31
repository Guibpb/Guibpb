#include <iostream>
#include <vector>

int main(){
    std::vector<int> vetor (50,1);

    for(int num : vetor){
        std::cout << num << "Hello World" << std::endl;
    }

    return 0;
}