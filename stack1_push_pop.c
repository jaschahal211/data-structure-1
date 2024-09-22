#include<stdio.h>
#define max 10
int stack1[max],top=-1;
void push();
int pop();
void main()
{   
	int choice,i=0,top,j; char ch;
	for(j=0;j<=i;j++)
	{
	printf("enter 1 for push,enter 2 for pop\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			default:printf("Stack after operation:\n");
	        for(i=i-1;i>=0;i--)
	        {
		    printf("%d\n",stack1[i]);
	        }
		}
		ch=getch();
		i++;
	}while(ch=='Y'||ch=='y');
}

}
void push(int num)
{
	if(top==max)
	{
		printf("stack overflow\n");
	}
	else
	{
		printf("enter number you want to push in stack\n");
		scanf("%d",&num);
		top=top+1;
		stack1[top]=num;
	}
	printf("press y for more elements to push\n");
}
int pop()
{
	int store;
	if(top==-1)
	{
		printf("stack underflow\n");
	}
	else
	{
		store=stack1[top];
		top=top-1;
		printf("%d is popped from stack\n",store);
	}
	printf("press y for more elements to pop\n");
}

