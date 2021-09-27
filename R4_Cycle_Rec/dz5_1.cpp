#include <iostream>
using namespace std;

double fact(int N)
{
	if (N < 0) 
		return 0; 
	if (N == 0) 
		return 1; 
	else 
		return N * fact(N - 1); 
}
int main() {
	int n;
	float u, v;
	cin >> n >> u >> v;
	float a1 = u, a_n1 = a1, a_n; //a(n-1); a(n)
	float b1 = v, b_n1 = b1, b_n; // b(n-1); b(n)
	double res = a1 * b1 / 2;
	for (int i = 2; i <= n; i++) {	
		a_n = 2 * b_n1 + a_n1;
		b_n = 2 * a_n * a_n + b_n1;
		res += (a_n * b_n) / fact(i + 1);
		a_n1 = a_n;
		b_n1 = b_n;

		cout << a_n << "\n" << b_n << "\n" << res << "\n";
	}
	//cout << "Sum: " << sum;
}