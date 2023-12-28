//
// Created by ASUS on 12/17/2023.
//


#include <stdio.h>

int stu1_marks[6]={75, 85, 92, 60, 78, 45};
int stu2_marks[6]={88, 79, 65, 72, 95, 88};
int stu3_marks[6]={60, 55, 40, 30, 45, 50};

void printMarks();
void result();
void numberOf_destinationSubjects();
void highestMark_student();

int main() {


    printMarks();
    result();
    numberOf_destinationSubjects();
    highestMark_student();



    return 0;
}

void printMarks(){
    int students=3;

    for(int i=0; i<students; i++){
        if(i==0){
            printf("Stuent 1 marks : ");
            for(int xx=0; xx<6; xx++){
                printf("[%d]",stu1_marks[i]);
            }
        } else if(i==1){
            printf("Student 2 marks : ");
            for(int xx=0; xx<6; xx++){
                printf("[%d]",stu2_marks[i]);
            }
        } else{
            printf("Stuent 3 marks : ");
            for(int xx=0; xx<6; xx++){
                printf("[%d]",stu3_marks[i]);
            }
        }
        printf("\n");
    }
}

void result(){
    int students = 3;

    printf("\n{ Students Results } \n");
    for (int i = 0; i < students; i++) {
        int failed = 0;

        for (int j = 0; j < 6; j++) {
            if (i == 0 && stu1_marks[j] < 40) {
                failed = 1;
                break;
            } else if (i == 1 && stu2_marks[j] < 40) {
                failed = 1;
                break;
            } else if (i == 2 && stu3_marks[j] < 40) {
                failed = 1;
                break;
            }
        }

        if (failed) {
            printf("Student %d : Failed\n", i + 1);
        } else {
            printf("Student %d : Passed\n", i + 1);
        }
    }
    printf("\n");
}



void numberOf_destinationSubjects(){
    int students = 3;

    for (int i = 0; i < students; i++) {
        int distinctionCount = 0;
        if (i == 0) {
            for (int xx = 0; xx < 6; xx++) {
                if (stu1_marks[xx] >= 75) {
                    distinctionCount++;
                }
            }
        } else if (i == 1) {
            for (int xx = 0; xx < 6; xx++) {
                if (stu2_marks[xx] >= 75) {
                    distinctionCount++;
                }
            }
        } else {
            for (int xx = 0; xx < 6; xx++) {
                if (stu3_marks[xx] >= 75) {
                    distinctionCount++;
                }
            }
        }

        printf("Student %d Number of Distinction Subjects - %d\n", i + 1, distinctionCount);
    }
}

void highestMark_student(){

    int students = 3;
    int highestStudent = -1;
    int highestMark = -1;

    for (int i = 0; i < students; i++) {
        int totalMarks = 0;

        if (i == 0) {
            for (int xx = 0; xx < 6; xx++) {
                totalMarks += stu1_marks[xx];
            }
        } else if (i == 1) {
            for (int xx = 0; xx < 6; xx++) {
                totalMarks += stu2_marks[xx];
            }
        } else {
            for (int xx = 0; xx < 6; xx++) {
                totalMarks += stu3_marks[xx];
            }
        }

        if (totalMarks > highestMark) {
            highestMark = totalMarks;
            highestStudent = i + 1;
        }
    }

    printf("\nHighest mark student is : Student %d\n", highestStudent);
}
