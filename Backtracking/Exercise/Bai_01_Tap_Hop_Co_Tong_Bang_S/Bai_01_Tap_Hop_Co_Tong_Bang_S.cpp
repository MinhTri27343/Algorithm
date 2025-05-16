#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int cnt = 0;
ll total = 0;
void Try(vector<int> a, int n, int k, int s, int sum = 0, int i = 1){
    for (int j = a[i - 1] + 1; j <= i + n - k; j++){
        total++;
        if (sum + j <= s){
            a[i] = j;
            if (i == k && sum + j == s){
                cnt++;
                return;
            }
            else if (i < k){
                Try(a, n, k, s, sum + j, i + 1);
            }
        }
        else {
            return;
        }
    }
}
/*
9
9 3 23 
9 3 22 
10 3 28
16 10 107
20 8 102
20 10 105
20 10 155 
3 4 3 
4 2 11
*/
int main(){
    int t;
    cin >> t;
    while (t--){
        cnt = 0;
        int n, k, s;
        cin >> n >> k >> s;
        vector<int> a(k + 1);
        for (int i = 0; i <= k; i++){
            a[i] = i;
        }
        Try(a, n, k, s);
        cout << cnt << endl;
    }
}
/*
34
91 
97 
*/