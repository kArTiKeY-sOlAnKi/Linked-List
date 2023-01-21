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

	node *n = new node(data) ;
	n -> next = head ;
	head = n ;
}

void print(node *head)
{
	while(head != NULL)
	{
		cout<<head->data<<" " ;
		head = head -> next ;
	}
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

void k_append(node *head, int n, int k)
{
	// list is 1 2 2 1 8 5 6
	// and o/p shd be 8 5 6 1 2 2 1 when k is 3

	int count = 1 ;
	node *temp = head ;

	while (count != n - k + 1)
	{
		temp = temp -> next ;
		count++ ;
	}

	// cout<<"Test Count : "<<count<<endl ;
	// cout<<"Test data : "<<temp->data<<endl ;
	node *temp2 = temp ; // temp2 is having the value 8

	while (count != n and temp != NULL)
	{
		cout<<temp->data<<" " ;
		temp = temp -> next ;
	}

	while (head -> data != temp2 -> data)
	{
		cout<<head->data<<" " ;
		head = head -> next ;
	}

}

int main ()
{
	int n, k, data ;
	cin>>n ;
	int count = 0 ;
	node *head = NULL ;

	while(count < n)
	{
		cin>>data ;
		insert_at_head(head,data) ;
		count++ ;
	}

	cin>>k ;

	reverse(head) ;  // list is reversed now

	k_append(head,n,k) ;

	// print(head) ;

	return 0 ;
}