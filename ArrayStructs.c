#include <stdio.h>
#include <string.h>

struct Student
{
    char name[12]; 
    float gpa;
};



int main(){

    struct Student student1 = {"Arthur", 4.0};
    struct Student student2 = {"Roberto", 2.5};
    struct Student student3 = {"Debora", 3.8};
    struct Student student4 = {"Alberto", 2.3};


    struct Student students[] = {student1, student2, student3, student4};

    for (int i = 0; i < sizeof(students)/sizeof(students[0]); i++)
    {
        printf("%-12s ", students[i].name);
        printf("%.2f\n", students[i].gpa);
    }
    
    
    
    return 0;
}