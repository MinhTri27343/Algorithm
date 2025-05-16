#include <iostream>
#include <vector>
using namespace std;
bool flag = false;
void Try(int n, int k, int i = 1, int start = 1, vector<int> X = {}, int sum = 0){
    for (int j = start; j <= 9; j++){
        if (sum + j <= n){
            X.push_back(j);
            if (i == k && sum + j == n){
                for (int i = 0; i < X.size(); i++){
                    cout << X[i] << " ";
                    if (i < X.size() - 1){
                        cout << "+ ";
                    }
                }
                cout << endl;
                flag = true;
            }
            else if (sum + j < n && i < k){
                Try(n, k, i + 1, j + 1, X, sum + j);
            }
            X.pop_back();
        }
        else {
            return;
        }
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    Try(n, k);
    if (flag == false){
        cout << "NOT FOUND\n";
    }

}