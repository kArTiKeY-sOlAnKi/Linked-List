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

void insert(node *&head, int data)
{
	node *n = new node(data) ;
	node *temp = head ;

	n -> next = head ;
	if (temp != NULL)
	{
		while(temp -> next != head)
		{
			temp = temp -> next ;
		}

		temp -> next = n ;
	}
	else
	{
		n -> next = n ;
	}

	head = n ;
}

node *find_pos(node *head, int data)
{
	// consider that linked list is
	// 1 -> 2 -> 3 -> 4 -> 5
	// need to find pos of 3 which is pos 3
	node *temp = head ;
	while(temp != NULL)
	{
		if (temp->data == data)
		{
			return temp ;
			break ;
		}
		temp = temp -> next ;
	}
}

void delete_element(node *&head, int data)
{
	// corner case
	if (head == NULL)
	{
		return ;
	}

	// finding the pos of prev node to that node which will be deleted
	node *pos = find_pos(head,data) ; // pos is pointing to the element which will be deleted, so pos is 3
	if (pos == head)
	{
		node *temp = head -> next ; // 1 2 3 4 5
		while(temp != head)
		{
			if(temp -> next == head)
			{
				temp -> next = head -> next ;
				delete head ;
				head = temp -> next ;
				break ;
			}
			temp = temp -> next ;
		}
	}
	else
	{
		node *temp = head ;
		while(temp -> next != head) // as this is circular queue, so it shd not reach head
		{
			if (temp -> next == pos)
			{
				temp -> next = pos -> next ;
				delete pos ;
			}
			temp = temp -> next ;
		}
	}
}

void print(node *head)
{
	node *temp = head ;
	while(temp -> next != head)
	{
		cout<<temp -> data<<" -> " ;
		temp = temp -> next ;
	}
	cout<<temp->data<<endl ;
	return ;
}

int main ()
{
	node *head = NULL ;
	insert(head,5) ;
	insert(head,4) ;
	insert(head,3) ;
	insert(head,2) ;
	insert(head,1) ;

	print(head) ;

	// deleting element in the list
	int ele ;
	cout<<"Enter element to be deleted : " ;
	cin>>ele ;

	delete_element(head,ele) ;

	cout<<"*****After deletion*****"<<endl ;
	print(head) ;

	return 0 ;
}