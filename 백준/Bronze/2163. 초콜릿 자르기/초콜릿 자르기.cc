#include <iostream>


using namespace std;

int N, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	cout << (N - 1) + ((M - 1) * N) << "\n";
}