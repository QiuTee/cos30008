#include<iostream>
#include"Polygon.h" ;

using namespace std;

float Polygon::getSignedArea() const {
	float signArea = 0.0f;
	float result = 0.0f;
	for (int i = 0; i < fNumberOfVertices; i++) {
		int nexttop = (i + 1) % fNumberOfVertices; 
		signArea += ((fVertices[i].getX() * fVertices[nexttop].getY()) - (fVertices[i].getY() * fVertices[nexttop].getX())); 
		result = signArea / 2 ;
	}
	return result;
}