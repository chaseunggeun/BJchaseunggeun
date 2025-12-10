#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> cards;
vector<bool> b;
vector<int> scores;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n;

    cards.resize(n);
    b.resize(1000001);
    scores.resize(1000001);

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        b[cards[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        int source = cards[i];

        for (int target = source * 2; target <= 1000000; target += source) {

            if (b[target]) {
                scores[source]++;
                scores[target]--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << scores[cards[i]] << " ";
    }
    cout << "\n";
}