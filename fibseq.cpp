#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void without2(ofstream &fout, string str, int n, bool is_prev_one){
    if (n == 0) {
        str.pop_back();
        fout << str << endl;
        return;
    }
    str.push_back('0');
    str.push_back(' ');
//    if (n != 1)
//        str.push_back(' ');
    without2(fout, str, n - 1, false);
    if (!is_prev_one) {
        str[str.length() - 2] = '1';
        without2(fout, str, n - 1, true);
    }
}

int main() {
    ifstream fin("fibseq.in");
    int n;
    fin >> n;
    fin.close();
    ofstream fout;
    fout.open("fibseq.out");
    string str;
    without2(fout, str, n ,false);
    fout.close();
    return 0;
}