#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void bynumber(ofstream &fout, string &str, long int k, int pos, int n){
    if (pos == n) {
        fout << str;
        return;
    }
    int i = 1;
    long int fact = factorial(n-pos);
    while (k > fact) {
        k -= fact;
        i++;
    }
    str += to_string(i) + ' ';
    bynumber(fout, str, k, pos + 1, n);
}

int main() {
    ifstream fin("bynumbaer.in");
    int n, k;
    fin >> n;
    fin >> k;
    fin.close();
    ofstream fout;
    fout.open("bynember.out");
    string str;
    bynumber(fout, str, k, 0, n);
    fout.close();
    return 0;
}