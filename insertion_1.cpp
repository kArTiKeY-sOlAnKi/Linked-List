#include <iostream>
using namespace std ;

// creating the node
class node
{
	public:
		int data ; // will hold the value for the node
		node *next ; // will hold the address for the next node which it will point

		// parameterized constructor
		node(int d)
		{
			data = d ; // tellling when value is passed, the value will store in d 
			next = NULL ; // and the address to which it will point is initialized with NULL
		}
};

void insert_at_head(node *&head, int data) //passed by ref otherwise after the scope of this funcn the value would be lost
{
	if (head == NULL)
	{
		head = new node(data) ; // for the first insertion, head because as the first node of the list is head
		return ;
	}
	node *n = new node(data) ; // for second and further insertions, value will be stored in the heap memory 
	n -> next = head ; // and address is stored in n, and n is storing the address of prev node i.e. the head
	head = n ; // lastly the head is updated to the current node
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

int main ()
{
	node *head = NULL ;
	insert_at_head(head,3) ;
	insert_at_head(head,2) ;
	insert_at_head(head,1) ;
	insert_at_head(head,0) ;

	print(head) ;
	print(head) ;

	return 0 ;
}