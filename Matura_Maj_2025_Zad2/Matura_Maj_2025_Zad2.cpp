#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Zad. 2.1
bool czyPalindrom(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

void Zadanie2_1() {
    ifstream fin("symbole.txt");

    string linia;
    while (getline(fin, linia)) {
        if (czyPalindrom(linia)) {
            cout <<"Zad 2.1 "<< linia << "\n";
        }
    }
    fin.close();
}
//Zad. 2.2
const int MAXN = 2000, MAXM = 12;
char A[MAXN][MAXM];

ifstream fin("symbole.txt");

void WczytajTablice()
{
    char znak;
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXM; j++)
        {
            fin >> znak;
            A[i][j] = znak;
        }
    }
    fin.close();
}
void Zadanie2_2()
{
    WczytajTablice();
    int licznik = 0;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXM; ++j) {
            char c = A[i][j];  // środkowy znak
            if (c == A[i - 1][j - 1] && c == A[i - 1][j] && c == A[i - 1][j + 1] &&
                c == A[i][j - 1]    && c == A[i][j + 1] &&
                c == A[i + 1][j - 1] && c == A[i + 1][j] && c == A[i + 1][j + 1])
            {
                cout << "Zad 2.2 " << (i + 1) << ' ' << (j + 1) << ' ' << c << '\n';
                ++licznik;
            }
        }
    }
    cout << "Zad 2.2 " << licznik << "\n";
}
void Zadanie2_3()
{
    long long max = 0;
    for (int i = 0; i < MAXN; ++i) {
        long long liczba = 0;
        for (int j = 0; j < MAXM; ++j) {
            int cyfra;
            char znak = A[i][j];
            if (znak == 'o') cyfra = 0;
            if (znak == '+') cyfra = 1;
            if (znak == '*') cyfra = 2;
            liczba = liczba * 3 + cyfra;
        }
        if (liczba > max) max = liczba;
    }
    cout << "Zad 2.3 " << max << "\n";
}
void Zadanie2_4() {
    cout << "zadanie 2.3\n";

    long long suma = 0;
    for (int i = 0; i < MAXN; ++i) {
        long long liczba = 0;
        for (int j = 0; j < MAXM; ++j) {
            int cyfra;
            char znak = A[i][j];
            if (znak == 'o') cyfra = 0;
            if (znak == '+') cyfra = 1;
            if (znak == '*') cyfra = 2;
            liczba = liczba * 3 + cyfra;
        }
        suma = suma + liczba;
    }
    cout << "Zad 2.4 " << suma << endl;
    string wynik = "";
    while (suma)
    {
        int cyfra = suma % 3;
        if (cyfra == 0) wynik = 'o' + wynik;
        if (cyfra == 1) wynik = '+' + wynik;
        if (cyfra == 2) wynik = '*' + wynik;
        suma /= 3;
    }
    cout << "Zad 2.4 " << wynik << endl;
}

int main() {
    int licznik = 0;

    Zadanie2_1();    
    Zadanie2_2();
    Zadanie2_3();
    Zadanie2_4();

    return 0;
}
