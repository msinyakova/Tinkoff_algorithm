#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	int min = 10000;
	int max = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	std::vector<int> dict(max - min + 1);
	for (int i = 0; i < dict.size(); i++)
		dict[i] = 0;
	for (int i = 0; i < n; i++)
		dict[arr[i] - min] += 1;
	for (int i = 0; i < dict.size(); i++) {
		for (int j = 0; j < dict[i]; j++)
			std::cout << i + min << ' ';
	}
	std::cout << std::endl;
	return 0;
}
