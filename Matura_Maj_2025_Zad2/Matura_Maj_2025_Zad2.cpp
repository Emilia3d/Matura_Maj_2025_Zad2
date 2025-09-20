#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool czyPalindrom(string s) {
    size_t i = 0, j = s.size();
    while(i<j){
        if (s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}

int main() {

    // pliki wejścia/wyjścia
    ifstream fin("symbole.txt");
    ofstream fout("wyniki2_1.txt");

    // twój kod tu
    string linia;
    while (getline(fin, linia)) {
        if (czyPalindrom(linia)) {
            fout << linia << "\n";
        }
    }

    return 0;
}