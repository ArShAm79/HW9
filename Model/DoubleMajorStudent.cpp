//
// Created by ArShAm on 8/1/2020.
//

#include "DoubleMajorStudent.h"

#include <utility>

long double DoubleMajorStudent::calculateSalary() const {
    return 6500 * getWorkHours();
}

DoubleMajorStudent::DoubleMajorStudent(const std::string &studentId, std::string first, std::string last,
                                       double workHours, std::vector<std::string> passedCourses,
                                       std::map<std::string, double> currentSemesterCourses, std::string major2)
        : Student(studentId, std::move(first), std::move(last), workHours, std::move(passedCourses),
                  std::move(currentSemesterCourses)), major2{std::move(major2)} {

}

const std::string &DoubleMajorStudent::getMajor2() const {
    return major2;
}

void DoubleMajorStudent::setMajor2(const std::string &major2) {
    DoubleMajorStudent::major2 = major2;
}
