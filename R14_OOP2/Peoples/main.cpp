#include <iostream>
#include <vector>

#include "human.h"
#include "student.h"
#include "teacher.h"
//#include "graduate.h"

int main(int argc, char* argv[])
{

    // Оценки студента
    std::vector<int> scores;

    // Добавление оценок студента в вектор
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(2);
    scores.push_back(2);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    // Создание объекта класса student
    student *stud = new student("Petrov", "Ivan", "Alekseevich", scores);

    // Вывод полного имени студента (используется унаследованный метод класса human)
    std::cout << stud->get_full_name() << std::endl;
    // Вывод среднего балла студента
    std::cout << "Average csore: " << stud->get_average_score() << std::endl;
    // Количество учебных часов преподавателя
    unsigned int teacher_work_time = 40;

    teacher *tch = new teacher("Vasilkov", "Petr", "Sergeevich", teacher_work_time);

    std::cout << tch->get_full_name() << std::endl;
    std::cout << "Work time: " << tch->get_work_time() << std::endl;
}
