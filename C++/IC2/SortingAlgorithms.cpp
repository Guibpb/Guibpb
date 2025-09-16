#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

void printa(const std::vector<int>& heights, char character) {
    int maxHeight = *std::max_element(heights.begin(), heights.end());

    // Percorre a altura máxima para imprimir cada linha
    for (int row = maxHeight; row > 0; --row) {
        for (size_t col = 0; col < heights.size(); ++col) {
            // Imprime o caractere se a altura for suficiente
            if (heights[col] >= row) {
                std::cout << character << character; // Colunas mais grossas
            } else {
                std::cout << "  "; // Espaço para colunas vazias
            }
            std::cout << " "; // Espaçamento entre colunas
        }
        std::cout << std::endl; // Nova linha após cada linha de impressão
    }
}

void insertion(std::vector<int> &vet){
    int N = 9;

    for(int i = 1; i < N; i++){
        int x = vet[i];
        int j = i;

        while(j > 0 && x < vet[j-1]){
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = x;

        printa(vet, '*');
        sleep(1);
        std::cout << "\n\n\n";
    }
}

void bubble(std::vector <int> &vet){
    int N = 9;
    int j = 1;
    bool sorted;
    
    do{
        sorted = true;

        for(int i = 0; i < N-j; i++){
            if(vet[i] > vet[i+1]){
                vet[i] += vet[i+1];
                vet[i+1] = vet[i] - vet[i+1];
                vet[i] -= vet[i+1];
                printa(vet, '*');
                sleep(1);
                std::cout << "\n\n";
                sorted = false;
            }
        }
        j++;

    }while(!sorted);
    
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // Escolhe o último elemento como pivô
        int i = low - 1; // Índice do menor elemento

        // Particiona o vetor
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) { // Se o elemento atual for menor que o pivô
                i++; // Incrementa o índice do menor elemento
                std::swap(arr[i], arr[j]); // Troca
                printa(arr, '*');
                sleep(1);
                std::cout << "\n\n";
            }
        }
        std::swap(arr[i + 1], arr[high]); // Coloca o pivô na posição correta
        printa(arr, '*');
        sleep(1);
        std::cout << "\n\n";
        int pivotIndex = i + 1; // Índice do pivô

        // Ordena recursivamente as duas metades
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Exemplo de vetor de alturas
    std::vector<int> vet = {3, 1, 9, 8, 5, 7, 2, 6, 4};

    std::cout << "PRIMEIRO MÉTODO: INSERÇÃO " << std::endl;
    insertion(vet);

    vet = {3, 1, 9, 8, 5, 7, 2, 6, 4};

    std::cout << "SEGUNDO MÉTODO: BUBBLE" << std::endl;
    //bubble(vet);

    vet = {3, 1, 9, 8, 5, 7, 2, 6, 4};
    std::cout << "TERCEIRO MÉTODO: QUICKSORT" << std::endl;
    quickSort(vet, 0, 8);

    for(int i = 0; i < 9; i++){
        std::cout << vet[i] << " ";
    }

    std::cout << "\n";

    return 0;
}