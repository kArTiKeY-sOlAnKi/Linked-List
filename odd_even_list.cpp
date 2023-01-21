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

void odd_even_list(node *head, int n)
{
	node *temp = head ;
	int count = 0 ;

	// for odd numbers
	while (temp != NULL)
	{
		if (temp -> data % 2 != 0)
		{
			cout<<temp->data<<" " ;
		}
		temp = temp -> next ;
	}

	while (head != NULL)
	{
		if (head -> data % 2 == 0)
		{
			cout<<head->data<<" " ;
		}
		head = head -> next ;
	}
}

int main ()
{
	int n, count = 0, data ;
	cin>>n ;
	node *head = NULL ;

	while(count < n)
	{
		cin>>data ;
		insert_at_head(head,data) ;
		count++ ;
	}

	reverse(head) ;

	odd_even_list(head,n) ;

	return 0 ;
}