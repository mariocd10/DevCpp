#include <iostream>
#include "List.h"

using namespace std;

node *Head = NULL;
node *Tail = NULL;

//traverse through list
void List::traverse(){
	node *tmp = Head;
	
	while(tmp != NULL){
		cout<<tmp->data<<"-";
		tmp = tmp->next;
	}
	return;

}

//remove
void List::remove(node *n){
	if(n == Head){
		Head = n->next;
	}	
	return;
}
//create first node
void List::createNode(int v){
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
	node *tmp = Tail;
	if(tmp==NULL){
		cout<<"Tail pointing to NULL";
		return NULL;
	}
	return Tail;
}

//returns the leftmost node (head)
node *List::getFirst(){
	node *tmp = Head;
	if(tmp==NULL){
		cout << "Head pointing to NULL";
		return NULL;
	}
	return tmp;
}

//Returns next node to the right of the node N
node *List::nextRight(node *n){
	if(n == NULL){
		cout << "node is null";
		return NULL;
	}
	if(n->next != NULL){
		//if next node exists
  		return n->next;
	}
	else{
		return NULL;
	}
}
//returns node to the left of n
node *List::nextLeft(node *n){
	if(n == NULL){
		cout << "node is null";
		return NULL;
	}
	if(n->prev != NULL){
		//if next node exists
  		return n->prev;
	}
	else{
		return NULL;
	}
}

//inserts node with value v after rightmost n
void List::insertRight(int v){
	node *last = Tail; //tail node
	//new node with value v as data
	node *tmp = new node;
	last->next = tmp;
	tmp->data = v;
	tmp->next = NULL;
	tmp->prev = last;
	Tail = tmp;
}
//inserts node with value v before leftmost n
void List::insertLeft(int v){
	node *first = Head;
	//create new node with v as data
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
