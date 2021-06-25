#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];

		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < n - 1; i ++) {
		count += (arr[i + 1] - arr[i] - 1);
	}
	
	std::cout << count << std::endl;
	return 0;
}