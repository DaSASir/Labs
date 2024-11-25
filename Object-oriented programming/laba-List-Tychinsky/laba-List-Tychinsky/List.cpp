#include <iostream>
#include "List.h"

using std::cout;
using std::cin;
using std::endl;

//Node
Node:: Node(char k = 0, Node* lst = nullptr, Node* nxt = nullptr)
	: m_data(k), last(lst), next(nxt) {
}
char Node:: Data() {
	return m_data;
}

//List
List::List() {
	head = new Node;
	tail = new Node(0, head, nullptr);
	head->next = tail;
}
List::List(const Array& array) {
	Clear();
	List();

	int lenth_of_array = 1;
	for (int i = 0; i < lenth_of_array; i++)
		AddToTail(0);
}
List::List(const List& other) {
	head = new  Node;
	tail = new  Node(0, head, nullptr);

	head->next = tail;

	Node* q = other.head->next;

	while (q != other.tail) {
		AddToTail(q->m_data);
		q = q->next;
	}
}

List::~List() {
	Clear();
	delete head, tail;
}

int List::Size() {
	Node* adapter = head->next;

	int weight = 0;
	while (adapter != tail) {
		weight++;
		adapter = adapter->next;
	}
	return weight;
}

void List::Swap(List& other) {
	using std::swap;
	swap(head,other.head);
	swap(tail, other.tail);

	int size;
	Size() > other.Size() ? size = Size() : size = other.Size();

	Node* adapter = head->next;
	Node* adapter2 = other.head->next;

	for (int i = 0; i < size; i++) {
		if (adapter == tail || adapter2 == other.tail) break;

		swap(adapter->m_data, adapter2->m_data);
	}
}

void List::Print() {
	if ((head->next) == tail) 
		cout << "list is empty" << endl;
	else {
		Node* q = head->next;

		while (q != tail) {
			cout << q->m_data << ' ';
			q = q->next;
		}
	}
}
void List::Scan() {
	int n;
	cout << "Введите количество элементов в списке - ";
	cin >> n;

	cout << "введите " << n << " элементов списка:" << endl;
	this->Clear();

	int element;
	for (int i = 0; i < n; i++) {
		cin >> element;
		AddToTail(element);
	}
}

Node* List::FindKey(const char key) {
	if (head->m_data == key)
		return head;

	else {
		Node* adapter = head;
		while (adapter != NULL && adapter->m_data != key)
			adapter = adapter->next;

		if (adapter == NULL)
			return NULL;

		else return adapter;
	}
}

void List::AddToTail(const char data) {
	AddAfterKey(data, tail->last);
}
void List::AddToHead(const char data) {
	AddAfterKey(data, head);
}
void List::AddAfterKey(const char data, Node* key) {
	Node* adapter = new Node;
	adapter->m_data = data;
	adapter->next = key->next;
	adapter->last = key;
	key->next = adapter;
	adapter->next->last = adapter;
}
void List::AddToIterator(const char data, Node* key) {

}

void List::DelHead() {
	if (head->next == tail)
		puts("список пустой");
	else DelKey(head->next);
}
void List::DelTail() {
	if (head->next == tail)
		puts("список пустой");
	else DelKey(tail->last);
}
void List::DelKey(Node* p) {
	p->last->next = p->next;
	p->next->last = p->last;
	delete p;
}
void List::DelIterator(Node* p) {

}

char List::MaxElement() {
	List copy(*this);
	copy.Sorting();

	Node* element = copy.tail->last;
	return element->m_data;
}
char List::MinElement() {
	List copy(*this);
	copy.Sorting();

	Node* element = copy.head->next;
	return element->m_data;
}

bool List::IsEmpty() {
	return head->next == tail;
}

void List::Clear() {
	while (!IsEmpty())
		DelHead();
}

void List::Sorting() {
	for (int i = 0; i < Size() - 1; i++) {
		bool checking = 0;

		Node* adapter = head->next;
		Node* adapter2 = adapter->next;

		for (int j = 0; j < Size() - i - 1; j++)
			if (adapter > adapter2) {
				checking = 1; 
				std::swap(adapter, adapter2);
			}
		if (!checking) break;
	}
}

List List:: operator = (const List& other) {
	if (this == &other) return *this;

	Clear();
	Node* adapter = other.head;
	while (adapter != tail || adapter == tail) {
		this->AddToTail(adapter->m_data);
		adapter = adapter->next;
	}
	return *this;
}
Node* List::operator [] (const int index) {
	Node* adapter = head->next;

	for (int i = 0; i < index; i++) 
		adapter = adapter->next;

	return adapter;
}
bool List:: operator == ( List& other) {
	if (Size() != other.Size())
		return false;

	Node* adapter = head->next;
	Node* adapter2 = other.head->next;

	for (int i = 0; i < Size(); i++) {
		if (adapter->m_data != adapter2->m_data) {
			return false;
			break;
		}
		adapter = adapter->next;
		adapter2 = adapter2->next;
	}
	return true;
}
bool List:: operator != ( List& other) {
	return !(*this == other);
}
List List::operator + (const List& other) {
	List back(*this);
	return back += other;
}
List List::operator += (const List& other) {
	Node* adapter = other.head->next;
	for (adapter; adapter != other.tail; adapter = adapter->next) 
		this->AddToTail(adapter->m_data);
	
	return *this;
}