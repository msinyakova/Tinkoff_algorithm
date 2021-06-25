#include <iostream>
#include <vector>

void print_arr(std::vector<int> arr)
{
	for (int i = 0; i < arr.size(); i ++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	int count;
	std::cin >> count;
	std::vector<int> arr(count);

	for (int i = 0; i < count; i++) {
		std::cin >> arr[i];
	}

	for (int i = 1; i < count; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		// std::cout << i << " : ";
		// print_arr(arr);
	}

	print_arr(arr);
	return 0;
}
