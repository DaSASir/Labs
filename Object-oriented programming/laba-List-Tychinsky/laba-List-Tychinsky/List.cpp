#include <iostream>
#include "List.h"

List::List() {
	head = new Node; tail = new Node;
	head->next = tail;
	head->last = nullptr;
	tail->next = nullptr;
	tail->last = head;
}
List::List(const Array& array) {

}
List::List(const List& other) {

}

List::~List() {
	Clear();
	delete head, tail;
}

int List::Size() {

}

void List::Swap(List& other) {

}

void List::Print() {

}
void List::Scan() {

}

Node* List::FindKey(int key) {

}

void List::AddToTail(const char data) {

}
void List::AddToHead(const char data) {

}
void List::AddAfterKey(const char data, Node* key) {

}
void List::AddToIterator(const char data, Node* key) {

}

void List::DelHead() {

}
void List::DelTail() {

}
void List::DelKey(Node* p) {

}
void List::DelIterator(Node* p) {

}

bool List::IsEmpty() {

}

void List::Clear() {
	
}