#include <sstream>
#include <string.h>
#include "../inc/GapBuffer.h"

// PRIVATE

void GapBuffer::moveGapLeft( const unsigned distance ) {
	if( distance <= _gapStart ) {
		memmove( &_buffer[_gapEnd-distance], &_buffer[_gapStart-distance], distance );
		_gapStart -= distance;
		_gapEnd -= distance;
	}
	// TODO: Throw out of range exeption
}

void GapBuffer::moveGapRight( const unsigned distance ) {
	if( distance <= getTotalSize()-_gapEnd ) {
		memmove( &_buffer[_gapStart], &_buffer[_gapEnd], distance );
		_gapStart += distance;
		_gapEnd += distance;
	}
	// TODO: Throw out of range exception
}

void GapBuffer::moveGapTo( const unsigned index ) {
	if( index >= 0 && index < getUsedSize() ) {
		if( index == _gapStart ) return;
		if( index < _gapStart ) moveGapLeft( _gapStart-index );
		else moveGapRight( index-_gapStart );
	}
	// TODO: Throw out of range exception
}

// PUBLIC

GapBuffer::GapBuffer( const unsigned size ) {
    _size = size;
    _buffer = new char [ size ];
    _gapStart = 0;
    _gapEnd = size;
}

GapBuffer::GapBuffer( const char* text, const unsigned size ) {
	_size = size;
	_buffer = new char [ size ];
	strcpy( _buffer, text );
	_gapStart = strlen( text );
	_gapEnd = size; 
}

GapBuffer::~GapBuffer() {
    delete _buffer;
}

unsigned GapBuffer::getTotalSize() {
    return _size;
}

unsigned GapBuffer::getFreeSize() {
    return _gapEnd - _gapStart;
}

unsigned GapBuffer::getUsedSize() {
    return _gapStart + ( _size - _gapEnd );
}

// Concatenate what's before the _gapStart and after _gapEnd,
// adding a \0 to make sure it's a valid c_str.
// NOTE: the returned pointer should be deleted by the caller.
char* GapBuffer::getText() {
	unsigned size = getUsedSize();
	char* text = new char[ size+1 ];
	memcpy( &text[0], &_buffer[0], _gapStart );
	memcpy( &text[_gapStart], &_buffer[_gapEnd], size-_gapStart );
	text[size] = '\0';
	return text;
}

const char* GapBuffer::getInfos() {
	std::stringstream stream;
	char* text = getText();
	
	stream << "Size : " << getTotalSize() <<
		"\nUsed : " << getUsedSize() <<
		"\nFree : " << getFreeSize() <<
		"\nText : '" << text << "'";
		
	delete text;
	return stream.str().c_str(); 
}

void GapBuffer::remove( const unsigned count ) {
	if( count <= getUsedSize()-_gapEnd ) _gapEnd += count;
	// TODO: Throw nothing to remove exception
}

void GapBuffer::removeAt( const unsigned index, const unsigned count ) {
	if( count > 0 && count <= getUsedSize() ) {
		moveGapTo( index );
		remove( count );
	}
	// TODO: Throw nothing to remove exception
}