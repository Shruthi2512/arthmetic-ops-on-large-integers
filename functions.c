#include<stdio.h>
#include<stdlib.h>
#include "header.h"

//function to get the number and store them minto a linked list
int getnumber(struct node **head)
{
    char ch;
    int digit;
    int count = 0;
    struct node *temp, *rear = NULL;

    ch = getchar();
    while (ch != '\n')
    {
        digit = ch-'0';
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = digit;
        temp->next = NULL;
        temp->prev=NULL;
        count++;
        if ((*head) == NULL)
        {
            *head = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            temp->prev=rear;
            rear = rear->next;
        }
        ch = getchar();
    }

    return count;
}


//Function to display the numbers stored in the linked list
void display (struct node *head)
{
    while (head != NULL)
    {
        printf("%d", head->num);
        head = head->next;
    }
    printf("\n");
}

//Function to free the linked list
void release (struct node **head)
{
    struct node *temp = *head;

    while ((*head) != NULL)
    {
        (*head) = (*head)->next;
        free(temp);
        temp = *head;
    }
}


//Function to insert a digit to the front of a linked list
void insert_front(struct node **p, int x)
{

    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->num=x;
    temp->prev=temp->next=NULL;

    if(*p==NULL)
    {
        *p=temp;
    }
    else
    {
         temp->next=*p;
         (*p)->prev=temp;
         *p=temp;
    }
}


//Funciton to add 2 numebrs stored in p and q, and store the result in r
struct node* add(struct node **phead,struct node **qhead,struct node *r)
{
    //struct node *r = NULL;
    //printf("inside add");
    struct node *ptemp; struct node *qtemp;
    ptemp=*phead;
    qtemp=*qhead;

    //Go to the last digits, i.e. units place
    while(ptemp->next!=NULL)
    {
        ptemp=ptemp->next;
    }

    while(qtemp->next!=NULL)
    {
        qtemp=qtemp->next;
    }


    //Initialize the carry over to zero. Add the digits from right to lift, updating the carry-overs on the way
    int car=0;
    int sum,sum1;
    while(ptemp!=NULL && qtemp!=NULL)
    {
        sum=ptemp->num + qtemp->num + car;
        sum1=sum%10;
        insert_front(&r,sum1);
        car=sum/10;
        ptemp=ptemp->prev;
        qtemp=qtemp->prev;
    }

    //Take care of boundary cases where either p or q is a shorter number than the other


    if(ptemp!=NULL && qtemp==NULL)
    {
        while(ptemp!=NULL)
        {

            sum=ptemp->num + car;
            sum1=sum%10;

            insert_front(&r,sum1);

            car=sum/10;

            ptemp=ptemp->prev;
        }
    }
    else if(ptemp==NULL && qtemp!=NULL)
    {
        while(qtemp!=NULL)
        {

            sum=qtemp->num + car;
            sum1=sum%10;

            insert_front(&r,sum1);

            car=sum/10;

            qtemp=qtemp->prev;
        }
    }
    if(car>0)
    {
        insert_front(&r,car);
    }
return r;
}



//Function to multiply 2 numbers stored in p and q, and store the result in s
struct node* mul(struct node **phead,struct node **qhead,struct node *s)
{
    struct node *r1 = NULL;
    struct node *r2 = NULL;
    struct node *ptemp;
    struct node *qtemp;
    struct node *prear;
  //  struct node *qrear;
    int prod,car,prod1,i;
    int count=0;
    ptemp=*phead;
    qtemp=*qhead;
    while(ptemp->next!=NULL)
    {
        ptemp=ptemp->next;
    }
    prear=ptemp;

    while(qtemp->next!=NULL)
    {
        qtemp=qtemp->next;
    }
   // qrear=qtemp;
    insert_front(&r1,0);

        while(qtemp!=NULL)
        {
            car=0;
            r2=NULL;
            ptemp=prear;
            for(i=0;i<count;i++)
            {
                insert_front(&r2,0);
            }
             while (ptemp!=NULL)
            {
                //printf("inside 2nd while");
                prod=((qtemp->num)*(ptemp->num))+car;
                prod1=prod%10;
                car=prod/10;

                insert_front(&r2,prod1);

                ptemp=ptemp->prev;
            }
            if(car>0)
            {
                insert_front(&r2,car);
            }
            r1=add(&r1,&r2,s);
            // display(r1);
            //display(r2);
            qtemp=qtemp->prev;
            count++;
        }


        s=r1;
        return s;



           #if 0
           if(qtemp->prev!=NULL)
            {
            qtemp=qtemp->prev;
            insert_front(&s,0);
            ptemp=prear;
            car=0;
            while (ptemp!=NULL)
            {
                prod=((qtemp->num)*(ptemp->num))+car;
                prod1=prod%10;
                car=prod/10;
                insert_front(&s,prod1);
                ptemp=ptemp->prev;
            }
            }
            display(r1);
            display(r2);
    //return 0;
 #endif
}

