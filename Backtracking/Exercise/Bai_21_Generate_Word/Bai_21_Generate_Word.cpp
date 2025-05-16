#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
// Left - Down - Up - Right 
bool flag = false;
vector<char> X(100);
vector<vector<bool>> visited(100, vector<bool>(100, false));
void Try(string s, vector<vector<char>> matrix, int n, int m, int i, int j, int str_size, int index = 1){
    if (flag) return;    
    if (matrix[i][j] == s[index]){
        X[index] = matrix[i][j];
        if (index == str_size){
            flag = true;
        }
        else { 
            for (int k = 0; k < 4; k++){
                int i_new = i + dy[k];
                int j_new = j + dx[k];
                if (i_new >= 1 && i_new <= n && j_new >= 1 && j_new <= m && index + 1 <= str_size && visited[i_new][j_new] == false){
                    visited[i_new][j_new] = true;
                    Try(s, matrix, n, m, i_new, j_new, str_size , index + 1);
                    visited[i_new][j_new] = false;
                }   

            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> matrix[i][j];
        }
    }
    string s;
    cin >> s;
    int str_size = s.size();
    s = '0' + s;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            visited[i][j] = true;
            Try(s, matrix, n, m, i, j, str_size);
            visited[i][j] = false;
            if (flag){
                break;
            }
        }
        if (flag){
            break;
        }
    }
    if (flag){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}