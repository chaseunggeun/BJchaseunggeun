#include <iostream>

using namespace std;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int M;
    cin >> M;
    bool arr[21] = { 0, };
    for (int i = 0; i < M; i++) {
        string a;
        int b;
        cin >> a;
        if (a == "add") {
            cin >> b;
            arr[b] = true;
        }
        else if (a == "remove") {
            cin >> b;
            arr[b] = false;
        }
        else if (a == "check") {
            cin >> b;
            if (arr[b] == true)cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (a == "toggle") {
            cin >> b;
            if (arr[b] == true)arr[b] = false;
            else arr[b] = true;
        }
        else if (a == "all") {
            for (int j = 1; j <= 20; j++) {
                arr[j] = true;
            }
        }
        else {
            for (int j = 1; j <= 20; j++) {
                arr[j] = false;
            }
        }
    }
}
