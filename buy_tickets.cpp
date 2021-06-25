#include <iostream>
#include <vector>

// void print_arr(std::vector<long long> arr)
// {
// 	for (int i = 0; i < arr.size(); i ++) {
// 		std::cout << arr[i] << ' ';
// 	}
// 	std::cout << std::endl;
// }

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<std::vector<int> > time;
	for (int i = 0; i < n; i++) {
		std::vector<int> v(3);
		for (int j = 0; j < 3; j++) {
			scanf("%d", &v[j]);
		}
		time.push_back(v);
	}
	std::vector<long long> dp(n);
	dp[0] = time[0][0];
	if (n == 1) {
		printf("%lld\n", dp[0]);
		return 0;
	}
	dp[1] = time[0][1] < dp[0] + time[1][0] ? time[0][1] : dp[0] + time[1][0];
	if (n == 2) {
		printf("%lld\n", dp[1]);
		return 0;
	}
	long long help = time[0][2] < dp[0] + time[1][1] ? time[0][2] : dp[0] + time[1][1];
	dp[2] = help < dp[1] + time[2][0] ? help : dp[1] + time[2][0];
	
	for (int i = 3; i < n; i++) {
		long long help = dp[i-1] + time[i][0] < dp[i-2] + time[i-1][1] ? dp[i-1] + time[i][0] : dp[i-2] + time[i-1][1];
		dp[i] = help < dp[i-3] + time[i-2][2] ? help : dp[i-3] + time[i-2][2];
	}
	printf("%lld\n", dp[n-1]);
	// print_arr(dp);
	return 0;
}
