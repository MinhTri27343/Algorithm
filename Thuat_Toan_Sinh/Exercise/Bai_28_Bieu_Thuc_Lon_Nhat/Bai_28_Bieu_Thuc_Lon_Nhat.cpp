#include<iostream>
using namespace std;
#define ll long long
int main(){
    int x, y, z , t;
    cin >> x >> y >> z >> t;
    ll sum = 0;
    sum = abs(x) + abs(y) + abs(z) + abs(t);
    cout << sum << endl;
    return 0;
    
}
