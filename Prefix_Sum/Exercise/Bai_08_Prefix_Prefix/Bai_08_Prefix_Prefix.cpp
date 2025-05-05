#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 200000
struct Query{
    int left;
    int right; 
    int k;
};
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    Query* query = new Query[m + 1];
    int temp = m;
    while (temp--){
        cin >> query[m - temp].left;
        cin >> query[m - temp].right;
        cin >> query[m - temp].k;
    }
    for (int i = 1; i <= m; i++){
        cout << query[i].left << " " << query[i].right << " " << query[i].k << endl;
    }
    vector<int> diffQuery(m + 1, 0);
    diffQuery[1] = 1;
    while (q--){
        int left;
        int right;
        cin >> left >> right;
        diffQuery[left] += 1;
        diffQuery[right + 1] -= 1;
    }
    vector<int> freQuery(m + 1, 1);
    freQuery[1] = diffQuery[1];
    for (int i = 2; i <= m; i++){
        freQuery[i] = diffQuery[i] + freQuery[i - 1];
    }
    vector<int> diffArray(n + 2, 0);
    diffArray[1] = a[1];
    for (int i = 2; i <= n; i++){
        diffArray[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= m; i++){
        int left = query[i].left;
        int right = query[i].right;
        int k = query[i].k;
        diffArray[left] += k * freQuery[i];
        diffArray[right + 1] -= k * freQuery[i];
    }
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++){
        res[i] = res[i - 1] + diffArray[i];
    }
    for (int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    delete [] query;
    return 0;
}