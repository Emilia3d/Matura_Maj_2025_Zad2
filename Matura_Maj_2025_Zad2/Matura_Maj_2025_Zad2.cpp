#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

//Zad. 2.1
bool czyPalindrom(string s) {
    int i = 0, j = s.size()-1;
    while(i<j){
        if (s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}

int main() {

    ifstream fin("symbole_przyklad.txt");
    ofstream fout("wyniki2_1.txt");


    string linia;
    while (getline(fin, linia)) {
        if (czyPalindrom (linia)) {
            fout << linia << "\n";
        }        
    }
    return 0;
}