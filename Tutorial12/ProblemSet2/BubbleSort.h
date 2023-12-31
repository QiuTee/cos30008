#pragma once
#include "SortableIntVector.h"
class BubbleSort : public SortableIntVector
{
public:
	BubbleSort(const int aArrayOfIntegers[], size_t aNumberOfElements);
	void sort(Comparable aOrderFunction) override;
};