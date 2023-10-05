#include<iostream>

#include"Capacitor.h"

using namespace std;
bool Capacitor::mustScale(double aValue) const {
	if (aValue >= 1.0) return false; 
	return true;
}
const double Capacitor::getMultiplier() const {
	return 1000.0; 
}
const std::string Capacitor::getMajorUnit() const {
	return "F"; 
}
const std::string Capacitor::getMinorUnits() const  {
	return "Fmunp";
}
Capacitor::Capacitor(double aBaseValue ) : ResistorBase(aBaseValue) {

}
double Capacitor::getReactance(double aFrequency) const {
	double PI = 4.0 * atan(1.0);
	double result = 1.0 / (2 * PI * aFrequency * getBaseValue());
	return result;
}
