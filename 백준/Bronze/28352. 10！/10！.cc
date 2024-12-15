#include <iostream>
using namespace std;
int main(){
    int n;
    long long cnt=6;
    cin >> n;
    while(n>10){
        cnt*=n;
        n--;
    }
    cout << cnt;
}