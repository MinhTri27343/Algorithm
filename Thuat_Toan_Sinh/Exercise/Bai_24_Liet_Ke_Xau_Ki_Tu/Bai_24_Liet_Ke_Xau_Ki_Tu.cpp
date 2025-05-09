#include <iostream>
#include <vector>
using namespace std;
bool nextPermutationRepetition(vector<char>& a, char n){
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
            a[j] = 'A';
        }
    }
    return true;
}
int main(){
    char n;
    int k;
    cin >> n >> k;
    vector<char> a(k);
    for (int i = 0; i < k; i++){
        a[i] = 'A';
    }
    do{
        for (char x : a){
            cout << x;
        }
        cout << endl;
    }while (nextPermutationRepetition(a, n) == true);
    return 0;

}