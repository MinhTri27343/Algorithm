#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool isPrime(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
void Try(vector<int> primes, int n, int k, int i = 0, int sum = 0, int start = 0, vector<int> X = {}){
    for (int j = start; j < primes.size(); j++){
        if (sum + primes[j] <= n){
            X.push_back(primes[j]);
            if (i == k - 1 && sum + primes[j] == n){
                for (int u = 0; u <= i; u++){
                    cout << X[u] << " ";
                    if (u < i){
                        cout << "+ ";
                    }
                }
                cout << endl;
            }
            else if (i < k - 1 && sum + primes[j] < n){
                Try(primes, n, k, i + 1, sum + primes[j], j + 1, X);
            }
            X.pop_back();
        }
        else {
            return;
        }
    }
}
int main(){
    vector<int> primes;
    for (int i = 2; i <= 500; i++){
        if (isPrime(i)){
            primes.push_back(i);
        }
    }
    int n , k;
    cin >> n >> k;
    Try(primes, n, k);


}