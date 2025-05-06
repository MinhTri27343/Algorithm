#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    int j = 0, i = 0;
    int numberGreater = 0;
    while (i < n && j < m){
        if (a[i] < b[j]){
            numberGreater++;
            i++;
        }
        else {
            c[j] = numberGreater;
            j++;
        }
    }
    while (j < m){
        c[j] = numberGreater;
        j++;
    }
    for (int i = 0; i < m; i++){
        cout << c[i] << " ";
    }

}
