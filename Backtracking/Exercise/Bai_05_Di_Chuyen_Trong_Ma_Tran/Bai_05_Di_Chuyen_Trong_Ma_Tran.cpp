#include <iostream>
#include <vector>
using namespace std;
bool flag = false;
int cnt = 0;
vector<vector<bool>> visited(100, vector<bool>(100, false));
void Try(int n, int m, int idxI = 1, int idxJ = 1, int i = 1){
    if (idxI == n && idxJ == m){
        flag = true;
        cnt++;
    }
    if (idxI < n && visited[idxI + 1][idxJ] == false){
        visited[idxI + 1][idxJ] = true; // Danh dau o da duoc di 
        Try(n, m, idxI + 1, idxJ, i + 1);
        visited[idxI + 1][idxJ] = false; // Bo ghi nhan
    }
    if (idxJ < m && visited[idxI][idxJ + 1] == false){
        visited[idxI][idxJ + 1] = true; // Danh dau o da duoc di 
        Try(n, m,idxI, idxJ + 1, i + 1);
        visited[idxI][idxJ + 1] = false; // Bo ghi nhan

    }
}
int main(){
    flag = false;
    int n, m;
    cin >> n >> m;
    string s = "";
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> matrix[i][j];
        }
    }
    if (visited[1][1] == false){
        visited[1][1] = true;
        Try(n, m);
        if (flag == false){
            cout << "-1";
        }
        cout << cnt;
        cout << endl;
    }
    else {
        cout << "-1\n";
    }

}