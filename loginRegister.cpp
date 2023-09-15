#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIn() {
    string userName, password, un, pw;
    cout << "Enter Your User Name: ";
    cin >> userName;
    cout << "Enter Your Password: ";
    cin >> password;

    ifstream read(userName + ".txt");
    getline(read, un);
    getline(read, pw);

    return un == userName && pw == password;
}

int main() {
    char choice;
    cout << "Enter your choice:\n1.Login\n2.Register" << endl;
    cin >> choice;
    if(choice == '1') {
        bool stats = isLoggedIn();
        if(stats) {
            cout << "Successfully Logged In" << endl;
            system("PAUSE");
        }
        else {
            cout << "Failed Logged In" << endl;
            system("PAUSE");
        }
    }
    else if(choice == '2') {
        string userName, password;
        cout << "Enter A Valid User Name: ";
        cin >> userName;
        cout << "Enter A Valid Password: ";
        cin >> password;

        ofstream file;
        file.open(userName + ".txt");
        file << userName << endl << password;
        file.close();

        main();
    }
    else {
        cout << "Invalid Input" << endl;
    }

    
}