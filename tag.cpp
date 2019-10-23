//S. Miller

#include "tag.h"

namespace DS {

//Initialize the static map
const std::map<std::string, unsigned short> tag::htmlmap = {
	{"a", VALID},
	{"abbr", VALID},
	{"address", VALID},
	{"area", VALID},
	{"article", VALID},
	{"aside", VALID},
	{"audio", VALID},
	{"b", VALID},
	{"base", VALID},
	{"bdi", VALID},
	{"bdo", VALID},
	{"blockquote", VALID},
	{"body", VALID},
	{"br", VALID | SELF_CLOSING},
	{"button", VALID},
	{"canvas", VALID},
	{"caption", VALID},
	{"cite", VALID},
	{"code", VALID},
	{"col", VALID},
	{"colgroup", VALID},
	{"datalist", VALID},
	{"dd", VALID},
	{"del", VALID},
	{"details", VALID},
	{"dfn", VALID},
	{"dialog", VALID},
	{"div", VALID},
	{"dl", VALID},
	{"!doctype", VALID | SELF_CLOSING},
	{"dt", VALID},
	{"em", VALID},
	{"embed", VALID},
	{"fieldset", VALID},
	{"figcaption", VALID},
	{"figure", VALID},
	{"footer", VALID},
	{"form", VALID},
	{"h1", VALID},
	{"h2", VALID},
	{"h3", VALID},
	{"h4", VALID},
	{"h5", VALID},
	{"h6", VALID},
	{"head", VALID},
	{"header", VALID},
	{"hr", VALID | SELF_CLOSING},
	{"html", VALID},
	{"i", VALID},
	{"iframe", VALID},
	{"img", VALID | SELF_CLOSING},
	{"input", VALID | SELF_CLOSING},
	{"ins", VALID},
	{"kbd", VALID},
	{"keygen", VALID | SELF_CLOSING},
	{"label", VALID},
	{"legend", VALID},
	{"li", VALID},
	{"link", VALID | SELF_CLOSING},
	{"main", VALID},
	{"map", VALID},
	{"mark", VALID},
	{"menu", VALID},
	{"menuitem", VALID},
	{"meta", VALID | SELF_CLOSING},
	{"meter", VALID},
	{"nav", VALID},
	{"noscript", VALID},
	{"object", VALID},
	{"ol", VALID},
	{"optgroup", VALID},
	{"option", VALID},
	{"output", VALID},
	{"p", VALID},
	{"param", VALID | SELF_CLOSING},
	{"pre", VALID},
	{"progress", VALID},
	{"q", VALID},
	{"rp", VALID},
	{"rt", VALID},
	{"ruby", VALID},
	{"s", VALID},
	{"samp", VALID},
	{"script", VALID},
	{"section", VALID},
	{"select", VALID},
	{"small", VALID},
	{"source", VALID | SELF_CLOSING},
	{"span", VALID},
	{"strong", VALID},
	{"style", VALID},
	{"sub", VALID},
	{"summary", VALID},
	{"sup", VALID},
	{"table", VALID},
	{"tbody", VALID},
	{"td", VALID},
	{"textarea", VALID},
	{"tfoot", VALID},
	{"th", VALID},
	{"thead", VALID},
	{"time", VALID},
	{"title", VALID},
	{"tr", VALID},
	{"track", VALID | SELF_CLOSING},
	{"u", VALID},
	{"ul", VALID},
	{"var", VALID},
	{"video", VALID},
	{"wbr", VALID | SELF_CLOSING},
};

tag::tag() : tag("") { }

tag::tag(const char* name) : tag(std::string(name)) {
}

tag::tag(const std::string& name) : tagName(name) {
	flags = INVALID;
	processTag();
}

void tag::processTag() {

	if ( !tagName.empty() ) {
		//Convert tag to lower case
		std::transform(tagName.begin(), tagName.end(), tagName.begin(), ::tolower);

		if ( tagName.at(0) == '/' ) {
			flags |= CLOSING_TAG;
			tagName.erase(0,1);
		} else
			flags |= OPENING_TAG;

		auto it = htmlmap.find(tagName);
		if ( it != htmlmap.end() )
			flags |= htmlmap.at(tagName);
	}
}

std::ostream& operator<<(std::ostream& out, const tag& element) {
	out << element.getTagName();
	return out;
}

} /* namespace DS */
