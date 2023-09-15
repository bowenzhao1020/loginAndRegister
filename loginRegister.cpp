#include <iostream>
#include <fstream>
#include <string>
#include<unordered_map>
#include<unordered_set>

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

bool validUserName(string str) {
    for(auto &ch : str) {
        if((ch < 'a' || ch > 'z')
        && (ch < 'A' || ch > 'Z')
        && (ch < '0' || ch > '9')
        || ch == ' ') {
            return false;
        }
    }
    return true;
}

bool validPassword(string str) {
    string special = "!?@#$%&*<>,.";
    unordered_set<char> speicalSet;
    for(auto &ch : special) {
        speicalSet.insert(ch);
    }
    for(auto &ch : str) {
        if((ch < 'a' || ch > 'z')
        && (ch < 'A' || ch > 'Z')
        && (ch < '0' || ch > '9')
        && (!speicalSet.count(ch))
        || ch == ' ') {
            return false;
        }
    }
    return true;
}

int main() {
    unordered_map<string, ofstream> data;
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
        bool validUn = false, validPw = false;
        while(!validUn) {
            cout << "Enter A Valid User Name:\n" 
            << "(the user name should only contain lower case, upper case letter, and digits)" << endl;
            cin >> userName;
            cout << userName << endl;
            validUn = validUserName(userName);
        }
        while(!validPw) {
            cout << "Enter A Valid Password:\n"
            << "(the password should only contain lower case, upper case letter, digits, and special characters !?@#$%&*<>,.)" << endl;
            cin >> password;
            cout << password << endl;
            validPw = validPassword(password);
        }

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