#include <iostream>
using namespace std ;

class node
{
	public:
		int data ;
		node *next ;

		node (int d)
		{
			data = d ;
			next = NULL ;
		}
};

void insert_at_head(node *& head, int data)
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

node *take_input()
{
	int data ;
	node *head = NULL ;

	while (data != -1)
	{
		cin>>data ;
		insert_at_head(head,data) ;
	}

	return head ;
}

istream& operator>>(istream &is, node *&head)
{
	head = take_input() ;
	return is ;
}

void reverse(node *&head)
{
	node *current = head ;
	node *prev = NULL ;
	node *temp ;

	while (current != NULL)
	{
		temp = current -> next ;
		current -> next = prev ;

		prev = current ;
		current = temp ;
	}

	head = prev ;
}

void last_kth(node *head, int k)
{
	int count = 0 ;

	while(count != k)
	{
		head = head -> next ;
		count++ ;
	}

	cout<<head->data<<endl ;
}

int main ()
{
	int k ;
	node *head = NULL ;

	cin>>head ;

	// reverse(head) ;

	cin>>k ;

	last_kth(head,k) ;

	return 0 ;
}