//S. Miller
//
// Constructors
//	tag();
//	tag(const std::string& name);
//	tag(const char* name);
//
//const std::string& getTagName() const {	return tagName;	}
//	Precondition: none
//  Postcondition: Return the name of the tag, such as body or title
//
//unsigned short getFlags() const { return flags; }
//	Precondition: none
//  Postcondition: Return the numerical flags of the tag
//
//bool isInvalidTag() const { return !isValidTag(); }
//	Precondition: none
//  Postcondition: Return true if the tag is invalid, such as center
//
//bool isValidTag() const { return (flags & VALID) == VALID; }
//	Precondition: none
//  Postcondition: Return true if the tag is valid
//
//bool isOpeningTag() const { return (flags & OPENING_TAG) == OPENING_TAG; }
//	Precondition: none
//  Postcondition: Return true if the tag is and opening tag
//
//bool isSelfClosingTag() const { return (flags & SELF_CLOSING) == SELF_CLOSING; }
//	Precondition: none
//  Postcondition: Return true if the tag is self closing
//
//bool isClosingTag() const { return (flags & CLOSING_TAG) == CLOSING_TAG; }
//	Precondition: none
//  Postcondition: Return true if the tag is a closing tag
//
// Constants:
// INVALID = 0; //Indicates a TAG that does not exist in HTML5
// VALID = 1
// OPENING_TAG = 2; //Indicates a VALID HTML5 opening tag
// SELF_CLOSING = 4; //Indicates a VALID HTML5 opening tag that does NOT get closed (ie: auto closing)
// CLOSING_TAG = 8; //Indicates a VALID HTML5 closing tag

#ifndef TAG_H_
#define TAG_H_

#include <string>
#include <algorithm>
#include <ostream>
#include <map>

namespace DS {

class tag {
public:
	enum Flags { INVALID = 0, VALID = 1, OPENING_TAG = 2, SELF_CLOSING = 4, CLOSING_TAG = 8 };
	tag();
	tag(const std::string& name);
	tag(const char* name);

	const std::string& getTagName() const {	return tagName;	}

	unsigned short getFlags() const { return flags; }
	bool isInvalidTag() const { return !isValidTag(); }
	bool isValidTag() const { return (flags & VALID) == VALID; }
	bool isOpeningTag() const { return (flags & OPENING_TAG) == OPENING_TAG; }
	bool isSelfClosingTag() const { return (flags & SELF_CLOSING) == SELF_CLOSING; }
	bool isClosingTag() const { return (flags & CLOSING_TAG) == CLOSING_TAG; }

private:
	std::string tagName;
	static const std::map<std::string, unsigned short> htmlmap;
	unsigned short flags;

	void processTag();
};

std::ostream& operator<<(std::ostream&, const tag&);

} /* namespace DS */

#endif /* TAG_H_ */
