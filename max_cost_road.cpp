#include <iostream>
#include <vector>

// void print_matrix(auto arr, int n, int m)
// {
// 	printf("\n");
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			printf("%c ", arr[i][j]);
// 		}
// 		printf("\n");
// 	} 
// }


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	// initialized arrays
	std::vector<std::vector<long long> > dp;
	std::vector<std::vector<char> > opt;
	for (int i = 0; i < n; i++) {
		std::vector<long long> dp_help(m, 0);
		std::vector<char> opt_help(m, 'D');
		dp.push_back(dp_help);
		opt.push_back(opt_help);
	}
	// read data
	std::vector<std::vector<int> > money;
	for (int i = 0; i < n; i++) {
		std::vector<int> help;
		for (int j = 0; j < m; j++) {
			int k;
			scanf("%d", &k);
			help.push_back(k);
		}
		money.push_back(help);
	}
	// dynamic
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = money[i][j];
				opt[i][j] = 'D';
			} else if (i == 0) {
				dp[i][j] = dp[i][j-1] + money[i][j];
				opt[i][j] = 'R';
			} else if (j == 0) {
				dp[i][j] = dp[i-1][j] + money[i][j];
				opt[i][j] = 'D';
			} else {
				if (dp[i-1][j] >= dp[i][j-1]) {
					dp[i][j] = dp[i-1][j] + money[i][j];
					opt[i][j] = 'D';
				} else {
					dp[i][j] = dp[i][j-1] + money[i][j];
					opt[i][j] = 'R';
				}
			}
		}
	}
	// print_matrix(opt, n, m);
	printf("%lld\n", dp[n-1][m-1]);
	// combine optimum road
	std::vector<char> road(n + m - 2,'W');
	int i = n - 1;
	int j = m - 1;
	for (int k = n+m-3; k >= 0; k--) {
		if (opt[i][j] == 'D') {
			road[k] = 'D';
			i--;
		} else {
			road[k] = 'R';
			j--;
		}
	}
	for (int k = 0; k < n+m-2; k++)
		std::cout << road[k] << ' ';
	std::cout<<std::endl;
	return 0;
}