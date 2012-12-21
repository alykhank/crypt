#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string plaintext, key, ciphertext;
    cout << "Please enter a phrase: ";
    cin >> plaintext;
	ciphertext = plaintext;
    cout << "Please enter a key: ";
    cin >> key;
	for (int i = 0; i < ciphertext.length(); i++) {
		ciphertext.at(i) -= 65;
		ciphertext.at(i) += (key.at(i%key.length())-65);
		ciphertext.at(i) %= 26;
		ciphertext.at(i) += 65;
	}
	cout << ciphertext << endl;
}
