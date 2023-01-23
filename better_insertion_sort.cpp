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

void print(node *head)
{
	while (head != NULL)
	{
		cout<<head -> data<<" " ;
		head = head -> next ;
	}
}

node *insertion_sort(node *head)
{
	node *dummy = new node(0), *current = head ; // dummy node

	node *temp, *prev, *nxt ;

	while (current != NULL)
	{
		temp = current -> next ;
		prev = dummy ;
		nxt = dummy -> next ;

		while (nxt != NULL)
		{
			if (nxt -> data > current -> data)
			{
				break ;
			}

			prev = nxt ;
			nxt = nxt -> next ;
		}

		current -> next = nxt ;
		prev -> next = current ;
		current = temp ;
	}

	return dummy -> next ;
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

	print(temp) ;

	return 0 ;
}