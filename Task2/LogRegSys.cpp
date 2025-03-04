#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ofstream file;
    file.open(username + ".txt");
    file << username << endl;
    file << password << endl;
    file.close();

    cout << "Registration Successful!" << endl;
}

bool loginUser() {
    string username, password, u, p;
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (file.is_open()) {
        getline(file, u);
        getline(file, p);
        file.close();
        if (u == username && p == password) {
            cout << "Login Successful!" << endl;
            return true;
        } else {
            cout << "Invalid Credentials!" << endl;
            return false;
        }
    } else {
        cout << "User does not exist!" << endl;
        return false;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}