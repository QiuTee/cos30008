#pragma once
#include <fstream>
using byte = unsigned char;
class ofstream12
{
private:
	std::ofstream fOStream; 
	byte* fBuffer; // output buffer
	size_t fBufferSize; // output buffer size
	size_t fByteIndex; // current byte index
	int fBitIndex; // current bit index (can be negative)
	void init(); // initialize data members
	void completeWriteBit(); // complete write
	void writeBit0(); // write 0
	void writeBit1(); // write 1
public:
	// using C++11's nullptr
	ofstream12(const char* aFileName = nullptr, size_t aBufferSize = 128);
	~ofstream12();
	void open(const char* aFileName); // open file 
	void close();
	bool good() const; // Check the status of the data stream.
	bool isOpen() const; // Check if the file can be opened
	void flush();
	ofstream12& operator<<(size_t aValue);
};