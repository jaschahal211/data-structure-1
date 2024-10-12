#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node*next;
};
struct node*s;
struct node*create(struct node*s);
struct node*delete_end(struct node*s);
struct node*delete_beg(struct node*s);
struct node*traversal(struct node*s);

void main()
{
struct node*create(struct node*s);
{
	struct node*p,*q;char ch;
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter data of the node=\n");
	scanf("%d",&p->data);
	s=p;
	do
	{
	q=(struct node*)malloc(sizeof(struct node));
	printf("enter data of the node=\n");
	scanf("%d",&q->data);
	p->next=q;
	p=q;
	printf("enter y for nodes to create\n");
	ch=getch();
	}while(ch=='y'||ch=='Y');
	p->next=s;
}
struct node*delete_beg(struct node*s);
{ 
	struct node*t;
	t=s;
	while(t->next!=s)
	{ 
		t=t->next;
	}
	t->next=s->next;
	free(s);
	s=t->next;
}
struct node*delete_end(struct node*s);
{
	struct node*w,*e;
	w=s;
	while(w->next!=s)
	{
		e=w;
		w=w->next;
	}
	e->next=s;
	free(w);
}
struct node*traversal(struct node*s);
{
	struct node*m;
	m=s;
	printf("after performing delete operations circular linked list is:\n");
	while(m->next!=s)
	{
		printf("%d\n",m->data);
		m=m->next;
	}
	printf("%d",m->data);
}
struct node*create(struct node*s);
struct node*delete_end(struct node*s);
struct node*delete_beg(struct node*s);
struct node*traversal(struct node*s);
}

