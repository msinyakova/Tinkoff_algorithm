#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weights(n + 1, 0);
    vector<int> cost(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
        cin >> weights[i];
    for (int i = 1; i < n + 1; i++)
        cin >> cost[i];

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1000000));
    vector<vector<vector<int>>> elems(n + 1, vector<vector<int>>(w + 1));
    dp[0][0] = 0;
    vector<int> vec1;
    elems[0][0] = vec1;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < w + 1; j++) {
            if (j - weights[i] < 0) {
                dp[i][j] = dp[i - 1][j];
                elems[i][j] = elems[i - 1][j];
            } else {
                if (dp[i - 1][j - weights[i]] + cost[i] > dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j - weights[i]] + cost[i];
                    elems[i][j] = elems[i - 1][j - weights[i]];
                    elems[i][j].push_back(i);
                } else {
                    dp[i][j] = dp[i - 1][j];
                    elems[i][j] = elems[i - 1][j];
                }
            }
        }
    }
    int max_w = -1000000;
    int max_k = 0;
    for (int k = 0; k < w + 1; k++) {
        if (max_w < dp[n][k]) {
            max_w = dp[n][k];
            max_k = k;
        }
    }
    cout << elems[n][max_k].size() << endl;
    for (int number : elems[n][max_k]){
        cout << number << ' ';
    }
    cout << endl;
    return 0;
}
