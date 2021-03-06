#include <stdlib.h>
#include <stdio.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct node
{
    int data;
    struct node *next;
};
struct node* start=NULL;

void create()
{
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp=NULL)
    {
        printf("Out of memory");
    }
    printf("Enter the data:\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start=NULL){
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void display()
{
    struct node *ptr;
    if(start=NULL)
    {
        printf("List is empty.\n");
    }
    else{
        ptr=start;
        printf("The elements of list are:\n");
        while(ptr->next!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
}

void insert_begin()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start=NULL)
    {
        start=temp;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}

void insert_end()
{
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Out of memory:\n");
        return;
    }
    printf("Enter the value of Node:\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void insert_pos()
{
    struct node *temp,*ptr;
    int i,pos;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Out of memory:\n");
        return;
    }
    printf("Enter The position at which the new node is to be inserted:\n");
    scanf("%d",&pos);
    printf("Enter the data of the node:\n");
    scanf("%d",&temp->data);
    if(pos==0)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
        for(i=0,ptr=start;i<pos-1;i++){
            ptr=ptr->next;
            if(ptr=NULL)
            {
                printf("Position not found");
            }
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}

void delete_begin()
{
    struct node *ptr;
    if (ptr == NULL)
    {
        printf("\nList is Empty:\n");
        return;
    }
    start=ptr;
    start=start->next;
     printf("\nThe deleted element is :%d\t", ptr->data);
        free(ptr);
}

void delete_end()
{
    struct node *ptr,*temp;
    if (start == NULL)
    {
        printf("\nList is Empty:");
        exit(0);
    }
    else if(start->next!=NULL){
        ptr=start;
        start=NULL;
        printf("\nThe deleted element is :%d\t", ptr->data);
        free(ptr);

    }
    else{
        ptr=start;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
         temp->next = NULL;
        printf("\nThe deleted element is:%d\t", ptr->data);
        free(ptr);

    }
}
void delete_pos()
{
    int i, pos;
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("\nThe List is Empty:\n");
        exit(0);
    }
    else
    {
        printf("\nEnter the position of the node to be deleted:\t");
        scanf("%d", &pos);
        if (pos == 0)
        {
            ptr = start;
            start = start->next;
            printf("\nThe deleted element is:%d\t", ptr->data);
            free(ptr);
        }
        else
        {
            ptr = start;
            for (i = 0; i < pos; i++)
            {
                temp = ptr;
                ptr = ptr->next;
                if (ptr == NULL)
                {
                    printf("\nPosition not Found:\n");
                    return;
                }
            }
            temp->next = ptr->next;
            printf("\nThe deleted element is:%d\t", ptr->data);
            free(ptr);
        }
    }
}
int main()
{
    int choice;
    while (1)
    {

        printf("\n                MENU                             \n");
        printf("\n 1.Create     \n");
        printf("\n 2.Display    \n");
        printf("\n 3.Insert at the beginning    \n");
        printf("\n 4.Insert at the end  n");
        printf("\n 5.Insert at specified position       \n");
        printf("\n 6.Delete from beginning      \n");
        printf("\n 7.Delete from the end        \n");
        printf("\n 8.Delete from specified position     n");
        printf("\n 9.Exit       \n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_begin();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            insert_pos();
            break;
        case 6:
            delete_begin();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            delete_pos();
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("\n Wrong Choice:\n");
            break;
        }
    }
    return 0;
}
