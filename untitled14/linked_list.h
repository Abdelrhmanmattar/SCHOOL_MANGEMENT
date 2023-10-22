//
// Created by abdelrhman mattar on 8/29/2023.
//

#ifndef UNTITLED10_LINKED_LIST_H
#define UNTITLED10_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//implement linked list for all data types
typedef struct node {
    void *data;
    struct node *next;
} node;

typedef struct linked_list {
    node *head;
    int size;
    size_t data_size;
} linked_list;

linked_list *create_linked_list(size_t data_size , void *data)
{
    linked_list *list = (linked_list *)malloc(sizeof(linked_list));
    if(list == NULL)return NULL;

    node *head = (node *)malloc(sizeof(node));
    if(head == NULL)return NULL;

    head->data=malloc(data_size);
    if(head->data == NULL)return NULL;
    for (int i = 0; i < data_size; i++) {
        *(unsigned char *) (head->data + i) = *(unsigned char *) (data + i);
    }
    head->next = NULL;


    list->head = head;
    list->size=1;
    list->data_size = data_size;
    return list;
}

void push_back( linked_list ** list , void * data)
{
    node * temp = (*list)->head;
    while (temp->next!= NULL)
        temp = temp->next;

    node * temp2 = (node * ) malloc(sizeof (node));
    if(temp2 == NULL)return;
    temp2->data = malloc((*list)->data_size);
    if(temp2->data == NULL)return;
    for (int i = 0; i < (*list)->data_size; i++) {
        *(unsigned char *) (temp2->data + i) = *(unsigned char *) (data + i);
    }
    temp2->next=NULL;
    temp->next = temp2;
    (*list)->size+=1;
}
void push_head(linked_list ** list , void * data)
{
    node * temp = (node * ) malloc(sizeof (node));
    if(temp == NULL)return;
    temp->data = malloc((*list)->data_size);
    if(temp->data == NULL)return;
    for (int i = 0; i < (*list)->data_size; i++) {
        *(unsigned char *) (temp->data + i) = *(unsigned char *) (data + i);
    }
    temp->next = (*list)->head;
    (*list)->head = temp;
    (*list)->size+=1;
}

void pop_head(linked_list ** list)
{
    node * temp = (*list)->head->next;
    free((*list)->head);
    (*list)->head = temp;
    (*list)->size--;
}
void remove_by_ind(linked_list ** list , int index)
{
    node * temp = (*list)->head;
    for(int i=0 ;i<index-1 ; i++)
    {
        temp = temp->next;
    }
    node * temp2 = temp->next->next;
    free(temp->next);
    temp->next=temp2;
    (*list)->size--;
}
void insert_by_ind(linked_list ** list ,int  index, void * data)
{
    node * temp = (*list)->head;
    for(int i=0 ;i<index-1 ; i++)
    {
        temp = temp->next;
    }
    node * temp2 = (node * ) malloc(sizeof (node));
    if(temp2 == NULL)return;
    temp2->data = malloc((*list)->data_size);
    if(temp2->data == NULL)return;
    for (int i = 0; i < (*list)->data_size; i++) {
        *(unsigned char *) (temp2->data + i) = *(unsigned char *) (data + i);
    }
    temp2->next=temp->next;
    temp->next=temp2;
    (*list)->size++;
}
void * get_element(linked_list * list , int index)
{
    node * temp = list->head;//1 2 3
    for(int i=0 ;i<index ; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}
int size_list(linked_list * list)
{
    return list->size;
}

void insert_by_comp(linked_list ** list , void * data , bool (*comp)(void * , void *))
{
    if((*list)->head == NULL)
    {
        push_head(list , data);
    }
    /*else if((*list)->size==1)
    {
        if(comp((*list)->head->data , data))
        {
            push_back(list , data);
        }
        else
        {
            push_head(list , data);
        }
    }*/
    else {
        node *temp = (*list)->head;
        node *previous=NULL;
        int i=0;
        while (temp!=NULL && comp(temp->data, data)) {
            i++;
            previous=temp;
            temp = temp->next;
        }//3 1 -1
        node * temp2=(node *)malloc(sizeof(node));
        if(temp2 == NULL)return;
        temp2->data = malloc((*list)->data_size);
        if(temp2->data == NULL)return;
        for (int j = 0; j < (*list)->data_size; j++) {
            *(unsigned char *) (temp2->data + j) = *(unsigned char *) (data + j);
        }
        insert_by_ind(list , i , data);
        /*
        if(previous->next == NULL)
        {
            previous->next=temp2;
            temp2->next=NULL;
            (*list)->size++;
        }
        else
        {
            insert_by_ind(list , i , data);
        }*/
    }
}

void chage_data_size(linked_list ** list , size_t data_size)
{
    (*list)->data_size = data_size;
}
node * get_head(linked_list * list)
{
    return list->head;
}

node * get_next(node * node)
{
    return node->next;
}



#endif //UNTITLED10_LINKED_LIST_H
