//
// Created by ArShAm on 8/1/2020.
//

#ifndef TA_19_DOUBLEMAJORSTUDENT_H
#define TA_19_DOUBLEMAJORSTUDENT_H


#include "Student.h"

class DoubleMajorStudent : public Student {

private:
    std::string major2;
public:
    DoubleMajorStudent(const std::string &studentId, std::string first, std::string last, double workHours,
                       std::vector<std::string> passedCourses, std::map<std::string, double> currentSemesterCourses,
                       std::string major2);

    ~DoubleMajorStudent() = default;

    DoubleMajorStudent() = default;

    virtual double calculateSalary() const;

    const std::string &getMajor2() const;

    void setMajor2(const std::string &major2);
};


#endif //TA_19_DOUBLEMAJORSTUDENT_H
