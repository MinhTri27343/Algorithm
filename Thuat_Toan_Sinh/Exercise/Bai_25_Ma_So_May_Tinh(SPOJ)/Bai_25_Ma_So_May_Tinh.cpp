#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool nextPermutationRepetition(vector<int>& a, int n){
    int k = a.size();
    int i = k - 1;
    while (i >= 0 && a[i] == n){
        i--;
    }
    if (i == -1){
        return false;
    }
    else {
        a[i] += 1;
        for (int j = i + 1; j < k; j++){
            a[j] = 1;
        }
    }
    return true;
}
bool nextPermutation(vector<char>& a){
    int i = a.size() - 2;
    while (i >= 0 && a[i] > a[i + 1]){
        i--;
    }
    if (i == -1){
        return false;
    }
    else {
        int j = a.size() - 1;
        while (a[i] > a[j]){
            j--;
        }
        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.end());
    }
    return true;
}
int main(){
    int n, k;
    cin >> n;
    k = n;
    
    vector<char> v(k);
    for (int i = 0; i < k; i++){
        v[i] = 'A' + i;
    }
    do{
        string prev = "";
        for (char x : v){
            prev += x;
        }
        vector<int> a(k, 1);
        do{
            cout << prev;
            for (int x : a){
                cout << x;
            }
            cout << endl;
        }while(nextPermutationRepetition(a, n) == true);
    }while (nextPermutation(v) == true);
    return 0;

}