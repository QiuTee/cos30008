#include<iostream>
#include<algorithm>
#include"Polynomial.h"
using namespace std;
Polynomial::Polynomial(){
	fDegree = 0; 
	for (int i = 0; i < MAX_DEGREE; i++) {
		fCoeffs[i] = 0.0; 
	}
}
Polynomial Polynomial::operator*(const Polynomial& aRHS) const {
	Polynomial poly;
	poly.fDegree = fDegree + aRHS.fDegree;
	for (size_t i = 0; i <= fDegree; i++) {
		for (int j = 0; j <= aRHS.fDegree; j++) {
		   	poly.fCoeffs[i + j] += fCoeffs[i] * aRHS.fCoeffs[j]; 
		}
	}
	return poly; 
}
bool Polynomial::operator==(const Polynomial& aRHS) const {
	if (fDegree != aRHS.fDegree) {
		return false; 
	}
	for (size_t i = 0; i <= fDegree; i++) {
		if (fCoeffs[i] != aRHS.fCoeffs[i]) {
			return false  ;
		}
	}
	return true; 
}
 std::istream& operator>>(std::istream& aIStream,Polynomial& aObject){
	 cin >> aObject.fDegree;
	 for (int  i = aObject.fDegree; i >= 0; i--) {
		 aIStream >> aObject.fCoeffs[i];
	 }
	 return aIStream;
 }
 std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject) {
	 
	 for (int i = aObject.fDegree; i >= 0; i--) {
		 if (aObject.fCoeffs[i] != 0) {
			 if (i != aObject.fDegree) {
				 if (aObject.fCoeffs[i] > 0) {
					aOStream << " + ";
				 }
				 else {
					 aOStream << "";
				 }
			 }
			 aOStream << aObject.fCoeffs[i];
			 aOStream << "x^" << i;
		
		 }
	 }
	 return aOStream;
 }