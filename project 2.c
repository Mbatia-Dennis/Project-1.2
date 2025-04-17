#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int roll_number;
    char name[50];
    char grade;
    int marks;
} Student;

typedef struct {
    int class_id;
    char class_name[50];
    Student students[50]; 
    int student_count;
} Class;


void add_student(Class *class, Student student) {
    if (class->student_count < 50) {
        class->students[class->student_count] = student;
        class->student_count++;
        printf("Student added successfully.\n");
    } else {
        printf("Class is full. Cannot add more students.\n");
    }
}


void display_students(Class *class) {
    printf("Students in Class: %s (%d)\n", class->class_name, class->class_id);
    if (class->student_count > 0) {
        for (int i = 0; i < class->student_count; i++) {
            printf("Roll Number: %d, Name: %s, Grade: %c, Marks: %d\n",
                   class->students[i].roll_number, class->students[i].name,
                   class->students[i].grade, class->students[i].marks);
        }
    } else {
        printf("No students in this class.\n");
    }
}

int search_student(Class *class, int roll_number) {
    for (int i = 0; i < class->student_count; i++) {
        if (class->students[i].roll_number == roll_number) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    Class class1;
    class1.class_id = 1;
    strcpy(class1.class_name, "Class 1");
    class1.student_count = 0;

    Student student1;
    student1.roll_number = 101;
    strcpy(student1.name, "Alice Johnson");
    student1.grade = 'A';
    student1.marks = 85;

    Student student2;
    student2.roll_number = 102;
    strcpy(student2.name, "Bob Smith");
    student2.grade = 'B';
    student2.marks = 78;

    add_student(&class1, student1);
    add_student(&class1, student2);

    display_students(&class1);

    int roll_to_search = 101;
    int index = search_student(&class1, roll_to_search);

    if (index != -1) {
        printf("Student with roll number %d found at index %d\n", roll_to_search, index);
    } else {
        printf("Student with roll number %d not found.\n", roll_to_search);
    }

    return 0;
}