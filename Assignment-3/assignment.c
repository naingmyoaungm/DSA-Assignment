//
// Created by ASUS on 12/27/2023.
//

#include "stdio.h"
#include "stdlib.h"

//function declare
void copy_two_charArray(char first[30],char second[30]);
void registration();
void menu();
void login();
void login_checking(char l_email[30],char l_pass[20]);
int compare_two_char_array(char first[30],char second[30]);
int size_of_charArray(char arr[30]);
void my_privilege(int user_id);

//Global Var
int g_userCount=0;
int g_login_check=-1;

// structure declare
struct Db{
    int user_id;
    char user_name[30];
    char user_email[30];
    char user_pass[20];
    int phone_number;
    char address[30];
    int postal_code;

};

// database
struct Db data[10];

// main function
int main(){

    menu();

    return 0;
}

// menu function
void menu(){

    while (1) { // 1 true 0 false
        int option = 0;
        printf("\nWelcome to our System!\n");
        printf("Press:1 To Login!\nPress:2 To Register!\nPress:3 To Exist!:\nEnter:");
        scanf("%d", &option);


        if (option == 1) {

            login();

        } else if (option == 2) {

            registration();
        } else {
            exit(1);
        }
    }

}

// login function
void login(){

    char l_email[30];
    char l_password[20];
    printf("This is Login!\n");
    printf("Enter your email to Login:");
    scanf(" %[^\n]",&l_email);
    printf("Enter your password to Login:");
    scanf(" %[^\n]",&l_password);

    login_checking(l_email,l_password);
    if(g_login_check != -1){
        printf("Login Success!\nYour Id= %d",g_login_check);
        my_privilege(g_login_check);
    } else{
        printf("Login Failed!\n");
        menu();
    }

}

void my_privilege(int user_id){

    while (1){
        int option=0;
        printf("\nWelcome Sir: %s",data[user_id].user_name);
        printf("\nYour PhoneNumber: %d",data[user_id].phone_number);
        printf("\nPress 1 to Logout:");
        scanf("%d",&option);

        if(option == 1){
            menu();
        }
    }


}


void login_checking(char l_email[30],char l_pass[20]){

    int i=0;
    g_login_check=-1;
    for(i=0; i<g_userCount; i++){

        int email_check = compare_two_char_array(data[i].user_email,l_email);

        if(email_check == 1){
            int pass_check = compare_two_char_array(data[i].user_pass,l_pass);
            if(pass_check==1){
                g_login_check=data[i].user_id;
                break;
            }
        }

    }

}

void registration(){

    char r_username[30];
    char r_useremail[30];
    char r_userpassword[20];
    int r_phoneNumber=0;
    char r_address[50];
    int r_postal_code=0;
    printf("This is Registration Option:\n");
    printf("Enter your user name to Register:");
    scanf(" %[^\n]",&r_username);
    printf("Enter your user email to Register:");
    scanf(" %[^\n]",&r_useremail);
    printf("Enter your user password to Register:");
    scanf(" %[^\n]",&r_userpassword);
    printf("Enter your user PhoneNumber to Register:");
    scanf("%d",&r_phoneNumber);
    printf("Enter your address to Register:");
    scanf(" %[^\n]",&r_address);
    printf("Enter your Postal code to Register:");
    scanf("%d",&r_postal_code);

    // collecting
    copy_two_charArray(data[g_userCount].user_name,r_username);
    printf("\nChecking for username: %s",data[g_userCount].user_name);

    copy_two_charArray(data[g_userCount].user_email,r_useremail);
    printf("\nChecking for useremail: %s",data[g_userCount].user_email);

    copy_two_charArray(data[g_userCount].user_pass,r_userpassword);
    printf("\nChecking for Password: %s",data[g_userCount].user_pass);

    data[g_userCount].phone_number = r_phoneNumber;
    printf("\nChecking for PhoneNumber: %d",data[g_userCount].phone_number);

    copy_two_charArray(data[g_userCount].address,r_address);
    printf("\nChecking for Address: %s",data[g_userCount].address);

    data[g_userCount].postal_code = r_postal_code;
    printf("\nChecking for Postal Code: %d",data[g_userCount].postal_code);


    data[g_userCount].user_id = g_userCount;
    g_userCount++;

}

void copy_two_charArray(char first[30],char second[30]){

    int i=0;
    for(i=0; i<30; i++){

        if(second[i]=='\0'){

            break;
        } else{
            first[i] = second[i];
        }

    }

}

int compare_two_char_array(char first[30],char second[30]){

    int size1 = size_of_charArray(first);
    int size2 = size_of_charArray(second);
    int sameCount=0;

    if(size1 == size2){

        for(int i=0; i<size1; i++){

            if(first[i] == second[i]){
                sameCount++;
            }
        }

    }

    if(size1 == sameCount){
        return 1;
    } else{
        return 0;
    }

}

int size_of_charArray(char arr[30]){

    int size=0;
    for(int i=0; i<30; i++){

        if(arr[i] == '\0'){
            break;
        }
        size++;
    }

    return size;
}