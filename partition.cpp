#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void recurs(ofstream &fout, int n, string str) {
    if (n == 0) {
        fout << str << endl;
        return;
    }
    int next = 1;
    while (next <= n) {
        str += to_string(next);
        str.push_back(' ');
        n -= next;
        recurs(fout, n, str);
        next++;
    }
}

int main() {
    ifstream fin("partition.in");
    int n;
    fin >> n;
    fin.close();
    ofstream fout;
    fout.open("partition.out");
    string str;
    recurs(fout, n ,str);
    fout.close();
    return 0;
}