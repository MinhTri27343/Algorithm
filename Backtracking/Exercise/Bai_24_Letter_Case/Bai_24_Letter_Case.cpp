#include <iostream>
using namespace std;
int count = 1; 
void Try(string s, int i = 0){
    if (i == s.size()){
        cout << count << " " << s  << endl;
    }
    else {
        if (isalpha(s[i])){
            s[i] = toupper(s[i]);
            Try(s, i + 1);
            s[i] = tolower(s[i]);
            Try(s, i + 1);
            
        }
        else {
            Try(s, i + 1);
        }
    }

}
int main(){
    string s;
    cin >> s;
    Try(s);

}