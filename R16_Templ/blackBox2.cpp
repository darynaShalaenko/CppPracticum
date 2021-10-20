#include <iostream>
#include <queue>
#include <vector>

class BlackBox {
private:
	int size = 0;
	std::queue<int> que = std::queue<int>();
public:
	BlackBox() {}

	int min(int k) {
		std::vector<int> buf;
		for (int i = 0; i < size; i++) {
			buf.push_back(que.front());
			que.pop();
		}
		std::sort(buf.begin(), buf.end());
		for (int i = 0; i < size; i++) {
			que.push(buf[i]);
		}
		return buf[k - 1];
	}

	void push(int a) {
		que.push(a);
		size++;
	}
};

int main() {
	BlackBox bb = BlackBox();
	bb.push(0);
	bb.push(3);
	bb.push(2);
	bb.push(2);
	bb.push(2);
	std::cout << bb.min(2);
	std::cout << bb.min(1);
	std::cout << bb.min(3);
}