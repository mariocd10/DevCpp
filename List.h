#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

struct node {
	node *prev;
	node *next;
	long data;
};


class List{
	friend class LongInt;
	private:
        node *Head;
		node *Tail;

	public:
		List(){
		}
		void traverse(); //display list
		void createNode(long v); //create node as head and tail
		node *getLast(); //returns rightmost node
		node *getFirst(); //returns leftmost node
		node *nextRight(node *n); //returns node to the right of n
		node *nextLeft(node *n); //returns node to the left of n
		void insertRight(long v); //inserts node with value v after rightmost n
		void insertLeft(long v); //inserts node with value v before leftmost n
		bool isFirst(node *n); //returns bool if node n is first
		bool isLast(node *n); //returns bool if node n is last
};

#endif
