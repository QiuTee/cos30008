#include<iostream>
#include<cmath> 
#include"Inductor.h"
using namespace std; 
bool Inductor::mustScale(double aValue) const {
	if (aValue >= 1.0) return false;
	return true; 
}
const double Inductor::getMultiplier() const {
	return 1000.0;
}
const std::string Inductor::getMajorUnit() const {
	return "H"; 
}
const std::string Inductor::getMinorUnits() const {
	return "Hmunp";
}
Inductor::Inductor(double aBaseValue) : ResistorBase( aBaseValue) {

}
double Inductor::getReactance(double aFrequency) const {
	double PI = 4.0 * atan(1.0);
	double result = 2 * PI * aFrequency * getBaseValue(); 
	return result;
}