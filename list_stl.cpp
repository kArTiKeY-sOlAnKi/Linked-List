#include <iostream>
#include <list>
using namespace std ;

int main ()
{
	list<int> l ;

	// Init
	list<int> l1{1,2,3,4,5,6,7,8,9} ;

	// Different Datatype
	list<string> l2{"apple","guava","mango","banana"} ;
	l2.push_back("orange") ; // insertion at end

	// iterate over list
	cout<<"String is : " ;
	for (auto s:l2) // can also use for (string s:l2) o/p will be same
	{
		cout<<s<<"-->" ;
	}
	cout<<"NULL"<<endl ;

	// to sort the string
	cout<<endl<<"Sorted String is : " ;
	l2.sort() ;
	for (auto s:l2)
	{
		cout<<s<<"-->" ;
	}
	cout<<"NULL"<<endl ;

	// to reverse the string
	cout<<endl<<"Reversed String is : " ;
	l2.reverse() ;
	for (auto s:l2)
	{
		cout<<s<<"-->" ;
	}
	cout<<"NULL"<<endl ;

	// to remove head of the string
	cout<<endl<<"After head removal : " ;
	l2.pop_front() ;
	for (auto s:l2)
	{
		cout<<s<<"-->" ;
	}
	cout<<"NULL"<<endl ;

	// to insert head of the string
	cout<<endl<<"After head insertion : " ;
	l2.push_front("plum") ;
	for (auto s:l2)
	{
		cout<<s<<"-->" ;
	}
	cout<<"NULL"<<endl ;

	// using normal iteration
	// cout<<endl<<"Using normal iteration : " ;
	// for (auto it = l2.begin(); it != l2.end(); it++)
	// {
	// 	cout<<(*it)<<"-->" ;
	// }
	// cout<<endl ;

	// to remove a fruit 
	string f ;
	cout<<"Enter fruit name : " ;
	cin>>f ;
	l2.remove(f) ;
	cout<<"After removal : " ;
	for (auto s:l2)
	{
		cout<<s<<"-->" ;
	}
	cout<<"NULL"<<endl ;

	// erase from iteration
	auto it = l2.begin() ;
	it++ ;
	it++ ;
	l2.erase(it) ;
	for (auto s:l2)
	{
		cout<<s<<"-->" ;
	}
	cout<<"NULL"<<endl ;

	// insert from iteration
	it = l2.begin() ;
	it++ ;
	it++ ;
	l2.insert(it,"fruitjuice") ;
	for (auto s:l2)
	{
		cout<<s<<"-->" ;
	}
	cout<<"NULL"<<endl ;
	

	return 0 ;
}