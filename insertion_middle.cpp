#include <iostream>
using namespace std ;

// creating the node
class node
{
	public:
		int data ; 
		node *next ;

		// parameterized constructor
		node(int d)
		{
			data = d ; 
			next = NULL ; 
		}
};

void insert_at_head(node *&head, int data) 
{
	if (head == NULL)
	{
		head = new node(data) ; 
		return ;
	}
	node *n = new node(data) ;  
	n -> next = head ; 
	head = n ; 
}

void print(node *head)
{
	while(head != NULL)
	{
		cout<<head -> data<<"->" ;
		head = head -> next ;
	}
	cout<<"NULL"<<endl ;
}

void insert_at_tail(node *&head, int data)
{
	// corner case
	if (head == NULL)
	{
		head = new node(data) ;
		return ;
	}
	node *tail = head ; // tail starts with head
	while(tail -> next != NULL)
	{
		tail = tail -> next ;
	}
	tail -> next = new node(data) ;
	return ;
}

int length(node *head)
{
	int count = 0 ;
	while(head != NULL)
	{
		count++ ;
		head = head -> next ;
	}
	return count ;
}

void insert_in_middle(node *&head, int data, int p)
{
	// corner case
	if (head == NULL or p == 0)
	{
		insert_at_head(head,data) ;
	}
	else if (p > length(head))
	{
		insert_at_tail(head,data) ;
	}
	else
	{
		// take p-1 jumps
		int jump = 1 ;
		node *temp = head ;
		while(jump <= p-1)
		{
			temp = temp -> next ;
			jump++ ;
		}
		// create a new node
		node *n = new node(data) ; // new node is created for the new insertion 
		n -> next = temp -> next ; // new node will point to its next node
		temp -> next = n ; // this will break the linkage and the prev node will point to new node
	}
}

int main ()
{
	node *head = NULL ;
	insert_at_head(head,5) ;
	insert_at_head(head,2) ;
	insert_at_head(head,1) ;
	insert_at_head(head,0) ;
	print(head) ;
	
	insert_in_middle(head,4,3) ;
	print(head) ;

	insert_at_tail(head,6) ;
	print(head) ;

	return 0 ;
}