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

node *insert_properly(node *head, node *temp)
{
	if (head == NULL or head -> data >= temp -> data)
	{
		temp -> next = head ;
		return temp ;
	}

	node *parse = head ;

	while (head -> next != NULL and (head -> next) -> data < temp -> data)
	{
		head = head -> next ;
	}

	temp -> next = head -> next ;
	head -> next = temp ;

	return parse ;
}

node *insertion_sort(node *head) 
{
	node *sorted = NULL ;

	while (head != NULL)
	{
		node *temp = head -> next ;
		sorted = insert_properly(sorted,head) ;
		head = temp ;
	}

	return sorted ;
}

void print(node *head)
{
	while (head != NULL)
	{
		cout<<head -> data<<" " ;
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

	node *temp = insertion_sort(head) ;

	print(head) ;

	return 0 ;
}