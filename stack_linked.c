#include<stdio.h>
#include<malloc.h>
void push(int x);
void pop();
struct node
{
	int data;
	struct node*next;
};
struct node*top;
void main()
{
	int choice,i=0,top,j,x; char ch;
	for(j=0;j<=i;j++)
	{
	printf("enter 1 for push,enter 2 for pop\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
			case 1:push(x);
			break;
			case 2:pop();
			break;
			default:printf("Stack after operation:\n");
	        traversal();
		}
		ch=getch();
		i++;
	}while(ch=='Y'||ch=='y');
}

}


void push(int x)
{
	struct node*new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter data you want to push=\n");
	scanf("%d",&x);
	new->data=x;
	new->next=top;
	top=new;
}
void pop()
{
	struct node*t;
	if(top==NULL)
	{
		printf("underflow");
	}
	else
	{
		t=top;
		top=top->next;
		free(t);
		t=NULL;
	}
}
int traversal()
{
struct node*p;
p=top;
while(p!=NULL)
{
	printf("%d\n",p->data);
	p=p->next;
}
}
