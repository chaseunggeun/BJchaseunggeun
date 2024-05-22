#include <iostream>
#include <vector>
using namespace std;
char convert(int a) {
    if ((a >= 0) && (a < 10))return(char)a + 48;
    else return (char)a + 55;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, B;
    cin >> N >> B;
    vector<int> vec;
    if (B > N)cout << convert(N);
    else{
    while (1) {
        vec.push_back(N % B);
        N /= B;
        if (N < B) {
            vec.push_back(N); 
            break;
        }
    }
    for (int i = vec.size()-1; i >= 0; i--) {
        cout << convert(vec[i]);
    }
    }
}