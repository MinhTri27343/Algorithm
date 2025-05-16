#include <iostream>
#include <vector>
using namespace std;
bool flag = false;
int dx[4] = {0, -1, 1, 0 };
int dy[4] = {1, 0, 0, -1};
string path = "DLRU";
int cnt = 0;
void Try(vector<vector<int>> matrix, int n, string s, int idxI = 1, int idxJ = 1, int i = 1){
    if (idxI == n && idxJ == n){
        cnt++;
        flag = true;
        cout << s;
        cout << "\n";
    }
    for (int k = 0; k < 4; k++){
        int i_new = idxI + dy[k]; 
        int j_new = idxJ + dx[k];
        if (i_new <= n && i_new >= 1 && j_new >= 1 && j_new <= n && matrix[i_new][j_new] == 1){
            matrix[i_new][j_new] = 0;
            Try(matrix, n, s + path[k], i_new, j_new, i + 1);
            matrix[i_new][j_new] = 1;
        } 
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