/* http://pl.spoj.com/problems/FR_02_16/
    Dominik Nowogórski
    01-08-2017
*/

#include <iostream>
#include <algorithm>
#include <vector>

class Student {

private:
    int number, year, month, day;
    int countYear(std::string date);
    int countMonth(std::string date);
    int countDay(std::string date);

public:
    Student(std::string date, int n);
    int getYear();
    int getMonth();
    int getDay();
    int getNumber();

};

int Student::countYear(std::string date) {
    int y = 1000*(date[0] - 48) + 100*(date[1] - 48) + 10*(date[2] - 48) + date[3] - 48;
    return y;
}

int Student::countMonth(std::string date) {
    int m = 10 * (date[5] - 48) + date[6];
    return m;
}

int Student::countDay(std::string date) {
    int d = 10 * (date[8] - 48) + date[9];
    return d;
}

Student::Student(std::string date, int n) {
    number = n;
    year = countYear(date);
    month = countMonth(date);
    day = countDay(date);
}

int Student::getYear() {
    return year;
}

int Student::getMonth() {
    return month;
}

int Student::getDay() {
    return day;
}

int Student::getNumber() {
    return number;
}

bool comparator(Student A, Student B) {
    if (A.getYear() > B.getYear()) {
        return false;
    }
    if (A.getYear() == B.getYear()) {
        if (A.getMonth() > B.getMonth()) {
            return false;
        }
        if (A.getMonth() == B.getMonth()) {
            if (A.getDay() > B.getDay()) {
                return false;
            }
            if (A.getDay() == B.getDay()) {
                if (A.getNumber() > B.getNumber()){
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::vector<Student> students;
        Student* s;
        std::cin >> n;
        for (int j = 0; j < n; j++){
            int nr;
            std::string date;
            std::cin >> nr >> date;
            s = new Student(date, nr);
            students.push_back(*s);
            delete s;
        }
        std::sort(students.begin(), students.end(), comparator);

        for (int j = 0; j < n; j++) {
            std::cout << students[j].getNumber() << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
