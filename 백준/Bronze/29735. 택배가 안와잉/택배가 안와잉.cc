#include <iostream>

using namespace std;

    int SH, SM;
    int EH, EM;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    char c;

    cin >> SH >> c >> SM;
    cin >> EH >> c >> EM;

    int n, t;
    cin >> n >> t;

    int ST = SH * 60 + SM;
    int ET = EH * 60 + EM;

    int D = 0;
    int T = n + 1;
    int C = ST;

    for (int i = 0; i < T; ++i) {
        if (C + t >= ET) {
            D++;
            C = ST + t;
        }
        else {
            C += t;
        }
    }

    int AH = C / 60;
    int AM = C % 60;

    cout << D << "\n";

    if (AH < 10) {
        cout << "0";
    }
    cout << AH << ":";

    if (AM < 10) {
        cout << "0";
    }
    cout << AM << "\n";
}