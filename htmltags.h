//  htmltags.h
//
// Date: October 2019
// Author: S.Miller
//
// Description:
// This class is offered to make one part of the project a little easier.  This class uses a data structure that we will learn later on in the semester.
// Creates a queue of tags after reading each tag from a file
//
//
//	bool tokenizeHTMLFile( std::string& filename )
//     Precondition: Filename is a local file that EXISTS and is readable, file should be a HTML
//     Postcondition: File is read into the objects queue for later processing
//
//	bool tokenizeHTMLFile( char * filename  )
//		Convenience function if you wanted to pass a hardcoded filename string (cstr) to tokenize, otherwise same as above
//     Precondition: Filename is a local file that EXISTS and is readable, file should be a HTML
//     Postcondition: File is read into the objects queue for later processing
//
//	tag front();
//     Precondition: Queue is not empty
//     Postcondition: Returns the tag at the front of the queue
//
//	bool empty() const;
//     Precondition: N/A
//     Postcondition: True if the HTML token queue is NOT empty
//
//Non-members:
//The following function is used internally and not intended for students to use directly
//bool ignoreNonHTML(std::ifstream&, const std::string&)
//		Precondition: fstream is not EOF
//		Postcondition: file is seeked to the end of non HTML


#ifndef HTMLTAGS_H_
#define HTMLTAGS_H_

#include <ostream>
#include <string>
#include "tag.h"
#include "queue.h"

namespace DS {

class htmltags {
public:
	htmltags();
	htmltags( const std::string& );
	~htmltags() { }
	bool tokenizeHTMLFile( const std::string& );
	bool tokenizeHTMLFile( const char * );
	void pop();
	const tag& front() const { return tags.front(); }
	bool empty() const { return tags.empty(); }

private:
	queue<tag> tags;
};

bool ignoreNonHTML(std::ifstream&, const std::string&);

} /* namespace DS */

#endif /* HTMLTAGS_H_ */

