#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
map<string, int> m;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        m.insert({ a, i });
    }
    
    vector<string> vec;
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        string a;
        cin >> a;
        if (m.find(a) != m.end()) {
            vec.push_back(a);
            cnt++;
        }
    }
    sort(vec.begin(), vec.end());
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        cout << vec[i] << "\n";
    }
    
}