#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[100][100] = { {0, }, };
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < a + 10; j++) {
            for (int k = b; k < b + 10; k++) {
                arr[j][k]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (arr[i][j] > 0)cnt++;
        }
    }
    cout << cnt;
}