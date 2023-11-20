#include<iostream>
#include"ShakerSortableIntVector.h"
using namespace std; 
ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : SortableIntVector(aArrayOfIntegers , aNumberOfElements){

}
void ShakerSortableIntVector::sort(Comparable aOrderFunction ) {
	for (size_t i = 0; i < size() / 2; i++) {
		for (size_t j = 0; j < size() - i - 1; j++) {
			if (aOrderFunction(get(j), get(j + 1))) {
				swap(j, j + 1); 
			}
		}
		for (size_t j = size() - 1 - i; j > i; j--) {
			if (aOrderFunction(get(j - 1), get(j))) {
				swap(j - 1 , j );
			}
		}
	}
}