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
        controller.findStudent(ID);
        cout << "Choose an course\n";
        for (size_t t{0}; t < controller.currentSemesterCourses.size(); t++) {
            cout << t + 1 << "_" << controller.currentSemesterCourses[t] << endl;
        }
        int number;
        cin >> number;
        controller.findStudent(ID).currentSemesterCourses.insert(
                {controller.currentSemesterCourses[number - 1].getCourseName(), 0});
        cout << "Done!\n";


    } else if (name == "Drop Course") {
        string ID;
        cout << "Please enter ID\n";
        cin >> ID;
        controller.findStudent(ID);
        cout << "Choose an course\n";
        for (size_t t{0}; t < controller.currentSemesterCourses.size(); t++) {
            cout << t + 1 << "_" << controller.currentSemesterCourses[t] << endl;
        }
        int number;
        cin >> number;
        controller.findStudent(ID).currentSemesterCourses.erase(
                controller.currentSemesterCourses[number - 1].getCourseName());
        cout << "Done!\n";

    } else if (name == "Show Student Courses In Current Semester") {

        string ID;
        cout << "Please enter ID\n";
        cin >> ID;
        for (const auto &courses:controller.findStudent(ID).currentSemesterCourses) {
            cout << courses.first << endl;
        }
        cout << "Done!\n";
    } else if (name == "Calculate Student Salary") {
        string ID;
        cout << "Please enter ID\n";
        cin >> ID;
        cout << controller.findStudent(ID).calculateSalary() << endl;
        cout << "Done!\n";

    } else if (name == "Show Professor Courses In Current Semester") {
        string ID;
        cout << "Please enter ID\n";
        cin >> ID;
        string profName = controller.findProfessor(ID).getLastName();
        for (auto &currentSemesterCourse : controller.currentSemesterCourses) {
            if (currentSemesterCourse.getProfLastName() == profName)
                cout << currentSemesterCourse.getCourseName() << endl;
        }
        cout << "Done!\n";
    } else if (name == "Submit Grade") {
        string ProID;
        cout << "Please enter Professor ID\n";
        cin >> ProID;
        string course;
        string profName = controller.findProfessor(ProID).getLastName();
        for (auto &currentSemesterCourse : controller.currentSemesterCourses) {
            if (currentSemesterCourse.getProfLastName() == profName)
                cout << currentSemesterCourse.getCourseName() << endl;
        }
        cout << "Please enter Course ID\n";
        cin >> course;
        string StuID;
        cout << "Please enter Student ID\n";
        cin >> StuID;
        double grade;
        cout << "Please enter Grade \n";
        cin >> grade;
        controller.findStudent(StuID).currentSemesterCourses[course] = grade;
        cout << "Done!\n";

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
        controller.addStudent(ID, first, last
        );
    } else if (name == "Show Students") {

    } else if (name == "Add Course") {

    } else if (name == "Show All Courses") {

    } else {
        throw invalid_argument("This Menu hase not been defined!!");
    }
}
