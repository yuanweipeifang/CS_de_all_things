#include<stdio.h>
#include<stdlib.h>

#define N 100000
#define NAME yuanweipeifang

typedef enum{
    Female,
    Male,
    WallmartBag,
}GenderType;

typedef struct Student {
    char name[10];
    unsigned char age;
    unsigned char score;
    GenderType gender;
    struct Student *next;
}StudentType;

// typedef struct Node{

//     struct Node *next;
// };

void info_print(StudentType *stu){
    if(NULL == stu){
        return ;
    }
    do {
        printf("%s %d %d %d \n", stu->name, stu->age, stu->score, stu->gender);
        stu = stu->next;
    }while (stu);
}

int main(){
    StudentType s3 = {
        .name = "333",
        .age = 18,
        .gender = Female,
        .score = 98,
        .next = NULL
    };
    StudentType s2 = {
        .name = "222",
        .age = 12,
        .gender = Female,
        .score = 38,
        .next = &s3
    };
    StudentType s1 = {
        .name = "111",
        .age = 23,
        .gender = Female,
        .score = 92,
        .next = &s2
    };

    info_print(&s1);
    system("pause");
    return 0;
}

