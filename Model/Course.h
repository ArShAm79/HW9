#ifndef TA_19_COURSE_H
#define TA_19_COURSE_H

#include <string>
#include <vector>

class Course {
    friend class Controller;

    friend std::ostream &operator<<(std::ostream &output, const Course &course);

    friend std::istream &operator>>(std::istream &input, Course &course);

private:
    std::string courseName;
    std::string profLastName;
    std::string semester;
    std::vector<std::string> preCourses;

public:
    Course() = default;

    Course(std::string courseName, std::string profLastName, std::string semester, std::vector<std::string> preCourses);

    const std::string &getCourseName() const;

    const std::string &getProfLastName() const;
};


#endif //TA_19_COURSE_H
