#include <iostream>

using namespace std;

int t, n, k;
int arr[10001];
int coin[21];
void init() {
    for (int i = 0; i <= k; i++) {
        arr[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> coin[i];
        }
        cin >> k;
        arr[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = coin[i]; j <= k; j++) {
                arr[j] += arr[j - coin[i]];
            }
        }
        cout << arr[k] << '\n';
        init();
    }

}
