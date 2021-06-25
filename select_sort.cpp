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
		int min = arr[i];
		int pos = i;
		for (int j = i+1; j < count; j++) {
			if (arr[j] < min) {
				min = arr[j];
				pos = j;
			}
		}
		arr[pos] = arr[i];
		arr[i] = min;
		// std::cout << i << " : ";
		// print_arr(arr);
	}

	print_arr(arr);
	return 0;
}
