#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

long long comp;
long long mov;

void insertionSort(vector <int> &vetor){
    int N = vetor.size() - 1;

    for(int i = 2; i <= N; i++){
        int numAtual = vetor[i];
        vetor[0] = numAtual;
        mov += 2;
        int j = i;

        while(numAtual < vetor[j-1]){
            comp++;
            vetor[j] = vetor[j-1];
            mov++;
            j--;
        }
        comp++;
        vetor[j] = numAtual;
        mov++;
    }
}

void binaryInsertionSort(vector <int> &vetor){
    int N = vetor.size() - 1;

    for(int i = 2; i <= N; i++){
        int numAtual = vetor[i];
        mov++;
        int L = 1, R = i;

        while(L < R){
            int m = (L+R)/2;
            comp++;
            if(vetor[m] <= numAtual)
                L = m + 1;
            else
                R = m;
        }

        int j = i;

        while(j > R){
            mov++;
            vetor[j] = vetor[j-1];
            j--;
        }
        vetor[R] = numAtual;
        mov++;
    }
}

void selectionSort(vector <int> &vetor){
    int N = vetor.size() - 1;

    for(int i = 1; i <= N; i++){
        int indiceMenor = i;

        for(int j = i+1; j <= N; j++){
            comp++;
            if(vetor[j] < vetor[indiceMenor])
                indiceMenor = j;
        }

        int numAtual = vetor[i];
        vetor[i] = vetor[indiceMenor];
        vetor[indiceMenor] = numAtual;

        mov += 3;
    }
}

void bubbleSort(vector <int> &vetor){
    int N = vetor.size() - 1;

    for(int i = 2; i <= N; i++){
        for(int j = N; j >= i; j--){
            comp++;
            if(vetor[j-1] > vetor[j]){
                int numAtual = vetor[j-1];
                vetor [j-1] = vetor[j];
                vetor[j] = numAtual;
                mov += 3;
            }
        }
    }
}

void heapify(vector<int> &vetor, int L, int R){
    int i = L;
    int j = 2*L;
    int numAtual = vetor[L];
    mov++;

    comp++;
    if((j < R) && (vetor[j] < vetor[j+1])){
        j++;
    }

    comp++;
    while((j <= R) && (numAtual < vetor[j])){
        comp++;
        mov++;
        vetor[i] = vetor[j];
        i = j;
        j = 2*j;

        comp++;
        if((j < R) && (vetor[j] < vetor[j+1])){
            j++;
        }
    }

    vetor[i] = numAtual;
    mov++;
}

void heapSort(vector <int> &vetor){
    int N = vetor.size() - 1;
    for(int L = N/2; L >= 1; L--){
        heapify(vetor, L, N);
    }

    for(int R = N; R >= 2; R--){
        int w = vetor[1];
        vetor[1] = vetor[R];
        vetor[R] = w;
        mov += 3;
        heapify(vetor,1,R-1);
    }
}

void merge(vector<int> &vetor, int L, int h, int R, vector<int> &c) {
    int i = L;
    int j = h + 1;
    int k = L-1;

    while ((i <= h) && (j <= R)) {
        k++;
        comp++;
        if (vetor[i] < vetor[j]) {
            c[k] = vetor[i];
            i++;
        } else {
            c[k] = vetor[j];
            j++;
        }
        mov++;
    }

    while (i <= h) {
        k++;
        c[k] = vetor[i];
        mov++;
        i++;
    }

    while (j <= R) {
        k++;
        c[k] = vetor[j];
        mov++;
        j++;
    }
}

void mpass(vector<int> &vetor, int N, int p, vector<int> &c) {
    int i = 1;

    while (i <= N-(2*p)+1) {
        merge(vetor, i, i + p - 1, i + 2 * p - 1, c);
        i = i + 2*p;
    }

    if (i + p - 1 < N) {
        merge(vetor, i, i + p - 1, N, c);
    } else {
        for (int j = i; j <= N; j++) {
            c[j] = vetor[j];
        }
    }
}

void mergeSort(vector<int> &vetor) {
    int N = vetor.size() - 1;
    int p = 1;
    vector<int> c(N);

    while (p < N) {
        mpass(vetor, N, p, c);
        p = 2 * p;
        mpass(c, N, p, vetor);
        p = 2 * p;
    }
}

