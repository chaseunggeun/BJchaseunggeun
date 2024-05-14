#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[6];
    int t=1;
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
        if (i == 2) {
            t = 2;
        }
        if (i == 5) {
            t = 8;
        }
        arr[i] = t - arr[i];
    }
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

}