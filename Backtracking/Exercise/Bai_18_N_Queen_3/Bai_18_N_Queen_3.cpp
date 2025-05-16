#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> X(100, vector<char>(100, '.'));
void Try(int n, vector<bool> cols, vector<bool> mainDiagonal, vector<bool>secondaryDiagonal, int i = 1){
    for (int j = 1; j <= n; j++){
        if (cols[j] == false && mainDiagonal[n - j + i] == false && secondaryDiagonal[i + j - 1] == false){
            X[i][j] = 'Q'; 
            cols[j] = true;
            mainDiagonal[n - j + i] = true;
            secondaryDiagonal[i + j - 1] = true;
            if (i == n){
                for (int i = 1; i <= n; i++){
                    for (int j = 1; j <= n; j++){
                        cout << X[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else {
                Try(n, cols, mainDiagonal, secondaryDiagonal, i + 1);
            }
            X[i][j] = '.';
            cols[j] = false;
            mainDiagonal[n - j + i] = false;
            secondaryDiagonal[i + j - 1] = false;
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<bool> rows(n + 1, false);
    vector<bool> cols(n + 1, false);
    vector<bool> mainDiagonal(2 * n + 1, false);
    vector<bool> secondaryDiagonal(2 * n + 1, false);
    Try(n, cols, mainDiagonal, secondaryDiagonal);
}