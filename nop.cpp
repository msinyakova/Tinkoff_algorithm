#include <iostream>
#include <vector>

using namespace std;

int main() {
    long int n, m;
    cin >> n;
    vector<long int> first(n + 1);
    for (int i = 1; i < n + 1; i++) {
        scanf("%ld", &first[i]);
    }
    cin >> m;
    vector<long int> second(m + 1);
    for (int i = 1; i < m + 1; i++) {
        scanf("%ld", &second[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (first[i] == second[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[n][m];
    return 0;
}