/*  pl.spoj.com/problems/FR_07_03/
    Dominik Nowogórski
    12-09-2017
*/

#include <iostream>
#include <map>
#include <algorithm>

bool isIDFree(std::string ID, std::map<std::string, std::string> m) {
    if (m.count(ID)) {
        return false;
    }
    return true;
}

bool isUpperCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}

bool isLowerCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

bool isLetter(char c) {
    return isUpperCase(c) || isLowerCase(c);
}

bool isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool isSpecialSign(char c) {
    if ( !isLetter(c) && !isDigit(c) ) {
        return true;
    }
    return false;
}

bool validateID(std::string ID) {
    int len = ID.length();
    if (len >= 3 && len <= 12) {
        int i;
        for (i = 0; i < len; i++) {
            if ( !(isLetter(ID[i]) || isDigit(ID[i])) ) {
                break;
            }
        }
        if (i != len) {
            return false;
        }
        return true;
    }
    return false;
}

bool validatePass(std::string pass) {
    int len = pass.length();
    if (len >= 5 && len <= 15) {
        int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
        for (int i = 0; i < len; i++) {
            if (isUpperCase(pass[i])) {
                hasUpper++;
            }
            if (isLowerCase(pass[i])) {
                hasLower++;
            }
            if (isDigit(pass[i])) {
                hasDigit++;
            }
            if (isSpecialSign(pass[i])) {
                hasSpecial++;
            }
        }
        if (hasLower && hasUpper && hasDigit && hasSpecial == 1) {
            return true;
        }
    }
    return false;
}

void registration(std::map<std::string, std::string>& m, std::string ID, std::string pass) {
    if ( !(validateID(ID) && validatePass(pass)) ) {
        std::cout << "Blad" << std::endl;
        return;
    }
    if (!isIDFree(ID, m)) {
        std::cout << "Login zajety" << std::endl;
        return;
    }
    m.insert(std::pair<std::string, std::string>(ID, pass));
    std::cout << "Zarejestrowano" << std::endl;
}

void login(std::map<std::string, std::string> m, std::string ID, std::string pass) {
    if (isIDFree(ID, m)) {
        std::cout << "Konto nie istnieje" << std::endl;
        return;
    }
    if (m[ID] != pass) {
        std::cout << "Zle haslo" << std::endl;
        return;
    }
    std::cout << "Zalogowano" << std::endl;
}

int main()
{
    std::map<std::string, std::string> dataBase;
    std::string action;
    int numberOfActions;
    while (std::cin >> action) {
        std::cin >> numberOfActions;
        std::string name, password;
        for (int i = 0; i < numberOfActions; i++) {
            std::cin >> name >> password;
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            if (action == "register") {
                registration(dataBase, name, password);
            }
            if (action == "login") {
                login(dataBase, name, password);
            }
        }
    }
    return 0;
}
