#include <iostream>
#include <vector>

using namespace std;

class Student {
    public:
    string name;
    string course;
    string studentnumber;
    int age;
};

class StudentData {
    public:
    void addStudent(vector<Student> & students) {
        Student newstudent;
        cout << "Enter student name: ";
        getline(cin, newstudent.name);
        for (char &c : newstudent.name) {
            c = toupper(c);
        }

        cout << "Enter course: ";
        getline(cin, newstudent.course);
        for (char &c : newstudent.course) {
            c = toupper(c);
        }

        cout << "Enter student number: ";
        getline(cin, newstudent.studentnumber);
        for (char &c : newstudent.studentnumber) {
            c = toupper(c);
        }

        cout << "Enter age: ";
        cin >> newstudent.age;
        students.push_back(newstudent);
        cout << "Student added!" << endl;
    }

    void displayStudent(vector<Student> & students) {
        if (!students.empty()) {
            for (int i = 0; i < students.size(); i++) {
            cout << "\nName: " << students[i].name << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Student Number: " << students[i].studentnumber << endl; 
            cout << "Age: " << students[i].age << endl;
            cout << endl;
            }
        } else {
            cout << "No student added!" << endl;
        }
    }
    
    void deleteStudent(vector<Student> & students) {
        cout << "Enter student number to delete: ";
        string studentnumber;
        getline(cin, studentnumber);
        for (char &c : studentnumber) {
        c = toupper(c);
    }

    bool studentFound = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].studentnumber == studentnumber) {
                students.erase(students.begin() + i);
                cout << "Student deleted!" << endl;
                studentFound = true;
                break;
            }
        }
        if (!studentFound) {
        cout << "Student not found! Please input a valid student number." << endl;
        }
    }

    void updateStudent(vector<Student> & students) {
    cout << "Enter student number to update: ";
    string studentnumber;
    getline(cin, studentnumber);
    for (char &c : studentnumber) {
        c = toupper(c);
    }

    bool studentFound = false;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].studentnumber == studentnumber) {
            cout << "Enter new student name: ";
            cin.ignore();
            getline(cin, students[i].name);
            for (char &c : students[i].name) {
                c = toupper(c);
            }

            cout << "Enter new course: ";
            getline(cin, students[i].course);
            for (char &c : students[i].course) {
                c = toupper(c);
            }

            cout << "Enter new student number: ";
            getline(cin, students[i].studentnumber);
            for (char &c : students[i].studentnumber) {
                c = toupper(c);
            }

            cout << "Enter new age: ";
            cin >> students[i].age;

            cout << "Student updated!" << endl;
            studentFound = true;
            break;
        }
    }
    if (!studentFound) {
        cout << "Student not found! Please input a valid student number." << endl;
    }
}
};

class menu {
    public:
    void displayMenu() {
        cout << "\nPRESS FROM THE FOLLOWING OPTION";
        cout << "\n1.ADD STUDENT";
        cout << "\n2.DISPLAY STUDENT";
        cout << "\n3.DELETE STUDENT";
        cout << "\n4.UPDATE STUDENT";
        cout << "\n5.EXIT";
    }
};
int main() {
    menu Menu;
    int option;
    vector<Student> students;
    StudentData data;
    while (true){
        Menu.displayMenu();
        cout << "\nENTER YOUR OPTION: ";
        cin >> option;
        cin.ignore();

        if (option < 1 || option > 5){
            cout << "INVALID OPTION" << endl;
            continue;
        } else {
            if (option == 1) {
                data.addStudent(students);
            } else if (option == 2) {
                data.displayStudent(students);
            } else if (option == 3) {
                data.deleteStudent(students);
            } else if (option == 4) {
                data.updateStudent(students);
            } else if (option == 5) {
                cout << "Thank you!" << endl;
                break;
            }
        }
    }
    return 0;
}