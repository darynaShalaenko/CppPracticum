#ifndef GRADUATE_H_INCLUDED
#define GRADUATE_H_INCLUDED

#include "human.h"
#include "student.h"
#include "teacher.h"
#include <string>
#include <vector>

class graduate: public human, public teacher, public student{
    // Конструктор класса graduate
    public:
        graduate(
            std::string last_name,
            std::string name,
            std::string second_name,
            unsigned int work_time,
            std::vector<int> scores

        ) : human(
            last_name,
            name,
            second_name
        ),  teacher (
            work_time
        ),  student(
            scores
        )
#endif // GRADUATE_H_INCLUDED
