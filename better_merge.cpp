#include <iostream>
using namespace std ;

class node
{
	public:
		int data ;
		node *next ;

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

	node *tail = head ;
	while (tail -> next != NULL)
	{
		tail = tail -> next ;
	}

	tail -> next = new node(data) ;
	return ; 
}

node *merge_lists(node *a, node *b)
{
	// solving through recursion
	// corner case
	if (a == NULL)
	{
		return b ;
	}

	else if (b == NULL)
	{
		return a ;
	}

	node *temp ;

	if (a -> data < b -> data)
	{
		temp = a ;
		temp -> next = merge_lists(a->next,b) ;
	}

	if (b -> data < a -> data)
	{
		temp = b ;
		temp -> next = merge_lists(a,b->next) ;
	}

	return temp ;
}

void print(node *head)
{
	while(head != NULL)
	{
		cout<<head->data<<" " ;
		head = head -> next ;
	}
}

int main ()
{
	int test_case, a_size, b_size ;

	cin>>test_case ;

	while(test_case > 0)
	{
		int data ;
		cin>>a_size ;
		node *a = NULL, *b = NULL ;
		while(a_size > 0)
		{
			cin>>data ;
			insert_at_head(a,data) ;
			a_size-- ;
		}

		cin>>b_size ;
		while(b_size > 0)
		{
			cin>>data ;
			insert_at_head(b,data) ;
			b_size-- ;
		}

		node *dislpay = merge_lists(a,b) ;

		print(dislpay) ;
		cout<<endl ;

		test_case-- ;
	}

	return 0 ;
}