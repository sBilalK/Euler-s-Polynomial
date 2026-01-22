#include <iostream>
using namespace std;

#define W "\033[0m"
#define R "\033[31m"
#define G "\033[32m"
#define Y "\033[33m"
#define B "\033[36m"


bool isPrime(long long sayi) {

    if (sayi <= 1) return false;
    if (sayi <= 3) return true;
    if (sayi % 2 == 0 || sayi % 3 == 0) return false;

    for (long long i = 5; i * i <= sayi; i += 6) {
        if (sayi % i == 0 || sayi % (i + 2) == 0)
            return false;
    }
    return true;
}


int main() {

    double possibility;
    double possibility_not;
    double p_piece = 0;
    double pnt_piece = 0;
    int choose;
    int girdi;
    long long sayi;

    do
    {
        cout << "\n\n\nWelcome to" << B << " Salih Bilal Korkmaz's " << W << "Project\n";
        cout << "This is Euler's Formula (n^2 + n + 41)\n\n";
        cout << "0. For Exit\n";
        cout << "1. Pick One Number\n";
        cout << "2. Try 0 <= 10000\n";
        cout << B "Choose: "<< W;
        cin >> choose;
    
        if (choose >= 0 && choose <= 2) {
            break;
        }

        else
        {
            cout << R << "\nInvalid Input\n" << W;
            cout << "Please Try Again";
        }
    } while (true);

    switch (choose) {

    case 0:
        cout << "\nEXIT";
        break;

    case 1:
        cout << "\nYou chose the first option\n";
        do{  
            cout << "Please enter n: ";
            cin >> girdi;
            if (girdi >= 0 && girdi <= 10000) {
                break;
            }
            else{
                cout << R << "\nInvalid Input\n" << W;
                cout << "Please Try Again\n";
            }
        } while (true);

        sayi = (girdi * girdi) + girdi + 41;

        if (isPrime(sayi))
            cout << G << "\nOutput is PRIME: " << W << sayi;
        else
            cout << R << "\nOutput is NOT prime: " << W << sayi;

        break;

    case 2:
        cout << "\nYou chose the second option\n";
        cout << "Trying values from 0 to 10000...\n";

        for (girdi = 0; girdi <= 10000; girdi++) {
            sayi = (girdi * girdi) + girdi + 41;

            if (isPrime(sayi)) {
                //cout << endl;
                cout << "n = " << girdi << " -> " << sayi << G << " (prime)\n" << W;
                p_piece = p_piece + 1;
            }

            else {
                //cout << endl;
                cout << "n = " << girdi << " -> " << sayi << R << " (not prime)\n" << W;
                pnt_piece = pnt_piece + 1;
            }
        }
        cout << "There are " << G << p_piece << W << " Prime Numbers\n";
        cout << "There are " << R << pnt_piece << W << " non Prime Numbers\n";
        possibility = (p_piece / 10001) * 100;
        possibility_not = (pnt_piece / 10001) * 100;
        cout << "The Possibility of choosing a random number that " << G << "is prime : " << W << "% " << possibility << endl;
        cout << "The Possibility of choosing a random number that " << R << "isn't prime : " << W << "% " << possibility_not << endl;
        break;
    }

    cout << "\n\n";
    return 0;
}