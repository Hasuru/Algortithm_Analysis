#include <iostream>
#include <array>
#include <string>

#define GEN 5290000

//working
void getMats(std::string mats, int mat1[6], int mat2[6]) {
    int index = 0;
    for (int i = 0; i < 8; i++) {
        if (i != 2 && i != 5) {
            mat1[index] = mats[i];
            index++;
        }
    }
    index = 0;
    for (int i = 9; i < 17; i++) {
        if (i != 11 && i != 14) {
            mat2[index] = mats[i];
            index++;
        }
    }
}

int letter_value(char l) {
    int cnt = l - 'A';
    if (l > 'K') {
        if (l > 'W') {
            if (l > 'Y') {
                cnt--;
            }
            cnt--;
        }
        cnt--;
    }
    return cnt;
}

int number_value(char n){
     return n - '0';
}

// Ajuda de Joao Azevedo a formular a funcao abaixo
int getSeries(int mat[]) {
    int gen = 0;
    if (mat[4] >= 'A' && mat[4] <= 'Z') gen = 1;
    if (mat[2] >= 'A' && mat[2] <= 'Z') gen = 2;
    if (mat[0] >= 'A' && mat[0] <= 'Z' && mat[4] >= 'A' && mat[4] <= 'Z') gen = 3;

    int series = gen * GEN;
    if(gen == 0) {
        series += letter_value(mat[0])*23*10*10*10*10 + letter_value(mat[1])*10*10*10*10 + number_value(mat[2])*10*10*10 + number_value(mat[3])*10*10 + number_value(mat[4])*10 + number_value(mat[5]);
    }
    if (gen == 1) {
        series += letter_value(mat[4])*23*10*10*10*10 + letter_value(mat[5])*10*10*10*10 + number_value(mat[0])*10*10*10 + number_value(mat[1])*10*10 + number_value(mat[2])*10 + number_value(mat[3]);
    }
    if (gen == 2) {
        series += letter_value(mat[2])*23*10*10*10*10 + letter_value(mat[3])*10*10*10*10 + number_value(mat[0])*10*10*10 + number_value(mat[1])*10*10 + number_value(mat[4])*10 + number_value(mat[5]);
    }
    if(gen == 3) {
        series += letter_value(mat[0])*23*23*23*10*10 + letter_value(mat[1])*23*23*10*10 + letter_value(mat[4])*23*10*10 + letter_value(mat[5])*10*10 + number_value(mat[2])*10 + number_value(mat[3]);
    }
    return series;
}

int main() {
    int n, m1series, m2series;
    int mat1[6], mat2[6]; 

    std::cin >> n;
    std::cin.ignore();
    for(int i = 0; i < n; i++) {
        std::string mats;
        getline(std::cin, mats);
        getMats(mats, mat1, mat2);
        m1series = getSeries(mat1);
        m2series = getSeries(mat2);
        printf("%d\n", abs(m1series - m2series));
    }

    return 0;
}