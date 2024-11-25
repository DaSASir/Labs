#include <iostream>
#include "Plenty.h"

Plenty::Plenty():BoolVector(full_size,0) {

}
Plenty::Plenty(const char* array):BoolVector(array) {
	
}
Plenty::Plenty(const Plenty& other):BoolVector(other) {

}
Plenty::~Plenty() {
	~BoolVector();
}

void Plenty::Print() const{

}
void Plenty::Scan() {

}

bool Plenty::InPlenty(const char element) {

}

int Plenty::MaxElement() const {

}
int Plenty::MinElement() const {

}

int Plenty::Capacity() const {
	return WeightVector();
}

Plenty Plenty::operator = (const Plenty& other) {

}
bool Plenty::operator == (const Plenty& other) {

}
bool Plenty::operator != (const Plenty& other) {
	return !((*this) == other);
}
Plenty Plenty::operator | (const Plenty& other) const {

}
Plenty Plenty::operator |= (const Plenty& other) {

}
Plenty Plenty::operator & (const Plenty& other) const {

}
Plenty Plenty::operator &= (const Plenty& other) {

}
Plenty Plenty::operator / (const Plenty& other) const {

}
Plenty Plenty::operator /= (const Plenty& other) {

}
Plenty Plenty::operator ~ () {
	Plenty back(*this);
	back.Inversion();
	return back;
}
Plenty Plenty::operator + (const char value) const {

}
Plenty Plenty::operator += (const char value) {

}
Plenty Plenty::operator - (const char value) const {

}
Plenty Plenty::operator -= (const char value) {

}