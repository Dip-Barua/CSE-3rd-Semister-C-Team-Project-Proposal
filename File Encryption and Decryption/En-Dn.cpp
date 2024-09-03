#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int getMenuSelection();  // Function to get the menu selection
void encrypt(const string& filename);  // Encrypt a file
void decrypt(const string& filename);  // Decrypt a file

int main() {
    int menu;  // Menu selection
    string file;  // File name

    while (true) {
        menu = getMenuSelection(); // Asks user what function to use.

        if (menu == 1) { // Option to encrypt a file.
            cout << "Enter the file name (File should be in the same folder): ";
            cin >> file;
            encrypt(file);
        } 
        else if (menu == 2) { // Option to decrypt a file.
            cout << "Enter the file name (File should be in the same folder): ";
            cin >> file;
            decrypt(file);
        } 
        else if (menu == 3) { // Option to end the program.
            cout << "Goodbye Agent" << endl;
            return 0;
        } 
        else {
            cout << "Invalid selection. Please try again." << endl;
        }
    }
}

int getMenuSelection() { // Menu selection function.
    int selection;
    cout << "Select any option from below:" << endl;
    cout << "1. Encrypt a file" << endl;
    cout << "2. Decrypt a file" << endl;
    cout << "3. Quit this program" << endl;
    cout << "Enter your choice: ";
    cin >> selection;

    switch (selection) {
        case 1:   cout << "You have selected to encrypt a file... " << endl;
                  break;
        case 2:   cout << "You have selected to decrypt a file... " << endl; 
                  break;
        case 3:   cout << "You have selected to quit this program..." << endl; 
                  break;
        default:  cout << "Invalid entry, please try again... " << endl;                
                  return getMenuSelection();
    }
    return selection;
}

void encrypt(const string& filename) { // Encryption function.
    ifstream infile(filename, ios::binary); // Open in binary mode
    if (!infile) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    ofstream outfile("encrypted_" + filename, ios::binary); // Open in binary mode
    if (!outfile) {
        cerr << "Error opening file for writing: encrypted_" << filename << endl;
        return;
    }

    char buffer;
    while (infile.get(buffer)) { // Read one byte at a time
        buffer += 2;  // Encrypt the byte
        outfile.put(buffer); // Write the encrypted byte
    }

    infile.close();
    outfile.close();
}

void decrypt(const string& filename) { // Decryption function.
    ifstream infile(filename, ios::binary); // Open in binary mode
    if (!infile) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    ofstream outfile("decrypted_" + filename, ios::binary); // Open in binary mode
    if (!outfile) {
        cerr << "Error opening file for writing: decrypted_" << filename << endl;
        return;
    }

    char buffer;
    while (infile.get(buffer)) { // Read one byte at a time
        buffer -= 2;  // Decrypt the byte
        outfile.put(buffer); // Write the decrypted byte
    }

    infile.close();
    outfile.close();
}
