#include <iostream>
#include <vector>

bool bin_search(std::vector<int> arr, int elem)
{
	int left = -1;
	int right = arr.size();
	while (right - left > 1) {
		int middle = (right + left) / 2;
		if (arr[middle] < elem)
			left = middle;
		else
			right = middle;
	}
	return arr[right] == elem;
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
		if (bin_search(arr, elem))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}