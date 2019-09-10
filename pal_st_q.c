#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
char data;
struct node *next;
}*top1=0,*rear2=0,*front2=0;

void push1(struct node**,char,struct node**);
void push(struct node**,char);

void push(struct node **top,char v)
{
	struct node *save=(struct node*)malloc(sizeof(struct node));
	if(*top==0)
	{
	save->data=v;
	save->next=0;
	*top=save;
	}
	else
	{
        save->data=v;
	save->next=*top;
	*top=save;
	}
}
void push1(struct node **rer,char q,struct node **frnt)
{
	struct node *sav=(struct node*)malloc(sizeof(struct node));
	if(*rer==0)
	{
	sav->data=q;
	sav->next=0;
	*rer=sav;
        *frnt=sav;
	}
	else
	{
        sav->data=q;
	sav->next=0;
	(*rer)->next=sav;
        *rer=sav;
	}
}
int main()
{
	int n,digit,digit1,val,flag=0;
	char str[20],*p;
	p=str;
	printf("ENTER THE NUMBER\n>>");
	scanf("%s",str);
	while((*p)!='\0')
	{
		push(&top1,*p);
                push1(&rear2,*p,&front2);
		p++;
	}
	while(front2 != 0)
	{
		if(top1->data!=front2->data)
		{
		flag=1;
		}
         top1=top1->next;
         front2=front2->next;
	}
	if(flag==1)
	{
	printf("\nSORRY, ITS NOT A PALINDROM NUMBER\n");
	}
	else
	{
	printf("\nYES, ITS A PALINDROM NUMBER\n");

	}
return 0;
}
