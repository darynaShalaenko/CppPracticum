#include <stdio.h>
#include <string.h>

typedef struct Seminar
{
    char subject[30];
    char teacher[30];
    int group;
    int day;
    char hours[11];
    char auditorium[3];
} Seminar;

typedef struct Seminar *s;

void input_allabout_seminar(Seminar *s){
    char subject[30], teacher[30], auditorium[3], hours[11];
    int group, day;
    printf("Subject: ");
    scanf("%s", subject);
    printf("Teacher: ");
    scanf("%s", teacher);
    printf("Group: ");
    scanf("%d", &group);
    printf("Day: ");
    scanf("%d", &day);
    printf("Hours: ");
    scanf("%s", hours);
    printf("Auditorium: ");
    scanf("%s", auditorium);
    strcpy(s->subject, subject);
    strcpy(s->teacher, teacher);
    strcpy(s->auditorium, auditorium);
    strcpy(s->hours, hours);
    s->group = group;
    s->day = day;
}
void output_allabout_seminar(Seminar *s){
    printf("\nSubject: %s\n", s->subject);
    printf("Teacher: %s\n", s->teacher);
    printf("Group: %d\n", s->group);
    printf("Day: %d\n", s->day);
    printf("Hours: %s\n", s->hours);
    printf("Auditorium: %s\n", s->auditorium);
}
int main()
{
    struct Seminar new_seminar;
    struct Seminar * p_sem = &new_seminar;
    printf("Input: \n");
    input_allabout_seminar(p_sem);
    printf("Outnput: \n");
    output_allabout_seminar(p_sem);
}
