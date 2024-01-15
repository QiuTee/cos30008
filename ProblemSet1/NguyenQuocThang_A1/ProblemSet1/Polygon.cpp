#include<iostream>
#include "Polygon.h"
using namespace std;

Polygon::Polygon() {
	fNumberOfVertices = 0; 
	for (int i = 0; i < MAX_VERTICES; i++) {
		fVertices[i] = Vector2D(); 
	}
}
size_t Polygon::getNumberOfVertices() const {
	return fNumberOfVertices;
}
const Vector2D& Polygon::getVertex(size_t aIndex) const {
	return fVertices[aIndex];
}
void Polygon::readData(std::istream& aIStream) {
	fNumberOfVertices = 0;
	while (!aIStream.eof()) {
		Vector2D vec;
		aIStream >> vec;
		fVertices[fNumberOfVertices] = vec;
		fNumberOfVertices++;
	}
}
float Polygon::getPerimeter() const {
	float perimeter = 0;
	Vector2D segment;
	for (int i = 0; i < fNumberOfVertices; i++) {
		int nextdinh = (i + 1) % fNumberOfVertices;
		segment = fVertices[nextdinh] - fVertices[i];
		perimeter += segment.length();
	}
	return  perimeter;
}
Polygon Polygon::scale(float aScalar) const {
	Polygon Result = *this;
	for (int i = 0; i < fNumberOfVertices; i++) {
		Result.fVertices[i] = fVertices[i] * aScalar;
	}
	return Result;
}

