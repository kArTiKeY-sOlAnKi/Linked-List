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

void insert_at_tail(node *&head, int data)
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

void print(node *head)
{
	while (head != NULL)
	{
		cout<<head->data<<" " ;
		head = head -> next ;
	}
}

void k_append(node *&head, int n, int k)
{
	// list is 1 2 2 1 8 5 6
	// o/p shd be 8 5 6 1 2 2 1
	node *temp = head ;
	node *temp2 = head ;
	int count = 0 ;

	while (count < n - k)
	{
		temp = temp -> next ;
		count++ ;
	}

	// temp is now at 8
	head = temp ;
	temp = head ;
	while (temp -> next != NULL)
	{
		temp = temp -> next ;
	}

	// head is now at 6
	temp -> next = temp2 ; // temp is now pointing to 1
	temp2 = head ;

	while (n > 1)
	{
		temp2 = temp2 -> next ;
		n-- ;
	}

	temp2 -> next = NULL ;
	
}

int main ()
{
	int n, k, data ;
	node *head = NULL ;

	cin>>n ;
	int temp = n ;

	while (temp > 0)
	{
		cin>>data ;
		insert_at_tail(head,data) ;
		temp-- ;
	}

	cin>>k ;
	k = k % n ;
	
	if (k == 0 or k < 0)
	{
		print(head) ;
	}

	else
	{
		k_append(head,n,k) ;

		node *temp2 = head ;

		print(head) ;
	}

	return 0 ;
}