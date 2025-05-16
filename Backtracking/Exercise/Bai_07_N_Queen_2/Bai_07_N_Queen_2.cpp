#include <iostream>
#include <vector>
using namespace std;
int maxSum = 0;
void Try(int n, vector<vector<int>> matrix, vector<bool> cols, vector<bool> mainDiagonal, vector<bool>secondaryDiagonal, int i = 1, int sum = 0){
    for (int j = 1; j <= n; j++){
        if (cols[j] == false && mainDiagonal[n - j + i] == false && secondaryDiagonal[i + j - 1] == false){
            cols[j] = true;
            mainDiagonal[n - j + i] = true;
            secondaryDiagonal[i + j - 1] = true;
            if (i == n){
                if (maxSum < sum + matrix[i][j]){
                    maxSum = sum + matrix[i][j];
                }
            }
            else {
                Try(n, matrix, cols, mainDiagonal, secondaryDiagonal, i + 1, sum + matrix[i][j]);
            }
            cols[j] = false;
            mainDiagonal[n - j + i] = false;
            secondaryDiagonal[i + j - 1] = false;
        }
    }
}
int main(){
    int n = 8;
    maxSum = 0;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }
    vector<bool> cols(n + 1, false);
    vector<bool> mainDiagonal(2 * n + 1, false);
    vector<bool> secondaryDiagonal(2 * n + 1, false);
    Try(n, matrix, cols, mainDiagonal, secondaryDiagonal);
    cout << maxSum << endl;

}
/*
12 29 80 91 56 46 97 13
54 88 27 84 85 9 32 77
48 80 88 74 30 77 38 98
6 82 20 95 7 86 12 43
100 82 15 7 95 9 5 84
51 40 65 98 86 38 30 63
96 78 98 76 33 11 2 58
33 51 35 68 62 87 67 39
*/