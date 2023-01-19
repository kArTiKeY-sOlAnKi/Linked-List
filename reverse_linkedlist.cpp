#include <iostream>
using namespace std ;

// creating node
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
	// corner case
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

int length(node *head)
{
	int count = 0 ;
	while(head != NULL)
	{
		head = head -> next ;
		count++ ;
	}
	return count ;
}

void insert_at_tail(node *&head, int data)
{
	// corner case
	if (head == NULL)
	{
		insert_at_head(head,data) ;
		return ;
	}
	node *tail = head ;
	while(tail -> next != NULL)
	{
		tail = tail -> next ;
	}
	tail -> next = new node(data) ;
	return ;
}

void insert_in_middle(node *&head, int data, int p)
{
	// corner case
	if (head == NULL)
	{
		insert_at_head(head,data) ;
	}
	else if (p > length(head))
	{
		insert_at_tail(head,data) ;
	}
	else
	{
		int jump = 1 ;
		node *temp = head ;
		while(jump <= p-1)
		{
			temp = temp -> next ;
			jump++ ;
		}
		// create a new node
		node *n = new node(data) ;
		n -> next = temp -> next ;
		temp -> next = n ;
	}
}

void delete_head(node *&head)
{
	if (head == NULL)
	{
		return ;
	}
	node *temp = head -> next ;
	delete head ;
	head = temp ;
}

void delete_at_tail(node *&head)
{
	// corner case
	if (head == NULL)
	{
		return ;
	}
	if (head -> next == NULL)
	{ 
		delete head ;
		return ;
	}	
	// 1->2->3->4->5, so pointer shd come to 4, break the link with 5 tail of 4 shd be NULL and 5 shd be deleted
	int count = length(head) ; // count will have the value of 5
	int pointer = 1 ;
	node *temp = head ; // temp will start with head
	while(pointer != count - 1)
	{	
		temp = temp -> next ; // now temp will move forward
		pointer++ ; // and value of pointer will be increasing 	
	}
	// now temp is at second last node
	delete temp -> next ;
	temp -> next = NULL ;
}

void delete_in_middle(node *&head, int pos)
{
	// corner case
	if (head == NULL)
	{
		return ;
	}
	else if (pos > length(head))
	{
		delete_at_tail(head) ;
	}
	else if (pos <=1)
	{
		delete_head(head) ;
	}
	else
	{
		// list is 1->2->3->4->5, and pos is 3 so we need to delete the 3rd node which is 3
		// idea is to create two pointers one will go to that node and the other will on prev node
		// the pointer on prev node will now point to the next of other pointer node and it will be deleted
		int jump = 1 ;
		node *temp = head ;
		while(jump < pos)
		{
			temp = temp -> next ;
			jump++ ;
		}
		// temp is pointing now on the node which will be deleted
		node *prev = head ;
		jump = 1 ;
		while(jump < pos - 1)
		{
			prev = prev -> next ;
			jump++ ;
		}
		// prev is pointing to the prev node which will be deleted
		prev -> next = temp -> next ;
		delete temp ;
	}
}

node *take_input()
{
	int d ;
	cin>>d ;

	node *head = NULL ;
	while(d != -1)
	{
		insert_at_head(head,d) ;
		cin>>d ;
	}
	return head ;
}

node *input_txt_file()
{
	int d ;
	node *head = NULL ;
	while(cin>>d) // taking input till EOF
	{
		insert_at_head(head,d) ;
	}
	return head ;
}

ostream& operator<<(ostream &os, node *head)
{
	print(head) ;
	return os ;
}

istream& operator>>(istream &is, node *&head)
{
	head = take_input() ;
	return is ;
}

void reverse_list(node *&head)
{
	// we will swap addresses of the nodes
	// instead of values, as it will be a very expensive operation
	// 1 -> 2 -> 3 -> 4 -> 5
	node *current = head ;
	node *prev = NULL ;
	node *temp ;

	while(current != NULL)
	{
		// save the address of the next node
		temp = current -> next ;

		// current node will point to the prev node
		current -> next = prev ;

		prev = current ;
		current = temp ;
	}
	head = prev ;
}

int main ()
{
	node *head ;

	cin>>head ;
	cout<<"Linked List which was entered is : "<<head ;

	reverse_list(head) ;
	cout<<"Reversed linked list is : "<<head ;

	return 0 ;
}