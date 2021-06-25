#include <iostream>
#include <vector>

int main()
{
	long long n, m;
	scanf("%lld %lld",&n, &m);
	std::vector<long long> arr(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	long long hostel_number = 1;
	unsigned long long acummulate = 0;
	for (int i = 0; i < m; i++) {
		long long letter;
		scanf("%lld", &letter);
		letter -= acummulate;
		while (letter > arr[hostel_number - 1]) {
			acummulate += arr[hostel_number - 1];
			letter -= arr[hostel_number - 1];
			hostel_number += 1;
		}
		printf("%d %lld\n", hostel_number, letter);
	}
	return 0;
}