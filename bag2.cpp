#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weights(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
        cin >> weights[i];

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1000000));
    dp[0][0] = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < w + 1; j++) {
            if (j - weights[i] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + weights[i]);
            }
        }
    }
    int max_w = -1000000;
    for (int k = 0; k < w + 1; k++)
        max_w = max(max_w, dp[n][k]);
    cout << max_w << endl;
    return 0;
}
