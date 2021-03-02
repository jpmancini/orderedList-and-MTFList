#ifndef MTFLIST_H
#define MTFLIST_H

#include "node.h"

using namespace std;

class MTFList
{
public:
	MTFList();
	void remove(const int&);
	void add(const int&);
	void search(const int&);
	void print() const;

private:
	unsigned sz;
	Node *frontPtr;
	Node *backPtr;

	void initialize();

}; //MTFList class

/***************
**CONSTRUCTORS**
***************/

//defualt constructor
MTFList::MTFList()
{
	initialize();
} //MTFList::MTFList

/*******************
**MEMBER FUNCTIONS**
*******************/

//printing
void MTFList::print() const
{
	Node *ptr = frontPtr;

	for (unsigned i = 0; i < sz; i++)
	{
		cout << ptr->getValue() << " ";
		ptr = ptr->getNextPtr();
	}

	//cout << frontPtr->getValue() << endl;
	//cout << backPtr->getValue() << endl;

	cout << endl;
} //MTFList::print

//intializing
void MTFList::initialize()
{
	sz = 0;
	frontPtr = 0;
}


//removing
void MTFList::remove(const int& deletion)
{
	//cout << "remove" << endl;

	Node *ptr = frontPtr;
	Node *trail = frontPtr;

	//cout << "0" << endl;

	if (frontPtr->getValue() == deletion)
	{
		if (frontPtr == backPtr)
		{
			delete ptr;
		}
		else
		{
			//cout << "entered";
			ptr = ptr->getNextPtr();
			delete trail;
			trail = ptr;
			frontPtr = ptr;
		}
		sz--;
	}

	//cout << "1" << endl;

	while(ptr != backPtr)
	{
		//cout << "in loop" << endl;
		if (ptr->getNextPtr() == backPtr)
		{
			//cout << "checks back" << endl;
			if (backPtr->getValue() == deletion)
			{
				//cout << "if" << endl;
				delete backPtr;
				backPtr = ptr;
				sz--;
			}
			else
			{
				//cout << "else" << endl;
				ptr = backPtr;
			}
		}
		else if (ptr->getNextPtr()->getValue() == deletion)
		{
			//cout << "deleted" << endl;
			ptr = ptr->getNextPtr();
			trail->setNextPtr(ptr->getNextPtr());
			delete ptr;
			ptr = trail;
			sz--;
		}
		else
		{
			ptr = ptr->getNextPtr();
			trail = ptr;
		}

		//cout << "out" << endl;
	}

	//cout << "loop over" << endl;
} //MTFList::remove

//adding
void MTFList::add(const int& value)
{
	Node *newNode = new Node(value);

	if (sz == 0)
	{
		backPtr = newNode;
	}
	else
	{
		newNode->setNextPtr(frontPtr);
	}

	frontPtr = newNode;
	sz++;
} //MTFList::add

void MTFList::search(const int& value)
{
	if (frontPtr->getValue() != value)
	{
		unsigned oldsz = sz;

		remove(value);

		if (sz < oldsz)
			add(value);
	}
}


#endif // MTFList_H



