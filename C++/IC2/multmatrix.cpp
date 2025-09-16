#include <iostream>

using namespace std;

int main(){
    int n = 2, m = 3 , r = 2;
    //for(int i = 0; i )

    int C[n][m] = {{1,2,3} , {4,5,6}};
    int D[m][r] = {{1,2}, {2,3}, {4,5}};
    int result2[n][r];

    for (int k = 0; k < n; k++) {
        for (int j = 0; j < r; j++) {
            result2[k][j] = 0; // Inicializa cada elemento
        }
    }

    for(int k = 0; k < n; k++){
        for(int j = 0; j < r; j++){
            for(int i = 0; i < m; i++){
                result2[k][j] += C[k][i]*D[i][j];
            }
        } 
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < r; j++){
            cout << result2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    

    
    return 0;
}