#include <iostream>
#include <vector>
using namespace std;
void Try(vector<int> x, vector<bool> visited, int n, int i = 1){
    for (int j = 1; j <= n; j++){
        if (visited[j] == false && abs(j - x[i - 1]) >= 2){
            visited[j] = true;
            x[i] = j;
            if (i == n){
                for (int u = 1; u <= n; u++){
                    cout << x[u];
                }
                cout << endl;
                return;
            }
            else {
                Try(x, visited, n, i + 1);
            }
            visited[j] = false;
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> x(n + 1, -1);
    vector<bool> visited(n + 1, false);
    Try(x, visited, n);
    return 0;
}