#include <iostream>
using namespace std ;
#define ll long long

class node
{
	public:
		int data ;
		node *next ;
		node *prev ;

		node(int d)
		{
			data = d  ;
			next = NULL ;
			prev = NULL ;
		}
};

void insert_at_head(node *& head, ll data)
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

node *merge_optimised(node *a_tail, node *b_tail)
{
	// corner case
	if (a_tail == NULL)
	{
		return b_tail ;
	}

	if (b_tail == NULL)
	{
		return a_tail ;
	}

	node *temp ;

	if (a_tail -> data < b_tail -> data)
	{
		temp = a_tail ;
		temp -> prev = merge_optimised(a_tail->prev,b_tail) ;
	}

	if (b_tail -> data < a_tail -> data)
	{
		temp = b_tail ;
		temp -> prev = merge_optimised(a_tail,b_tail->prev) ;
	}

	return temp ;
}

void print(node *tail)
{
	while(tail != NULL)
	{
		cout<<tail->data<<" " ;
		tail = tail -> prev ;
	}
}

int main ()
{
	int testcase ;
	cin>>testcase ;

	while(testcase > 0)
	{
		ll a_size, b_size, count = 0, data ;

		// 1st list
		node *a = NULL, *a_tail ;
		cin>>a_size ;
		while (count < a_size)
		{
			cin>>data ;
			insert_at_head(a,data) ;
			count++ ;
		}
		node *temp = a ;
		while(temp->next != NULL)
		{
			temp = temp -> next ;
		}
		a_tail = temp ;

		// 2nd List
		node *b = NULL, *b_tail ;
		count = 0 ;
		cin>>b_size ;
		while(count < b_size)
		{
			cin>>data ;
			insert_at_head(b,data) ;
			count++ ;
		}
		temp = b ;
		while(temp->next != NULL)
		{
			temp = temp -> next ;
		}
		b_tail = temp ;

		// need to pass tail instead of head
		node *display = merge_optimised(a_tail,b_tail) ;
		print(display) ;

		testcase-- ;
	}

	return 0 ;
}