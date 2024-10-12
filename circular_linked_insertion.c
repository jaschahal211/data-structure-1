#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node*next;
};
struct node*s;
struct node*create(struct node*s);
struct node*insert_beg(struct node*s);
struct node*insert_end(struct node*s);
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
struct node*insert_beg(struct node*s);
{
	struct node*r,*i;
    r=(struct node*)malloc(sizeof(struct node));
	printf("enter data of the node that you want to insert at beg=\n");
	scanf("%d",&r->data);
	i=s;
	while(i->next!=s)
	{
		i=i->next;
	}
	r->next=s;
	i->next=r;
	s=r;
	printf("%d inserted at beg\n",r->data);
}
struct node*insert_end(struct node*s);
{
	struct node*j,*l;
	j=(struct node*)malloc(sizeof(struct node));
	printf("enter data of the node that you want to insert at end=\n");
	scanf("%d",&j->data);
	l=s;
	while(l->next!=s)
	{
		l=l->next;
	}
	l->next=j;
	j->next=s;
	printf("%d inserted at end\n",j->data);
}
struct node*traversal(struct node*s);
{
	struct node*m;
	m=s;
	printf("after performing insert operations circular linked list is:\n");
	while(m->next!=s)
	{
		printf("%d\n",m->data);
		m=m->next;
	}
	printf("%d",m->data);
}

struct node*create(struct node*s);
struct node*insert_beg(struct node*s);
struct node*insert_end(struct node*s);
struct node*traversal(struct node*s);

}
