#include <iostream>
#include <vector>
using namespace std;
bool flag = false;
void Try(vector<vector<int>> matrix, int n, string s, int idxI = 1, int idxJ = 1, int i = 1){
    if (idxI == n && idxJ == n){
        flag = true;
        cout << s;
        cout << "\n";
    }
    if (idxI < n && matrix[idxI + 1][idxJ] == 1){
        matrix[idxI + 1][idxJ] = 0; // Danh dau o da duoc di 
        Try(matrix, n, s + 'D', idxI + 1, idxJ, i + 1);
        matrix[idxI + 1][idxJ] = 1; // Bo ghi nhan
    }
    if (idxJ < n && matrix[idxI][idxJ + 1] == 1){
        matrix[idxI][idxJ + 1] = 0; // Danh dau o da duoc di 
        Try(matrix, n, s + 'R',idxI, idxJ + 1, i + 1);
        matrix[idxI][idxJ + 1] = 1; // Bo ghi nhan

    }
}
int main(){
    flag = false;
    int n;
    cin >> n;
    string s = "";
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }
    if (matrix[1][1] == 1){
        matrix[1][1] = 0;
        Try(matrix, n, s);
        if (flag == false){
            cout << "-1";
        }
        cout << endl;
    }
    else {
        cout << "-1\n";
    }

}
/*
2
4
1 0 0 0 
1 1 0 1
0 1 0 0
1 1 1 1
5 
1 0 0 0 0 
1 1 1 1 1 
1 1 0 0 1 
0 1 1 1 1 
0 0 0 1 1
*/