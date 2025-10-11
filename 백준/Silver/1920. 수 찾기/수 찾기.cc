#include <iostream>
#include <map>
#include <set>

using namespace std;

int N, T;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    //cin >> T;
    //while (T--)
    //{
        cin >> N;
        set<int> s;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            s.insert(a);
        }

        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            if (s.count(a))
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
            cout << '\n';
        }
    // }
}