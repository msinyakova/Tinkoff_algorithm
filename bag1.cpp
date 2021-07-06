#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weights(n + 1);
    for (int i = 1; i < n + 1; i++)
        cin >> weights[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(w + 1, false));
    dp[0][0] = true;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < w + 1; j++) {
            if (j - weights[i] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - weights[i]];
            }
        }
    }
    if (dp[n][w]) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
