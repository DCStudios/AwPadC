#include <iostream>
#include "../inc/GapBuffer.h"

const unsigned MAJOR = 0;
const unsigned MINOR = 0;
const char* const CODE_NAME = "New-Born";

// Wrapper to automatically dispose of the returned buffer info
void showInfo( GapBuffer* buff ) {
	const char* info = buff->getInfos();
	std::cout << info << std::endl << std::endl;
	delete info;
}

int main( int argc, char* argv[] ) {
    
    std::cout << std::endl << "GapBuffer v" << MAJOR << "." << MINOR << " ( " << CODE_NAME << " )" << std::endl << std::endl;
    
    std::cout << "Creating buffer... ";
	char text[] = "This is a test.";
    GapBuffer* buffer = new GapBuffer( text );
    std::cout << "DONE" << std::endl << std::endl;
    showInfo( buffer );
    
	std::cout << "Deleting a character at the beginning..." << std::endl;
	buffer->removeAt( 0 );
	showInfo( buffer );
	
	std::cout << "Deleting 2 characters from middle..." << std::endl;
	buffer->removeAt( 4,2 );
	showInfo( buffer );
	
	std::cout << "Deleting a character fomr current position..." << std::endl;
	buffer->remove();
	showInfo( buffer );
	
	std::cout << "Deleting a character from end..." << std::endl;
	buffer->removeAt( buffer->getUsedSize()-1 );
	showInfo( buffer );
	
	std::cout << "Deleting 2 character from middle..." << std::endl;
	buffer->removeAt( 4,2 );
	showInfo( buffer );
	
    std::cout << std::endl << "Destroying buffer... ";
    delete buffer;
    std::cout << "DONE" << std::endl;
	
    return 0;
    
}