#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        vec[i] = i + 1;
    }

    vector<int> result;
    int index = 0;
    while (!vec.empty()) {
        index = (index + K - 1) % vec.size();
        result.push_back(vec[index]);
        vec.erase(vec.begin() + index);
    }

    cout << "<";
    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ", ";
    }
    cout << result.back();
    cout << ">";
}
