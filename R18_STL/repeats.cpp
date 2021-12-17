#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {

	int n;
	cout << "How many numbers do you have?" << endl;
	cin >> n;
	vector<int> numbers;
	for (int i = 0; i<n; i++){
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	int prev = numbers[0];
	cout << numbers[0] << " ";
	for (auto num : numbers) {
		if (num != prev)
			cout << num << " ";
		prev = num;
	}
	return 0;
}
