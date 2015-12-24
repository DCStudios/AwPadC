#ifndef _INCLUDE_GAPBUFFER_
#define _INCLUDE_GAPBUFFER_

#include <string>

class GapBuffer {
    
private:
    char* _buffer;
    unsigned _size;
    unsigned _gapStart;
    unsigned _gapEnd;
	
	void moveGapLeft( const unsigned distance );
	void moveGapRight( const unsigned distance );
	void moveGapTo( const unsigned index );
    
public:
    GapBuffer( const unsigned size=4096 );
	GapBuffer( const char* text, const unsigned size=4096 );
    ~GapBuffer();
	
    unsigned getUsedSize();
    unsigned getFreeSize();
    unsigned getTotalSize();
	
	char* getText();
	const char* getInfos();
	
	void remove( const unsigned count=1 );
	void removeAt( const unsigned index, const unsigned count=1 );
    
};

#endif
