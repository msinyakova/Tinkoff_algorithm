#include <iostream>
#include <vector>

int bin_search(std::vector<int> arr, int elem)
{
	int left = 0;
	int right = arr.size()-1;
	while (right - left > 1) {
		int middle = (right + left) / 2;
		if (arr[middle] < elem)
			left = middle;
		else
			right = middle;
		// if (arr[right] - arr[left] == 0)
		// 	break;
	}
	if ((elem - arr[left]) <= (arr[right] - elem))
		return arr[left];
	else
		return arr[right];
}


int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < k; i++) {
		int elem;
		scanf("%d", &elem);
		printf("%d\n", bin_search(arr, elem));
	}
	return 0;
}