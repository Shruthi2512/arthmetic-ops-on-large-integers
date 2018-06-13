#ifndef HEADER_H
#define HEADER_H

struct node
{
  int num;
  struct node *next;
  struct node *prev;
};

int getnumber(struct node **);
void release(struct node **);
void display(struct node *);
void insert_front(struct node **, int);
struct node* add(struct node**,struct node**,struct node*);
struct node* mul(struct node**,struct node**,struct node*);


#endif
