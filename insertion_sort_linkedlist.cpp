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
		return ;
	}

	node *n = new node(data) ;
	n -> next = head ;
	// n -> prev = NULL ;

	// while (head != NULL)
	// {
	// 	head -> prev = n ;
	// }

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

/*void insertion_sort(node *&head, node *&tail)
{
	node *new_head ;
	while(head != NULL)
	{
		int ele = tail -> data ;
		node *j = head -> prev ;
		while (j != NULL and j -> data > ele)
		{
			(j -> next) -> data = j -> data ;
			j = j -> prev ;
		}

		(j -> next) -> data = ele ;
		head = head -> next ;
	}

	new_head = head ;
}*/

void sorted_insert(node *current, node *&sorted)
{
	if (sorted == NULL or sorted -> data >= current -> data)
	{
		current -> next = sorted ;
		sorted = current ;
	}

	else
	{
		node *temp = sorted ;

		while (temp -> next != NULL and (temp -> next)->data < current -> data)
		{
			temp = temp -> next ;
		}
		current -> next = temp -> next ;
		temp -> next = current ;
	}
}

void insertion_sort(node *&head)
{
	node *sorted = NULL ; // temp pointer variable
	node *current = head ;

	while (current != NULL)
	{
		// node *next = current -> next ;
		sorted_insert(current,sorted) ;
		// current = next ;
		current = current -> next ;
	}

	head = sorted ;
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
	int n, data ;
	cin>>n ;
	node *head = NULL ;

	while (n > 0)
	{
		cin>>data ;
		insert_at_head(head,data) ;
		n-- ;
	}

	// // reverse(head) ;

	// node *temp = head ;

	// while (temp -> next != NULL)
	// {
	// 	temp = temp -> next ;
	// }

	// node *tail = temp ;

	insertion_sort(head) ;

	print(head) ;

	return 0 ;
}