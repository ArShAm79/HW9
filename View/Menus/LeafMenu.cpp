#include <fstream>
#include "LeafMenu.h"
#include "../../Model/DoubleMajorStudent.h"
#include <iomanip>

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
        cout << "Enter student number: \n";
        cin >> ID;
        string first;
        cout << "Enter First Name: \n";
        cin >> first;
        string last;
        cout << "Enter Last Name:\n ";
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

    } else if (name == "ReadMembersFromFile") {
        ifstream input("members.txt");
        while (input.good()) {
            char check;
            input >> check;
            if (check == 'S') {
                string ID, first, last;
                double wh;
                input >> ID >> first >> last >> wh;
                auto student = new Student{ID, first, last, wh, vector<string>(), map<string, double>()};
                controller.mathClass.push_back(student);
            } else if (check == 'P') {
                string ID, first, last, title;
                double wh;
                input >> ID >> first >> last >> title >> wh;
                auto professor = new Professor{ID, first, last, wh, title};
                controller.mathClass.push_back(professor);
            } else if (check == 'D') {
                string ID, first, last;
                double wh;
                input >> ID >> first >> last >> wh;
                auto doubleMajorStudent = new DoubleMajorStudent{ID, first, last, wh, vector<string>(),
                                                                 map<string, double>(), "Math"};
                controller.mathClass.push_back(doubleMajorStudent);
            } else {
                throw invalid_argument("Is not Available");
            }

        }
    } else if (name == "CalculateTotalSalary") {
         double ans = 0;
        for (auto &mathClass : controller.mathClass) {
            ans += mathClass->calculateSalary();
        }
        cout << setw(10)<<fixed << ans <<fixed<< endl;
    } else {
        throw invalid_argument("This Menu has not been defined!!");
    }
}
