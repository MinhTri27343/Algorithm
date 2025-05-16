#include <iostream>
#include <vector>
using namespace std;
int minSum = 1e9;
int cMin = 1e9;
void Try(vector<vector<int>> matrix, vector<int> x,  vector<bool> visited, int n,  int sum = 0, int i = 2){
    for (int j = 2; j <= n; j++){
        if (visited[j] == false){
            visited[j] = true;
            x[i] = j;
            sum += matrix[x[i]][x[i - 1]];
            if (i == n){
                if (minSum > sum + matrix[1][x[i]]){
                    minSum = sum + matrix[1][x[i]];
                }
            }
            // Danh gia can 
            else if (sum + (n + 1 - i) * cMin < minSum){
                Try(matrix, x, visited, n, sum, i + 1);
            }
            sum -= matrix[x[i]][x[i - 1]];
            visited[j] = false;
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> matrix[i][j];
            if (matrix[i][j]){
                cMin = min(cMin, matrix[i][j]);
            }
        }
    }
    vector<int> x(n + 1, 0);
    x[1] = 1;
    vector<bool> visited(n + 1, false);
    Try(matrix, x, visited, n);
    cout << minSum << endl;

}