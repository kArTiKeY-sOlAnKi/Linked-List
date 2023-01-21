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
			prev = NULL ;
		}
};

// using next as prev, prev as next, head as tail and tail as head
void insert_at_head(node *&head, int data, int count, int val)
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

void print(node *head)
{
	node *temp ;
	
	cout<<"Next Pointer : " ;
	while(head != NULL)
	{
		cout<<head->data<<"->" ;
		temp = head ;
		head = head -> next ;
	}
	cout<<"NULL"<<endl ;

	cout<<"Prev Pointer : " ;
	while(temp != NULL)
	{
		cout<<temp->data<<"->" ;
		temp = temp -> prev ;
	}
	cout<<"NULL" ;
}

void k_reverse(node *head,node *tail,int k, int size)
{
	// List is 5 6 2 3 8 7 1 4 9
	int count = 1, check = 0 ;
	node *temp = tail ; // temp is 9
	node *temp2 = temp ; // temp2 is also 9
	while(temp != head) // head is 5
	{
		while(count < k) // value of k is 3
		{
			temp2 = temp2 -> prev ;
			count++ ;
		}
		temp = temp2 ; // temp 2 is at 1, and also value of temp is also shifted to 1 from tail 9
		count = k - 1 ;
		while(count > -1) // value of count is 2
		{
			cout<<temp2->data<<" " ;
			check++ ;
			temp2 = temp2 -> next ;
			--count ;
		}
		count = 1 ;
		// temp = temp -> prev ;
		if (temp -> prev != NULL)
		{
			temp = temp -> prev ;
		}
		else
		{
			break ;
		}
		temp2 = temp ;
	}

	if (check != size)
	{
		cout<<temp->data ;
	}
}

int main ()
{
	int n, k, d ;
	node *head = NULL ;
	
	cin>>n>>k ; // n is 9 which is the total length of list and k is rev factor
	int count = 0 ;
	while(count < n)
	{
		cin>>d ;
		insert_at_head(head,d,count,n) ;
		count++ ;
	}

	node *temp = head ;
	while(temp -> next != NULL)
	{
		temp = temp -> next ;
	}

	node *tail = temp ;

	k_reverse(head,tail,k,n) ;

	return 0 ;
}