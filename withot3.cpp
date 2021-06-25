#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr(3);
	arr[0] = 2;
	arr[1] = 4;
	arr[2] = 7;
	if (n == 1 || n == 2 || n == 3) {
		std::cout << arr[n - 1] << std::endl;
		return 0;
	}
	for (int i = 3; i < n; i++) {
		int arr_new = arr[0] + arr[1] + arr[2];
		arr[0] = arr[1];
		arr[1] = arr[2];
		arr[2] = arr_new;
	}
	std::cout << arr[2] << std::endl;
	return 0;
}