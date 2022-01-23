#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   
void insert();  
void delete();  
void display();  
void main ()  
{  
    int choice;   
        printf("\nMain Menu\n");  
       
        printf("\n1.insert \n2.Delete \n3.Display \n4.Exit\n");  
        while(choice != 4)   
    {     
        printf("\nEnter your choice ?");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1: insert();  
                    break;  
            case 2: delete();  
                    break;  
            case 3: display();  
                    break;  
            case 4: exit(0);  
        }  
    }  
}  
void insert()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value? ");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void delete ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nthe queue is");  
        while(ptr != NULL)   
        {  
            printf("%d,",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}
