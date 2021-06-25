#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	if (n == 1 || n == 2) {
		std::cout << 1 << std::endl;
		return 0;
	}
	int k_1 = 1;
	int k_2 = 1;
	for (int i = 3; i <= n; i++) {
		int k_next = k_1 + k_2;
		k_1 = k_2;
		k_2 = k_next;
	}
	std::cout << k_2 << std::endl;
	return 0;
}