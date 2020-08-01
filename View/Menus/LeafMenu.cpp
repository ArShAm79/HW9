#include "LeafMenu.h"

using namespace std;

LeafMenu::LeafMenu(std::string name, Menu *parent)
        : Menu{move(name), parent} {}

void LeafMenu::showSubMenus() const {}

void LeafMenu::run() {
    setCurrentMenu(parent);

    if (name == "Show This Semester Courses") {
        for (size_t t{0}; t < controller.currentSemesterCourses.size(); t++) {
            cout << t + 1 << "_" << controller.currentSemesterCourses[t] << endl;
        }
        cout << "Done!\n";

    } else if (name == "Take Course") {
        string ID;
        cout << "Please enter ID\n";
        cin >> ID;
        bool check = false;
        for (auto &stu : controller.students) {
            if (stu.studentId == ID) {
                check = true;
                cout << "Choose one course\n";
                for (size_t t{0}; t < controller.currentSemesterCourses.size(); t++) {
                    cout << t + 1 << "_" << controller.currentSemesterCourses[t] << endl;
                }
                int number;
                cin >> number;
                stu.currentSemesterCourses.insert({controller.currentSemesterCourses[number - 1].getCourseName(), 0});
                cout << "Done!";

            }
        }
        if (!check)
            cout << "This ID is invalid\n";

    } else if (name == "Drop Course") {
        string ID;
        cout << "Please enter ID\n";
        cin >> ID;
        bool check = false;
        for (auto &stu : controller.students) {
            if (stu.studentId == ID) {
                check = true;
                cout << "Choose one course\n";
                for (size_t t{0}; t < controller.currentSemesterCourses.size(); t++) {
                    cout << t + 1 << "_" << controller.currentSemesterCourses[t] << endl;
                }
                int number;
                cin >> number;
                stu.currentSemesterCourses.erase(controller.currentSemesterCourses[number - 1].getCourseName());
                cout << "Done!";
            }
        }
        if (!check)
            cout << "This ID is invalid\n";

    } else if (name == "Show Student Courses In Current Semester") {

    } else if (name == "Calculate Student Salary") {

    } else if (name == "Show Professor Courses In Current Semester") {

    } else if (name == "Submit Grade") {

    } else if (name == "Calculate Professor Salary") {

    } else if (name == "Add Professor") {

    } else if (name == "Show Professors") {

    } else if (name == "Add Student") {
        string ID;
        cout << "Enter student number: ";
        cin >> ID;
        string first;
        cout << "Enter First Name: ";
        cin >> first;
        string last;
        cout << "Enter Last Name: ";
        cin >> last;
        controller.addStudent(ID, first, last);
    } else if (name == "Show Students") {

    } else if (name == "Add Course") {

    } else if (name == "Show All Courses") {

    } else {
        throw invalid_argument("This Menu hase not been defined!!");
    }
}
