#include<iostream>
#include"Combination.h" 
using namespace std; 
using ll = long long ;
Combination::Combination(size_t aN , size_t aK )  {
	this->fN = aN;
	this->fK = aK; 
}
size_t Combination::getN() const {
	return this->fN ;
}
size_t Combination::getK() const {
	return this->fK;
}
unsigned long long Combination::operator()() const {
	unsigned long long result = 1;
	float numerator = 0.0f; 
	if (fK > fN) {
		return 0 ; 
	}
	 
	for (size_t i = 1; i <= fK; i++) {
		numerator =  fN - (i - 1) ;
		result *= (numerator / i);
		}
	return result;
}