#include <iostream>
#include <vector>
#include <string>

const int N = 1000000; 

int main()
{
	std::vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}

	int left = 0;
	int right = N;
	while (right - left > 1) {
		int middle = (right + left) / 2;
		printf("%d\n", arr[middle]);
		fflush(stdout);

		char str;
		scanf("%s", &str);
		if (str == '<') {
			right = middle;
		} else {
			left = middle;
		}
	}
	printf("! %d\n", arr[left]);
	return 0;
}