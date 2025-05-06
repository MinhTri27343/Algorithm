#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(n + m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    int i = 0, j = 0, index = 0;
    while (i < n && j < m){
        if (a[i] < b[j]){
            c[index] = a[i];
            index++;
            i++;
        }
        else{
            c[index] = b[j];
            index++;
            j++;
        }
    }
    while (i < n){
        c[index] = a[i];
        index++;
        i++;
    }
    while (j < m){
        c[index] = b[j];
        index++;
        j++;
    }
    for (int i = 0; i < n + m; i++){
        cout << c[i] << " ";
    }

}
