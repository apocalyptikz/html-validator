/*
Programmer Name: Jonathan Christian
Date Submitted:
File Purpose: htmlcheck driver
Date Updated: n/a
Purpose for Update: n/a
Global Variable List: n/a


*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "htmltags.h"
#include "queue.h"
#include "stack.h"

//Outputs queue
void outQueue(DS::queue<DS::tag>&);
void outQueue(DS::queue<DS::tag>& qIn)
{
	std::cout << "[";
	while (!qIn.empty())
	{
		std::cout << qIn.front().getTagName() << " ";
		qIn.dequeue();
	}
	std::cout << "]";
}

//Checks if queue of tags contains a tag
bool queueContains(DS::queue<DS::tag>&, DS::tag);
bool queueContains(DS::queue<DS::tag>& qIn, DS::tag tagIn)
{
	DS::queue<DS::tag> tempQueue;
	while (!qIn.empty())
	{
		if (qIn.front().getTagName() == tagIn.getTagName())
			return true;
		tempQueue.enqueue(qIn.front());
		qIn.dequeue();
	}
	qIn = tempQueue;
	tempQueue.clear();
	return false;
}

//Inserts tag into queue alphabetically
void insertInQueue(DS::queue<DS::tag>&, DS::tag);
void insertInQueue(DS::queue<DS::tag>& qIn, DS::tag tagIn)
{
	//Just insert if it's empty
	if (qIn.empty())
	{
		qIn.enqueue(tagIn);
		return;
	}
	
	DS::queue<DS::tag> tempQueue;
	
	//Compare strings of tags, adding each tag into tempqueue
	while (!qIn.empty() && qIn.front().getTagName() < tagIn.getTagName())
	{
		tempQueue.enqueue(qIn.front());
		qIn.dequeue();
	}
	//Our "midpoint" - temp contains everything before where the tag belongs, leaving everything else in the qIn
	if (!queueContains(qIn, tagIn)) //unique tags only
		tempQueue.enqueue(tagIn);
	while (!qIn.empty()) //add the rest of qIn behind the tag
	{
		tempQueue.enqueue(qIn.front());
		qIn.dequeue();
	}
	//Update qIn
	qIn = tempQueue;
}

int main(int argc, char *argv[])
{
	DS::htmltags tags = DS::htmltags(argv[1]);

	DS::stack<DS::tag> tagStack; //for validation
	DS::queue<DS::tag> tagQueue; //for cout entire list of tags, alphabetical order
	DS::queue<DS::tag> invalidQueue; //Invalid tags

	while (!tags.empty())
	{
		DS::tag currTag = tags.front();
		if (currTag.isValidTag())
		{
			if (!currTag.isSelfClosingTag())
			{
				if (currTag.isOpeningTag())
				{
					std::cout << "Tag " << currTag.getTagName() << " pushed." << std::endl;
					//Empty queue into another queue until the correct spot for currTag
					//enqueue currTag
					//then enqueue rest of tagqueue
					//put tempqueue into tagqueue

					//Add tag to queue by alphebetical order
					insertInQueue(tagQueue, currTag);

					tags.pop();
					tagStack.push(currTag);
				}
				if (currTag.isClosingTag())
				{
					if (tagStack.top().getTagName() == currTag.getTagName() && tagStack.top().isOpeningTag())
					{
						//currTag matches tags.front()
						std::cout << "Tag /" << currTag.getTagName() << " matches top of stack." << std::endl;
						tagStack.pop();
						tags.pop();
					}
					else
					{
						//Tag is XXX but top of stack is YYY
						std::cout << "Tag mismatch: tag is " << currTag.getTagName() << " but top of stack is "
							<< tags.front().getTagName() << std::endl;
						tags.pop();
						
					}
				}
			}
			else
			{
				std::cout << "Tag " << currTag.getTagName() << " self closing." << std::endl;
				tags.pop();
				insertInQueue(tagQueue, currTag);
			}
			
		}
		else
		{
			std::cout << "Tag " << currTag.getTagName() << " is not a valid HTML5 tag.";
			insertInQueue(invalidQueue, currTag);
			tags.pop();
		}
	}
	std::cout << "Processing complete. ";
	//No mismached tags
	if (tagStack.empty())
	{
		//invalidQueue has something in it
		if (!invalidQueue.empty())
		{
			std::cout << "Invalid HTML5. Tags matched, however, ";
			outQueue(invalidQueue);
			std::cout << " are not a valid HTML5 tag(s).";
		}
		else //No invalid tags
		{
			std::cout << "Document is valid." << std::endl
				<< "Unique tags seen in sorted order: ";
			outQueue(tagQueue);
			//Empty, opening tags matched closing tags
		}
		
	}
	else
	{
		std::cout << "Invalid HTML5. Unmatched tags remain on stack: ";
		while (!tagStack.empty())
		{
			std::cout << tagStack.top() << " ";
			tagStack.pop();
		}
	}


	return 0;
}
