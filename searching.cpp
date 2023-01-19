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

int search(node *head, int key)
{
	// corner case
	if (head == NULL)
	{
		return 0 ;
	}
	node *temp = head ;
	int i = 1 ;
	while(temp != NULL)
	{
		if (temp -> data == key)
		{
			return i ;
			break ;
		}
		temp = temp -> next ;
		i++ ;
	}
}

// recursive search
bool search_recursive(node *head, int key)
{
	// corner case
	if (head == NULL)
	{
		return false ;
	}

	if (head -> data == key)
	{
		return true ;
	}

	else
	{
		return search_recursive(head -> next, key) ;
	}
}

int main ()
{
	node *head = NULL ;
	insert_at_head(head,4) ;
	insert_at_head(head,2) ;
	insert_at_head(head,1) ;
	insert_at_head(head,0) ;

	print(head) ;

	insert_in_middle(head,3,3) ;

	print(head) ;

	insert_at_tail(head,5) ;

	print(head) ;

	delete_head(head) ;

	print(head) ;

	// delete_at_tail(head) ;

	// print(head) ;

	delete_in_middle(head,100) ;

	print(head) ;

	int res = search(head,100) ;

	if (res)
	{
		cout<<"Found at index : "<<res<<endl ;
	}
	
	else
	{
		cout<<"Not Found .."<<endl ;
	}

	int key ;
	cin>>key ;

	if (search_recursive(head,key))
	{
		cout<<"Found"<<endl ;
	} 
	else
	{
		cout<<"Not Found"<<endl ;
	}

	return 0 ;
}