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

	for (int i = 0; i < count-1; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			if (arr[j] > arr[j+1]) {
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
		// std::cout << i << " : ";
		// print_arr(arr);
	}

	print_arr(arr);
	return 0;
}