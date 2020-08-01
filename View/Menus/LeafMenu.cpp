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
        string ID;
        cout << "Please enter ID\n";
        cin >> ID;
        cout << controller.findProfessor(ID).calculateSalary() << endl;
        cout << "Done!\n";

    } else if (name == "Add Professor") {
        string id;
        string first;
        string last;
        string title;
        double wh;
        cout << "Enter professor number: \n";
        cin >> id;
        cout << "Enter First Name: \n";
        cin >> first;
        cout << "Enter Last Name: \n";
        cin >> last;
        cout << "Enter Title: \n";
        cin >> title;
        controller.addProfessor(id, first, last, title);


    } else if (name == "Show Professors") {
        cout << "Number\tFirstName\tLastName\tWorkHours\tTitle\n";
        for (const auto &professor : controller.professors) {
            cout << professor << endl;
        }

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
        cout << "Number\tFirstName\tLastName\tWorkHours\tPassedCourses\n";
        for (const auto &student : controller.students) {
            cout << student << endl;
        }

    } else if (name == "Add Course") {
        string courseName;
        string profLastName;
        string semester;
        int preCoursesSize;
        vector<string> preCourses;
        string crs;
        cout << "Enter course name: \n";
        cin >> courseName;
        cout << "Enter Professor Last name: \n";
        cin >> profLastName;
        cout << "Enter semester: \n";
        cin >> semester;
        cout << "Enter number of preCourse:\n";
        cin >> preCoursesSize;
        for (size_t i{0}; i < preCoursesSize; ++i) {
            cin >> crs;
            preCourses.push_back(crs);
        }
        controller.addCourse(courseName, profLastName, semester, preCourses);

    } else if (name == "Show All Courses") {
        for (const auto &course : controller.courses) {
            cout << course << endl;
        }

    } else {
        throw invalid_argument("This Menu hase not been defined!!");
    }
}
