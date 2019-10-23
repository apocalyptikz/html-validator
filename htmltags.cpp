/*
 * htmltags.cpp
 *
 *  Created on: Oct 8, 2016
 *      Author: steve
 */

#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <cstring>
#include <limits>
#include <regex>
#include <iostream>
#include "queue.h"
#include "htmltags.h"

namespace DS {



htmltags::htmltags() {
}

htmltags::htmltags(const std::string& filename) {
	tokenizeHTMLFile(filename);
}

bool htmltags::tokenizeHTMLFile(const std::string& filename) {
	std::string tagName;
	std::ifstream fin;
	bool commentBlock = false;
	tags.clear();

	fin.open( filename.c_str(), std::ifstream::in);
	if ( !fin.fail() ) {
		while ( fin ) {
			tagName.clear();
			while ( fin && fin.peek() != '<' )
				fin.ignore();

			if ( fin && fin.peek() == '<' ) {
				fin.ignore();
				//Possible HTML Tagname, tagnames end in >, SPACE, [, or newline (carriage return too)

				while ( fin && !commentBlock && !std::strchr("> [\n\r", fin.peek( )) ) {
					tagName += fin.get();

					if ( tagName.length() == 3 && tagName == "!--" ) {
						//Look for closing tag
						commentBlock = true;
					}
				}

				if (!commentBlock) {
					//Got tag name
					tags.enqueue(tagName);

					while ( fin && fin.peek() != '>' )
						fin.ignore();

					//Special case, ignore other languages
					if ( tagName == "script" && ignoreNonHTML(fin, "script") ) {
						tags.enqueue("/script");
					} else if ( tagName == "style" && ignoreNonHTML(fin, "style")  ) {
						tags.enqueue("/style");
					}

				} else {
					//Discard until end of comment
					std::string buffer;
					while ( fin && commentBlock ) {
						buffer += fin.get();

						if ( buffer.length() == 3 && buffer == "-->" ) {
							//Look for closing tag
							commentBlock = false;
						} else if ( buffer.length() > 0 && buffer.at(buffer.length()-1) != '-' ) {
							buffer.clear();
						}
					}
				}
			}
		}
	} else {
		throw std::runtime_error("Unable to open/read file!");
	}
	fin.close();
	return true;
}

bool htmltags::tokenizeHTMLFile( const char * filename ) {
	return tokenizeHTMLFile( std::string(filename) );
}

void htmltags::pop() {
	if ( !tags.empty() ) {
		tags.dequeue();
	} else {
		throw std::runtime_error("Tokens underflow!");
	}
}

bool ignoreNonHTML(std::ifstream& fin, const std::string& element) {
	bool done = false;
	std::string buffer;
	auto elementRegex = std::regex("/" + element + "[[:space:]]*");
	while ( fin && !done ) {
		buffer.clear();
		fin.ignore(std::numeric_limits<std::streamsize>::max(),'<');
		if ( fin && fin.peek() == '/' ) {
			while ( fin && fin.peek() != '<' && fin.peek() != '>' ) {
				buffer += fin.get();
			}
			if ( fin && fin.peek() == '>' && std::regex_match(buffer, elementRegex)) {
				done = true;
				fin.ignore();
				//tokens.push("/script");
				return true;
			}
		}
	}
	return false;
}

/*
<!--...--> 	Defines a comment
<!DOCTYPE>  	Defines the document type
<a> 	Defines a hyperlink
<abbr> 	Defines an abbreviation or an acronym
<acronym> 	Not supported in HTML5. Use <abbr> instead.
Defines an acronym
<address> 	Defines contact information for the author/owner of a document
<applet> 	Not supported in HTML5. Use <embed> or <object> instead.
Defines an embedded applet
<area> 	Defines an area inside an image-map
<article> 	Defines an article
<aside> 	Defines content aside from the page content
<audio> 	Defines sound content
<b> 	Defines bold text
<base> 	Specifies the base URL/target for all relative URLs in a document
<basefont> 	Not supported in HTML5. Use CSS instead.
Specifies a default color, size, and font for all text in a document
<bdi> 	Isolates a part of text that might be formatted in a different direction from other text outside it
<bdo> 	Overrides the current text direction
<big> 	Not supported in HTML5. Use CSS instead.
Defines big text
<blockquote> 	Defines a section that is quoted from another source
<body> 	Defines the document's body
<br> 	Defines a single line break
<button> 	Defines a clickable button
<canvas> 	Used to draw graphics, on the fly, via scripting (usually JavaScript)
<caption> 	Defines a table caption
<center> 	Not supported in HTML5. Use CSS instead.
Defines centered text
<cite> 	Defines the title of a work
<code> 	Defines a piece of computer code
<col> 	Specifies column properties for each column within a <colgroup> element
<colgroup> 	Specifies a group of one or more columns in a table for formatting
<datalist> 	Specifies a list of pre-defined options for input controls
<dd> 	Defines a description/value of a term in a description list
<del> 	Defines text that has been deleted from a document
<details> 	Defines additional details that the user can view or hide
<dfn> 	Represents the defining instance of a term
<dialog> 	Defines a dialog box or window
<dir> 	Not supported in HTML5. Use <ul> instead.
Defines a directory list
<div> 	Defines a section in a document
<dl> 	Defines a description list
<dt> 	Defines a term/name in a description list
<em> 	Defines emphasized text
<embed> 	Defines a container for an external (non-HTML) application
<fieldset> 	Groups related elements in a form
<figcaption> 	Defines a caption for a <figure> element
<figure> 	Specifies self-contained content
<font> 	Not supported in HTML5. Use CSS instead.
Defines font, color, and size for text
<footer> 	Defines a footer for a document or section
<form> 	Defines an HTML form for user input
<frame> 	Not supported in HTML5.
Defines a window (a frame) in a frameset
<frameset> 	Not supported in HTML5.
Defines a set of frames
<h1> to <h6> 	Defines HTML headings
<head> 	Defines information about the document
<header> 	Defines a header for a document or section
<hr> 	Defines a thematic change in the content
<html> 	Defines the root of an HTML document
<i> 	Defines a part of text in an alternate voice or mood
<iframe> 	Defines an inline frame
<img> 	Defines an image
<input> 	Defines an input control
<ins> 	Defines a text that has been inserted into a document
<kbd> 	Defines keyboard input
<keygen> 	Defines a key-pair generator field (for forms)
<label> 	Defines a label for an <input> element
<legend> 	Defines a caption for a <fieldset> element
<li> 	Defines a list item
<link> 	Defines the relationship between a document and an external resource (most used to link to style sheets)
<main> 	Specifies the main content of a document
<map> 	Defines a client-side image-map
<mark> 	Defines marked/highlighted text
<menu> 	Defines a list/menu of commands
<menuitem> 	Defines a command/menu item that the user can invoke from a popup menu
<meta> 	Defines metadata about an HTML document
<meter> 	Defines a scalar measurement within a known range (a gauge)
<nav> 	Defines navigation links
<noframes> 	Not supported in HTML5.
Defines an alternate content for users that do not support frames
<noscript> 	Defines an alternate content for users that do not support client-side scripts
<object> 	Defines an embedded object
<ol> 	Defines an ordered list
<optgroup> 	Defines a group of related options in a drop-down list
<option> 	Defines an option in a drop-down list
<output> 	Defines the result of a calculation
<p> 	Defines a paragraph
<param> 	Defines a parameter for an object
<pre> 	Defines preformatted text
<progress> 	Represents the progress of a task
<q> 	Defines a short quotation
<rp> 	Defines what to show in browsers that do not support ruby annotations
<rt> 	Defines an explanation/pronunciation of characters (for East Asian typography)
<ruby> 	Defines a ruby annotation (for East Asian typography)
<s> 	Defines text that is no longer correct
<samp> 	Defines sample output from a computer program
<script> 	Defines a client-side script
<section> 	Defines a section in a document
<select> 	Defines a drop-down list
<small> 	Defines smaller text
<source> 	Defines multiple media resources for media elements (<video> and <audio>)
<span> 	Defines a section in a document
<strike> 	Not supported in HTML5. Use <del> or <s> instead.
Defines strikethrough text
<strong> 	Defines important text
<style> 	Defines style information for a document
<sub> 	Defines subscripted text
<summary> 	Defines a visible heading for a <details> element
<sup> 	Defines superscripted text
<table> 	Defines a table
<tbody> 	Groups the body content in a table
<td> 	Defines a cell in a table
<textarea> 	Defines a multiline input control (text area)
<tfoot> 	Groups the footer content in a table
<th> 	Defines a header cell in a table
<thead> 	Groups the header content in a table
<time> 	Defines a date/time
<title> 	Defines a title for the document
<tr> 	Defines a row in a table
<track> 	Defines text tracks for media elements (<video> and <audio>)
<tt> 	Not supported in HTML5. Use CSS instead.
Defines teletype text
<u> 	Defines text that should be stylistically different from normal text
<ul> 	Defines an unordered list
<var> 	Defines a variable
<video> 	Defines a video or movie
<wbr> 	Defines a possible line-break
*/

} /* namespace DS */
