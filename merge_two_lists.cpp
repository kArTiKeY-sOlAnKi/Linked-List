#include <iostream>
using namespace std ;

class node
{
	public:
		int data ;
		node *next ;
		node *prev ;

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
	int test_case, a_size, b_size ;

	cin>>test_case ;

	while(test_case > 0)
	{
		int count = 0, data ;
		cin>>a_size ;
		node *a = NULL ;
		while(count < a_size)
		{
			cin>>data ;
			insert_at_head(a,data) ;
			count++ ;
		}

		// cout<<"Printing first list : "<<endl ;
		// print(a) ;
		// cout<<endl ;

		// cout<<"Reversed First List is : "<<endl ;
		reverse_list(a) ;

		cin>>b_size ;
		count = 0 ;
		node *b = NULL ;
		while(count < b_size)
		{
			cin>>data ;
			insert_at_head(b,data) ;
			count++ ;
		}

		// cout<<"Printing second list : "<<endl ;
		// print(b) ;
		// cout<<endl ;

		reverse_list(b) ;

		node *dislpay = merge_lists(a,b) ;

		print(dislpay) ;
		cout<<endl ;

		test_case-- ;
	}

	return 0 ;
}