#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    struct node *p = NULL;
    struct node *q = NULL;
    struct node *r=NULL;
    struct node *s=NULL;
    int pcount = 0, qcount = 0;
    printf("Enter 1st number of any length\n");
    pcount = getnumber(&p);
    printf("Enter 2nd number of any length\n");
    qcount = getnumber(&q);

    printf("Number of digits entered in the 1st number are: %d\n", pcount);
    printf("Number of digits entered in the 2nd number are: %d\n", qcount);

    printf("Displaying the numbers entered:\n");
    display(p);
    display(q);

    r=add(&p,&q,r);
    printf("The sum is: ");
    display(r);
    s=mul(&p,&q,s);
    printf("The product is: ");
    display(s);


    release(&p);
    release(&q);
    release(&r);
    release(&s);

    return 0;
}
