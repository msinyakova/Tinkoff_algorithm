#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string strS, strT;
    cin >> strS;
    cin >> strT;
    int p = 30;
    int n = strT.size();
    long long int m = 1e+9 + 7;
    vector<long long int> hs(strS.size(), 0);
    hs[0] = int(strS[0]);
//    cout << hs[0] << ' ';
    long int hash_t = 0;
    vector<long long int> pow_p(strS.size(), 1);
    for(int i = 1; i < strS.size(); ++i) {
        pow_p[i] = pow_p[i - 1] * p % m;
        hs[i] = (pow_p[i] * int(strS[i]) + hs[i - 1]) % m;
//        cout << hs[i] << ' ';
    }
    for(int i  = 0; i < n; i++) {
        hash_t = (hash_t + pow_p[i] * int(strT[i])) % m;
    }
    cout << endl << "hash T = " << hash_t << endl;
    if (hs[n - 1] == hash_t) {
        cout << 0 << ' ';
    }
    for(int i = 1; i < strS.size() - n + 1; i++) {
        cout << (m + hs[i + n - 1] - hs[i - 1]) % m << ' ';
        cout << hash_t * pow_p[i] % m << endl;
        if ((m + hs[i + n - 1] - hs[i - 1]) % m == hash_t * pow_p[i] % m) {
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}