#include<iostream>
#include"BernsteinBasisPolynomial.h"
#include<cmath>
using namespace std;

BernsteinBasisPolynomial::BernsteinBasisPolynomial(unsigned int aV, unsigned int aN) : fFactor(aN, aV) {

}
double BernsteinBasisPolynomial::operator()(double aX) const {
	/*unsigned long long  combination = 1; 
	double numerator = 0.0f; 
	for (size_t i = 1; i <= fFactor.getK(); i++) {
		numerator = fFactor.getN() - (i - 1);
		combination *= (numerator / i);
	}*/
	double result = 0.0f; 
	result = fFactor() * pow(aX, fFactor.getK()) * pow((1 - aX), (fFactor.getN() - fFactor.getK()));
	return result;
}