void quickSort(vector <int> &vetor, int L, int R){
    int i = L, j = R, w;
    int x = vetor[(L+R)/2];
    mov++;

    do{
        comp++;
        while(vetor[i] < x){
            i++;
            comp++;
        }

        comp++;
        while(x < vetor[j]){
            j--;
            comp++;
        }

        if(i <= j){
            w = vetor[i];
            vetor[i] = vetor[j];
            vetor[j]= w;
            i++;
            j--;
            mov += 3;
        }
    }while(i <= j);

    if(L < j){
        quickSort(vetor, L, j);
    }
        

    if(i < R){
        quickSort(vetor, i, R);
    }
}

void setVetorFixo(vector <int> &vetor){
    vetor[1] = 45;
    vetor[2] = 56;
    vetor[3] = 12;
    vetor[4] = 43;
    vetor[5] = 95;
    vetor[6] = 19;
    vetor[7] = 8;
    vetor[8] = 67;
}

void testes(){
    vector <int> vetor(9);

    setVetorFixo(vetor);
    cout << "Vetor antes: " << endl;
    for(int i = 1; i <=8; i++){
        cout << vetor[i] << " ";
    }
    cout << "\n\n";

    comp = 0;
    mov = 0;
    insertionSort(vetor);

    cout << "Vetor ordenado (Ordenação Por Inserção): " << endl;
    for(int i = 1; i <=8; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
    cout << comp << " " << mov << endl;


    setVetorFixo(vetor);
    comp = 0;
    mov = 0;
    binaryInsertionSort(vetor);

    cout << "Vetor ordenado (Ordenação Por Inserção Binária): " << endl;
    for(int i = 1; i <=8; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
    


    setVetorFixo(vetor);
    comp = 0;
    mov = 0;
    selectionSort(vetor);

    cout << "Vetor ordenado (Ordenação Por Seleção): " << endl;
    for(int i = 1; i <=8; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;


    setVetorFixo(vetor);
    comp = 0;
    mov = 0;
    bubbleSort(vetor);

    cout << "Vetor ordenado (Ordenação Por Método da Bolha): " << endl;
    for(int i = 1; i <=8; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;


    setVetorFixo(vetor);
    comp = 0;
    mov = 0;
    heapSort(vetor);

    cout << "Vetor ordenado (Ordenação Por Heap Sort): " << endl;
    for(int i = 1; i <=8; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;


    setVetorFixo(vetor);
    comp = 0;
    mov = 0;
    mergeSort(vetor);

    cout << "Vetor ordenado (Ordenação Por Fusão): " << endl;
    for(int i = 1; i <=8; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;


    setVetorFixo(vetor);
    comp = 0;
    mov = 0;
    quickSort(vetor, 1, vetor.size()-1);

    cout << "Vetor ordenado (Ordenação Por QuickSort): " << endl;
    for(int i = 1; i <=8; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void getVetorCrescente(vector <int> &vetor, int N){
    for(int i = 1; i <= N; i++){
        vetor.push_back(i);
    }
}

void getVetorDecrescente(vector <int> &vetor, int N){
    for(int i = N; i >= 1; i--){
        vetor.push_back(i);
    }
}

void getVetorAleatório(vector <int> &vetor, int N){
    srand(time(0));

    for(int i = 1; i <= N; i++){
        int randomNum = rand() % 101;
        vetor.push_back(randomNum);
    }
}

int main(){
    /*int N;
    cout << "Insira o tamanho do vetor: ";
    cin >> N;

    vector <int> vetor(N);
    cout << "Preencha o vetor: " << endl;

    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;
        vetor.push_back(num);
    }

    //insertionSort(vetor);
    //binaryInsertionSort(vetor);
    //selectionSort(vetor);
    //bubbleSort(vetor);
    //heapSort(vetor);
    //mergeSort(vetor);
    //quickSort(vetor, 1, N);*/

    vector <int> vetor;
    clock_t t1, t2;
    double tTotal;
    comp = 0;
    mov = 0;

    getVetorCrescente(vetor, 1000);

    t1 = clock();
    binaryInsertionSort(vetor);
    t2 = clock();

    tTotal = difftime(t2,t1)/CLOCKS_PER_SEC;

    cout << comp << " " << mov << " " << tTotal << endl;

    //testes();

    return 0;
}