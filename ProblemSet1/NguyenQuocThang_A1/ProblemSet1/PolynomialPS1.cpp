#include<iostream>
#include<cmath>
#include"Polynomial.h"
using namespace std;
double Polynomial::operator()(double aX) const {

	double result = 0.0;

	for (int i = 0; i <= fDegree; i++) 
	{
		result += fCoeffs[i] * pow(aX, i);
	}
	return result;
}
Polynomial Polynomial::getDerivative() const 
{
	Polynomial derivative;  
	
	derivative.fDegree = fDegree - 1;
	for (int i = 0; i <= fDegree; i++)
	{
		if (i == 0) {
			  derivative.fCoeffs[i] = 0 ;
		}else 
		{ 
			derivative.fCoeffs[i - 1] = fCoeffs[i] * i ;
		}
	}

	return derivative;
}
Polynomial Polynomial::getIndefiniteIntegral() const {
	Polynomial indef; 
	indef.fDegree = fDegree + 1; 
	for (int i = 0; i <= indef.fDegree; i++) {
		indef.fCoeffs[i + 1] = (fCoeffs[i] / (i + 1));
	}
	return indef;
}
double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const {
	double lowresult = 0.0; 
	double highresult = 0.0; 
	//define.fDegree = fDegree + 1;
	Polynomial define = getIndefiniteIntegral();
	for (int i = 0; i <= define.fDegree; i++) {
		//define.fCoeffs[i + 1] = (fCoeffs[i] / (i + 1));
		lowresult += define.fCoeffs[i + 1] * pow(aXLow, (i + 1)); 
		highresult += define.fCoeffs[i + 1] * pow(aXHigh, (i + 1));
	}
	double result = highresult - lowresult;
	return result; 
}