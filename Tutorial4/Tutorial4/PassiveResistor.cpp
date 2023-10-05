#include <iostream>
#include <string>
#include"PassiveResistor.h"
bool PassiveResistor::mustScale(double aValue) const {
	if (aValue < 1000.0) {
		return false;
	}
	return true;
}
const double PassiveResistor::getMultiplier() const {
	double result; 
	return result = 1.0 / 1000.0; 
}
const std::string PassiveResistor::getMajorUnit() const  {
	return "Ohm";
}
const std::string PassiveResistor::getMinorUnits() const {
	return "OkM"; 
}
PassiveResistor::PassiveResistor(double aBaseValue ) : ResistorBase(aBaseValue) {

}
double PassiveResistor::getReactance(double aFrequency ) const {
	return getBaseValue(); 
}

