#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("nextperm.in");
    long int n;
    fin >> n;
    vector<long int> permutation(n);
    for (long int i = 0; i < n; i++) {
        fin >> permutation[i];
    }
    fin.close();

    vector<long int> help(n, 0);
    long int stop_elem = 0;
    for (long int i = n - 1; i > 0; i--) {
        if (permutation[i] < permutation[i - 1]) {
            help[n - 1 - i] = permutation[i];
        } else {
            help[n - 1 - i] = permutation[i];
            stop_elem = i - 1;
            break;
        }
    }
    ofstream fout;
    fout.open("nextperm.out");
    if (stop_elem == 0) {
        help[n - 1] = permutation[0];
        for (long int i = 0; i < n; i++) {
            fout << help[i] << ' ';
        }
        return 0;
    }
    for (long int i = 0; i < stop_elem; i++)
        fout << permutation[i] << ' ';
    for (long int i = 0; i < n; i++) {
        if (help[i] > permutation[stop_elem]) {
            long int swap = help[i];
            help[i] = permutation[stop_elem];
            permutation[stop_elem] = swap;
            break;
        }
    }
    fout << permutation[stop_elem] << ' ';
    long int  i = 0;
    while (help[i] != 0) {
        fout << help[i] << ' ';
        i++;
    }
    fout << endl;
    fout.close();
    return 0;
}