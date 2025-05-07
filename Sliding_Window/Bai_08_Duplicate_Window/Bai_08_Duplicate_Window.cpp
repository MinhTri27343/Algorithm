#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<int, int> unMap;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (unMap.find(a[i]) != unMap.end()){
            if (i - unMap[a[i]] <= k){
                cout << "YES\n";
                return 0;
            }
            unMap[a[i]] = i;
        }
        else {
            unMap[a[i]] = i;
        }
    }
    cout << "NO\n";
    return 0;
    
}
/*
- Mot solution khac la xay dung cua so truot voi kich thuoc k va kiem tra xem 
trong cua so do co 2 gia tri bang nhau khong bang cach dem tan suat
*/