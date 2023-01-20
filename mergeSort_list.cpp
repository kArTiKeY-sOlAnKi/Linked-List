#include <iostream>
using namespace std ;

// creating node
class node
{
	public:

		int data ;
		node *next ;

		// parameterized constructor
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
		cout<<head -> data<<"->" ;
		head = head -> next ;
	}
	cout<<"NULL"<<endl ;
}

int length(node *head)
{
	int count = 0 ;
	while(head != NULL)
	{
		head = head -> next ;
		count++ ;
	}
	return count ;
}

void insert_at_tail(node *&head, int data)
{
	// corner case
	if (head == NULL)
	{
		insert_at_head(head,data) ;
		return ;
	}
	node *tail = head ;
	while(tail -> next != NULL)
	{
		tail = tail -> next ;
	}
	tail -> next = new node(data) ;
	return ;
}

void insert_in_middle(node *&head, int data, int p)
{
	// corner case
	if (head == NULL)
	{
		insert_at_head(head,data) ;
	}
	else if (p > length(head))
	{
		insert_at_tail(head,data) ;
	}
	else
	{
		int jump = 1 ;
		node *temp = head ;
		while(jump <= p-1)
		{
			temp = temp -> next ;
			jump++ ;
		}
		// create a new node
		node *n = new node(data) ;
		n -> next = temp -> next ;
		temp -> next = n ;
	}
}

void delete_head(node *&head)
{
	if (head == NULL)
	{
		return ;
	}
	node *temp = head -> next ;
	delete head ;
	head = temp ;
}

void delete_at_tail(node *&head)
{
	// corner case
	if (head == NULL)
	{
		return ;
	}
	if (head -> next == NULL)
	{ 
		delete head ;
		return ;
	}	
	// 1->2->3->4->5, so pointer shd come to 4, break the link with 5 tail of 4 shd be NULL and 5 shd be deleted
	int count = length(head) ; // count will have the value of 5
	int pointer = 1 ;
	node *temp = head ; // temp will start with head
	while(pointer != count - 1)
	{	
		temp = temp -> next ; // now temp will move forward
		pointer++ ; // and value of pointer will be increasing 	
	}
	// now temp is at second last node
	delete temp -> next ;
	temp -> next = NULL ;
}

void delete_in_middle(node *&head, int pos)
{
	// corner case
	if (head == NULL)
	{
		return ;
	}
	else if (pos > length(head))
	{
		delete_at_tail(head) ;
	}
	else if (pos <=1)
	{
		delete_head(head) ;
	}
	else
	{
		// list is 1->2->3->4->5, and pos is 3 so we need to delete the 3rd node which is 3
		// idea is to create two pointers one will go to that node and the other will on prev node
		// the pointer on prev node will now point to the next of other pointer node and it will be deleted
		int jump = 1 ;
		node *temp = head ;
		while(jump < pos)
		{
			temp = temp -> next ;
			jump++ ;
		}
		// temp is pointing now on the node which will be deleted
		node *prev = head ;
		jump = 1 ;
		while(jump < pos - 1)
		{
			prev = prev -> next ;
			jump++ ;
		}
		// prev is pointing to the prev node which will be deleted
		prev -> next = temp -> next ;
		delete temp ;
	}
}

node *take_input()
{
	int d ;
	cin>>d ;

	node *head = NULL ;
	while(d != -1)
	{
		insert_at_head(head,d) ;
		cin>>d ;
	}
	return head ;
}

node *input_txt_file()
{
	int d ;
	node *head = NULL ;
	while(cin>>d) // taking input till EOF
	{
		insert_at_head(head,d) ;
	}
	return head ;
}

ostream& operator<<(ostream &os, node *head)
{
	print(head) ;
	return os ;
}

istream& operator>>(istream &is, node *&head)
{
	head = take_input() ;
	return is ;
}

node *mid_point(node *head)
{
	// corner case
	if (head == NULL or head -> next == NULL)
	{
		return head ;
	}

	node *slow = head ;
	node *fast = head -> next ;

	while(fast != NULL and fast -> next != NULL)
	{
		fast = fast -> next -> next ;
		slow = slow -> next ;
	}
	return slow ;
}

node *kth_pos(node *head, int k)
{
	// corner case
	if (head == NULL or head -> next == NULL or k < 0)
	{
		return head ;
	}

	int counter = 1 ;
	// list is 1 2 3 4 5 6 7
	// length is 7 and k is 2 
	node *fast = head ;

	int len = length(head) ; // len is 7
	int diff = len - k ; // diff = 5

	while(counter <= diff)
	{
		fast = fast -> next ;
		counter++ ;
	}

	return fast ;
}

node *merge_list(node *a, node *b)
{
	// solving through recursion
	// base case
	if (a == NULL)
	{
		return b ;
	}

	if (b == NULL)
	{
		return a ;
	}

	node *temp ;

	if (a -> data < b -> data)
	{
		temp = a ;
		temp -> next = merge_list(a->next,b) ;
	}

	if (b -> data < a -> data)
	{
		temp = b ;
		temp -> next = merge_list(a,b->next) ;
	}

	return temp ;
}

node *mergeSort_list(node *&head)
{
	// Corner Case
	if (head == NULL or head -> next == NULL)
	{
		return head ;
	}

	node *mid = mid_point(head) ; // mid is 4
	node *a = head ;
	node *b = mid -> next ;
	// breaking the link
	mid -> next = NULL ;

	// rec sort the lists
	a = mergeSort_list(a) ;
	b = mergeSort_list(b) ;

	// merge them 
	head = merge_list(a,b) ;

	return head ;
}

int main ()
{
	node *head = NULL ;
	cout<<"Enter the linked list : " ;
	cin>>head ;

	cout<<"Sorted Linked List is : "<<mergeSort_list(head) ;

	return 0 ;
}