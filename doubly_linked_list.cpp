#include <iostream>
using namespace std ;

class node
{
	public:
		int data ;
		node *next ;
		node *prev ;

		// parameterized constructor
		node (int d)
		{
			data = d ;
			next = NULL ;
			prev = NULL ;
		}
};

void insert_at_tail(node *&head, int data)
{
	// corner case
	if (head == NULL)
	{
		head = new node(data) ;
		return ;
	}

	node *n = new node(data) ;
	n -> next = head ;
	n -> prev = NULL ;

	if (head != NULL)
	{
		head -> prev = n ;
	}

	head = n ;
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

void insert_in_middle(node *&head, int data, int pos)
{
	// corner case
	if (head == NULL or pos == 0)
	{
		insert_at_tail(head,data) ;
	}

	else if (pos > length(head))
	{
		insert_at_tail(head,data) ;
	}	
	
	else
	{
		// take pos-1 jumps
		int jump = 0 ;
		node *temp = head ;

		while(jump < pos - 1)
		{
			temp = temp -> next ;
			jump++ ;
		}

		node *n = new node(data) ;
		n -> next = temp -> next ;
		temp -> next = n ; // temp is head and n is new node
		// extra part for prev node
		// cout<<temp->data ; 
		n -> prev = temp ;
		temp = temp -> next -> next ;
		temp -> prev = n ;
	}	
}

void insert_at_end(node *&head, int data)
{
	// corner case
	if (head == NULL)
	{
		insert_at_tail(head,data) ;
	}

	else
	{
		int count = length(head) ;
		node *temp = head ;
		int jump = 1 ;
		while(jump != count)
		{
			temp = temp -> next ;
			jump++ ;
		}
		// jump is temp
		node *n = new node(data) ; // for new insertion at the end
		n -> prev = temp ; // prev of n will point to head
		temp -> next = n ;
		n -> next = NULL ;
	}
}

void delete_head(node *&head)
{
	// corner case
	if (head == NULL or head -> next == NULL)
	{
		return ;
	}

	node *temp = head ;
	temp = temp -> next ;
	delete head ;
	head = temp ;
	head -> prev = NULL ;
}

void delete_at_tail(node *&head)
{
	// corner case
	if (head == NULL or head -> next == NULL)
	{
		return ;
	}

	int count = length(head) ; // count is 6
	int jump = 1 ;
	node *temp = head ;
	// 1 2 3 4 5 6
	while(jump != count - 1) // count-1 is 5
	{
		temp = temp -> next ;
		jump++ ;
	}

	// temp is at 5
	delete temp -> next ;
	temp -> next = NULL ;	
}

void delete_in_middle(node *&head, int pos)
{
	// corner case
	if (head == NULL or head -> next == NULL)
	{
		cout<<"Only one element in the list"<<endl ;
		cout<<"No deletion taking place"<<endl ;	
		return ;
	}

	else if (pos > length(head))
	{
		cout<<"Postion greater than the length of linked list"<<endl ;
		return ;
	}

	else if (pos == 1)
	{
		delete_head(head) ;
	}

	else
	{
		// 2 3 4 5 and I want to delete at positon 3 which is 4
		// so updated list should look like 2 3 5
		int jump = 1 ;
		int count = length(head) ; // value of count will be 4
		node *temp = head ;

		while(jump < pos - 1)
		{
			temp = temp -> next ;
			jump++ ;
			// cout<<"Jump : "<<jump<<endl ;
		}
		// now temp is at 3
		node *n = temp -> next ; // n is pointing to 4
		// temp -> next = temp -> next -> next ; // next of 3 will point to 5 
		temp -> next = n -> next ; // 3 is pointing to 5
		delete n ; // 4 is deleted
		n = temp ;
		temp = temp -> next ; // temp is now moved to 5
		temp -> prev = n ;
	}
}

void print(node *head)
{
	node *temp ;
	cout<<"Next Pointer : " ;
	while(head != NULL)
	{
		cout<<head -> data<<" -> " ;
		temp = head ;
		head = head -> next ;
	}
	cout<<"NULL" ;
	cout<<endl ;
	cout<<"Prev Pointer : " ;
	while(temp != NULL)
	{
		cout<<temp -> data<<" -> " ;
		temp = temp -> prev ;
	}
	cout<<"NULL" ;
}

int main ()
{
	node *head = NULL ;
	// node *prev = NULL ;
	insert_at_tail(head,5) ;
	insert_at_tail(head,3) ;
	insert_at_tail(head,2) ;
	insert_at_tail(head,1) ;

	insert_in_middle(head,4,3) ;

	print(head) ;

	cout<<endl<<"*****After inserting at end*****"<<endl ;

	insert_at_end(head,6) ; 

	print(head) ;

	cout<<endl<<"*****Deletion of Head*****"<<endl ;
	delete_head(head) ;

	print(head) ;
	cout<<endl ;

	cout<<"*****Deletion of Tail*****"<<endl ;
	delete_at_tail(head) ; // not working need to check

	print(head) ;

	cout<<endl<<"*****Deletion in Middle*****"<<endl ;
	delete_in_middle(head,2) ;

	print(head) ;

	return 0 ;
}