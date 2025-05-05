#include<iostream>
#include <vector>
using namespace std;
int main(){
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cout << endl;
    prefix[1][1] = a[1][1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            // Xay dung mang cong don 2 chieu 
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}