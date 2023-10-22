#include <stdio.h>
#include "linked_list.h"
#include <string.h>
typedef struct student
{
    char name[50];
    char id[11];
    char birthday[15];
    char phone[15];
    char address[50];
    int total_score;
    int cs_score;
}student;

void MAIN_MENU(linked_list ** list , linked_list ** sort_byrank , linked_list ** sort_bycs);
void add_student(linked_list ** list);
void print_all_student(linked_list ** list);

void  sort_by_cs_score(linked_list ** list , linked_list ** sorted_list);
void  sort_by_rank(linked_list ** list , linked_list ** sorted_list);

void delete_student(linked_list ** list);
void edit_student(linked_list ** list);

bool comp_fun(void * a, void *b)
{
    //ascending names
    return (strcmp((*(student*)a).name,(*(student*)b).name)) >= 0;
}
bool comp_cs_rank(void * a, void *b)
{
    return ( (*(student*)a).cs_score >= (*(student*)b).cs_score);
}
bool comp_rank(void * a, void *b)
{
    return ( (*(student*)a).total_score >= (*(student*)b).total_score);
}

int main() {
    student begin = {" "," "," "," "," ",INT_MAX,INT_MAX};
    linked_list * list = create_linked_list(sizeof(student),&begin);
    linked_list * sort_byrank;
    linked_list * sort_bycs;
    MAIN_MENU(&list , &sort_byrank , &sort_bycs);
    return 0;
}

void MAIN_MENU(linked_list ** list , linked_list ** sort_byrank , linked_list ** sort_bycs)
{
    fflush(stdin);
    fflush(stdout);
    printf("---------------------\n");
    printf("1-Add student\n");
    printf("2-Delete student\n");
    printf("3-Edit student\n");
    printf("4-Print all students\n");
    printf("5-Sort by Rank student\n");
    printf("6-Sort by CS Score student\n");
    printf("7-Exit\n");
    printf("Enter your choice: ");
    char x,z;
    scanf("%c" , &x);
    switch (x)
    {
        case '1':
            add_student(list);
            MAIN_MENU(list,sort_byrank,sort_bycs);
            break;
        case '2':
            delete_student(list);
            printf("Student deleted successfully\n");
            MAIN_MENU(list,sort_byrank,sort_bycs);
            break;
        case '3':
            edit_student(list);
            printf("Student edited successfully\n");
            MAIN_MENU(list,sort_byrank,sort_bycs);
            break;
        case '4':
            print_all_student(list);
            scanf("%c" , &z);
            MAIN_MENU(list,sort_byrank,sort_bycs);
            break;
        case '5':
            sort_by_rank(list , sort_byrank);
            print_all_student(sort_byrank);
            scanf("%c" , &z);
            MAIN_MENU(list,sort_byrank,sort_bycs);
            break;
        case '6':
            sort_by_cs_score(list , sort_bycs);
            print_all_student(sort_bycs);
            scanf("%c" , &z);
            MAIN_MENU(list,sort_byrank,sort_bycs);
            break;
        case '7': //exit
            return;
        default:
            printf("Invalid choice\n");
            MAIN_MENU(list,sort_byrank,sort_bycs);
    }
}

void add_student(linked_list ** list)
{
    student add_new;
    fflush(stdin);
    fflush(stdout);
    printf("Enter student name: ");
    scanf("%s" , add_new.name);
    fflush(stdin);
    fflush(stdout);
    printf("Enter student id: ");
    scanf("%s" , add_new.id);
    fflush(stdin);
    fflush(stdout);
    printf("Enter student birthday: ");
    scanf("%s" , add_new.birthday);
    fflush(stdin);
    fflush(stdout);
    printf("Enter student phone: ");
    scanf("%s" , add_new.phone);
    fflush(stdin);
    fflush(stdout);
    printf("Enter student address: ");
    scanf("%s" , add_new.address);
    fflush(stdin);
    fflush(stdout);
    printf("Enter student total score: ");
    scanf("%d" , &add_new.total_score);
    fflush(stdin);
    fflush(stdout);
    printf("Enter student cs score: ");
    scanf("%d" , &add_new.cs_score);
    insert_by_comp(list,&add_new,comp_fun);
}

void  sort_by_cs_score(linked_list ** list , linked_list ** sorted_list)
{
    node * begin = (*list)->head;
    *sorted_list = create_linked_list(sizeof(student),begin->data);
    //begin=begin->next;
    while (begin != NULL)
    {
        insert_by_comp(sorted_list,begin->data,comp_cs_rank);
        begin = begin->next;
    }
}
void  sort_by_rank(linked_list ** list , linked_list ** sorted_list)
{
    node * begin = (*list)->head;
    *sorted_list = create_linked_list(sizeof(student),begin->data);
    //begin=begin->next;
    while (begin != NULL)
    {
        insert_by_comp(sorted_list,begin->data,comp_rank);
        begin = begin->next;
    }
}

void delete_student(linked_list ** list)
{
    int i=0;
    fflush(stdin);
    fflush(stdout);
    printf("Enter student id: ");
    char id[11];
    scanf("%s" , id);

    node * begin = (*list)->head;

    while (begin != NULL)
    {
        student * temp = (student *)begin->data;
        if (strcmp(temp->id,id) == 0)
        {
            remove_by_ind(list,i);
            return;
        }
        begin = begin->next;
        i++;
    }
    printf("Student not found\n");
}

void edit_student(linked_list ** list)
{
    int i=0;
    fflush(stdin);
    fflush(stdout);
    printf("Enter student id: ");
    char id[11];
    scanf("%s" , id);

    node * begin = (*list)->head;

    while (begin != NULL)
    {
        student * temp = (student *)begin->data;
        if (strcmp(temp->id,id) == 0)
        {
            fflush(stdin);
            fflush(stdout);
            printf("Enter student birthday: ");
            scanf("%s" , temp->birthday);

            fflush(stdin);
            fflush(stdout);
            printf("Enter student phone: ");
            scanf("%s" , temp->phone);

            fflush(stdin);
            fflush(stdout);
            printf("Enter student address: ");
            scanf("%s" , temp->address);

            fflush(stdin);
            fflush(stdout);
            printf("Enter student total score: ");
            scanf("%d" , &temp->total_score);

            fflush(stdin);
            fflush(stdout);
            printf("Enter student cs score: ");
            scanf("%d" , &temp->cs_score);

            fflush(stdin);
            fflush(stdout);
            return;
        }
        begin = begin->next;
        i++;
    }
    printf("Student not found\n");
}

void print_all_student(linked_list ** list)
{
    node * begin = (*list)->head;
    while (begin != NULL)
    {
        fflush(stdin);
        fflush(stdout);
        student * temp = (student *)begin->data;
        printf("Name: %s\n" , temp->name);
        printf("ID: %s\n" , temp->id);
        printf("Birthday: %s\n" , temp->birthday);
        printf("Phone: %s\n" , temp->phone);
        printf("Address: %s\n" , temp->address);
        printf("Total Score: %d\n" , temp->total_score);
        printf("CS Score: %d\n" , temp->cs_score);
        printf("--------------------------------------------------\n");
        begin = begin->next;
    }
}