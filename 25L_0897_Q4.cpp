#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char C[5001];
    string K;

    cout << "Enter text (C-string): ";
    cin.getline(C, 5001);

    cout << "Enter encryption key: ";
    getline(cin, K);

    int n = 0;
    while(C[n] != '\0'){
        n++;
    }
    int keyLen = K.length();

    char encrypted[5001];

    for (int i = 0; i < n; i++) {
        int Ci = C[i];
        int Ki = K[i % keyLen];

        int result = Ci + Ki;

        while (result > 126) result -= 95;
        while (result < 32)  result += 95;

        encrypted[i] = (char)result;
    }
    encrypted[n] = '\0';

    cout << "Encrypted Text:\n" << encrypted << endl;

    char decrypted[5001];

    for (int i = 0; i < n; i++) {
        int Ei = encrypted[i];
        int Ki = K[i % keyLen];
        

        int result = Ei - Ki;

        while (result > 126) result -= 95;
        while (result < 32)  result += 95;

        decrypted[i] = (char)result;
    }
    decrypted[n] = '\0';

    cout << "\nDecrypted Text:\n" << decrypted << endl;

    return 0;
}
