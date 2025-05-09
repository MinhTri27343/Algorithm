#include <iostream>
#include <vector>
using namespace std;
bool nextPartition(vector<int>& a, int &cur_size){
    int i = cur_size - 1;
    int sum = 0;
    while (i >= 0 && a[i] == 1){
        i--;
        sum++;
    }
    if (i == -1){
        return false;
    }
    a[i] -= 1;
    int temp = a[i];
    sum++;
    int d = sum / a[i];
    int r = sum % a[i];
    for (int j = 1; j <= d; j++){
        i++;
        a[i] = temp; 
    }
    if (r != 0){
        i++;
        a[i] = r;
    }
    cur_size = i + 1;
    return true;

}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int cur_size = 1;
    vector<vector<int>> res;
    a[0] = n;
    do{
        vector<int> item;
        for (int i = 0; i < cur_size; i++){
            item.push_back(a[i]);
        }
        res.push_back(item);
    }while(nextPartition(a, cur_size));
    cout << res.size() << endl;
    for (vector<int> item: res){
        for (int i = 0; i < item.size(); i++){
            cout << item[i];
            if (i != item.size() - 1){
                cout << "+";
            }
        }
        cout << endl;
    }
    return 0;
}