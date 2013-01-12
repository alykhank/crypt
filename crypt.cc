#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int main(int argc, char* argv[])
{
    string plaintext, key, ciphertext;
    cout << "Please enter a phrase: ";
    cin >> plaintext;
	ciphertext = plaintext;
    cout << "Please enter a key: ";
    cin >> key;

    /* Always convert key to lowercase. */
    for (int i = 0; i < key.length(); i++) {
        assert((65 <= key.at(i) && key.at(i) <= 90) || (97 <= key.at(i) && key.at(i) <= 122));
        if (65 <= key.at(i) && key.at(i) <= 90) {
        } else if (97 <= key.at(i) && key.at(i) <= 122) {
            key.at(i) = key.at(i) - 32;
        }
    }

    /* Compute ciphertext based on alphabetic rotation with key mod26. */
	for (int i = 0; i < ciphertext.length(); i++) {
        assert((65 <= ciphertext.at(i) && ciphertext.at(i) <= 90) || (97 <= ciphertext.at(i) && ciphertext.at(i) <= 122));
        if (65 <= ciphertext.at(i) && ciphertext.at(i) <= 90) {
            ciphertext.at(i) -= 65;
            ciphertext.at(i) += (key.at(i%key.length())-65);
            ciphertext.at(i) %= 26;
            ciphertext.at(i) += 65;
        } else if (97 <= ciphertext.at(i) && ciphertext.at(i) <= 122) {
            ciphertext.at(i) -= 97;
            ciphertext.at(i) += (key.at(i%key.length())-65);
            ciphertext.at(i) %= 26;
            ciphertext.at(i) += 65;
        }
	}
	cout << "Ciphertext: " << ciphertext << endl;
}
