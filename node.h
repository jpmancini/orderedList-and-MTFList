#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node 
{
	public:
		Node( const int& );
		void setValue( const int& );
		int& getValue();
		void setNextPtr( Node * );
		Node *getNextPtr() const;
	private:
		int object;
		Node *nextPtr;

}; //Node class

Node::Node( const int& object )
{
  this->object = object;
  this->nextPtr = 0;
} //Node::Node

void Node::setValue( const int& object )
{
  this->object = object;
} //Node::setObject

int& Node::getValue()
{
  return object;
} //Node::getObject

void Node::setNextPtr( Node *nextPtr )
{
  this->nextPtr = nextPtr;
} //Node::setNextPtr

Node *Node::getNextPtr() const
{
  return nextPtr;
} //Node::getNextPtr

#endif // NODE_H

