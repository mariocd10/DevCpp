#include <iostream>
#include "List.h"

using namespace std;

node *Head = NULL;
node *Tail = NULL;

//traverse through list
void List::traverse(){
	node *tmp = Head;
	
	while(tmp != NULL){
		cout<<tmp->data;
		tmp = tmp->next;
	}
	return;

}

//create first node
void List::createNode(long v){
	node *n = new node;
	n->data = v;
	n->next = NULL;
	n->prev = NULL;
	Head = n;
	Tail = n;
	return;
}

//returns rightmost node (tail)
node *List::getLast(){

	return Tail;
}

//returns the leftmost node (head)
node *List::getFirst(){
	/*
	if(Head==NULL){
		cout << "Empty List";
		return;
	}
	*/
	return Head;
}

//Returns next node to the right of the node N
node *List::nextRight(node *n){
	node *tmp = Head;
	
	/*
	if(tmp == NULL){
		cout << "empty List";
		return;
	}
	*/

	while(tmp->next != NULL){
		//if next node exists check if curr node is n
		if(n->data == tmp->data){
			return tmp->next;
		}
		tmp = tmp->next;
	}
	
	if(tmp->data == n->data){
		return tmp;
	}
	else{
		cout<<"node not in list";
		//return;
	}
}
//returns node to the left of n
node *List::nextLeft(node *n){
	node *tmp = Tail;
	/*
	if(tmp == NULL){
		cout<<"Empty List";
		return;
	}
	*/
	while(tmp->prev != NULL){
		//if prev node exists check if curr node is n
		if(n->data == tmp->data){
			return tmp->prev;
		}
		tmp = tmp->prev;
	}
	
	if(tmp->data == n->data){
		return tmp;
	}
	else{
		cout<<"node not in list";
		//return;
	}
}

//inserts node with value v after rightmost n
void List::insertRight(long v){
	node *last = getLast(); //tail node
	//new node with value v as data
	node *tmp = new node;
	last->next = tmp;
	tmp->data = v;
	tmp->next = NULL;
	tmp->prev = last;
	Tail = tmp;
}
//inserts node with value v before leftmost n
void List::insertLeft(long v){
    node *first = getFirst(); //head node
	//new node with value v as data
	node *tmp = new node;
	first->prev = tmp;
	tmp->data = v;
	tmp->prev = NULL;
	tmp->next = first;
	Head = tmp;
		}
//returns bool if node n is first
bool List::isFirst(node *n){
	if(n == Head){
		return true;
	}
	return false;
}
		
//returns bool if node n is last
bool List::isLast(node *n){
	if(n==Tail){
		return true;
	}
	return false;
}
