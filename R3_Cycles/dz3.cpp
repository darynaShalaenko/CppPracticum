#include <iostream>
using namespace std;

int main() {
	int n, x;
	float result=0;
	cin >> n;
	cin >> x;
	for (int i = 0; i <= n; i++) {
		result += 1 / pow((x * x + 1), i);
	}
	cout << "Res: " << result;
}