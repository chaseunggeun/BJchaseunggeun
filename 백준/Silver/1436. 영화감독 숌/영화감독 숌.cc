#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int i = 666, ver = 0;
    while (true) {
        string a = to_string(i);
        for (int j = 0; j < a.length() - 2; j++) {
            if (a[j] == '6' && a[j + 1] == '6' && a[j + 2] == '6') {
                ver++;
                break;
            }
        }
        if (N == ver) {
            cout << i;
            break;
        }
        i++;
    }

}