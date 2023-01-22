#include <iostream>
using namespace std ;

class node
{
	public:
		int data ;
		node *next ;
		node *prev ;

		node (int d)
		{
			data = d ;
			next = NULL ;
			prev = NULL ;
		}
};

void insert_at_head(node *&head, int data)
{
	// corner case
	if (head == NULL)
	{
		head = new node(data) ;
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

node *mid_point(node *head)
{
	node *fast = head -> next ;
	node *slow = head ;

	while (fast != NULL and fast -> next != NULL)
	{
		fast = fast -> next -> next ;
		slow = slow -> next ;
	}

	return slow ;
}

bool palindrome(node *head, node *mid)
{
	// list is 1 2 3 4 5
	node *temp = head ;
	node *tail ;

	while (temp -> next != NULL)
	{
		temp = temp -> next ;
	}

	tail = temp ;
	tail = tail -> prev ;

	while (head != mid and tail != mid)
	{
		if (head -> data != tail -> data)
		{
			return false ;
			break ;
		}
		head = head -> next ;
		tail = tail -> prev ;
	}
	return true ;
}

int main ()
{
	int n, data ;
	node *head = NULL ;	
	cin>>n ;

	while (n > 0)
	{
		cin>>data ;
		insert_at_head(head,data) ;
		n-- ;
	}

	node *mid = mid_point(head) ; // mid is having the address of the mid point

	if (palindrome(head,mid))
	{
		cout<<"true"<<endl ;
	}

	else
	{
		cout<<"false" ;
	}

	return 0 ;
}