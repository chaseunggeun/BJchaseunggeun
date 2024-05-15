#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class member {
public:
	int age;
	int count;
	string name;
	void getter(int age, string name, int count) {
		this->age = age;
		this->name = name;
		this->count = count;
	}
};

bool cmp(member a, member b) {
	if (a.age != b.age) {
		return a.age < b.age;
	}
	return a.count < b.count;

}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<member> vec;
	for (int i = 0; i < N; i++) {
		int a;
		string b;
		member m;
		cin >> a >> b;
		m.getter(a, b, i);
		vec.push_back(m);
	}
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << vec[i].age << " " << vec[i].name << "\n";
	}
}