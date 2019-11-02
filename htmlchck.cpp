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


int main(int argc, char *argv[])
{
	DS::htmltags tags = DS::htmltags(argv[1]);

	DS::stack<DS::tag> tagStack; //for validation
	DS::queue<DS::tag> tagQueue; //for cout entire list of tags, alphabetical order

	while (!tags.empty())
	{
		if (tags.front().isValidTag())
		{
			if (tags.front().isOpeningTag())
			{
				std::cout << "Tag " << tags.front().getTagName() << " pushed." << std::endl;
				//Add tag to queue by alphebetical order
			}
			if (tags.front().isClosingTag())
			{
				DS::tag currTag = tags.front();
				tags.pop();
				if (tags.front().getTagName() == currTag.getTagName() && tags.front().isOpeningTag())
				{
					//currTag matches tags.front()
					std::cout << "Tag /" << currTag.getTagName() << " matches top of stack." << std::endl;
					tags.pop();
				}
				else
				{
					//Tag is XXX but top of stack is YYY
				}
			}
		}
	}

	if (tagStack.empty())
	{
		while (!tagQueue.empty())
		{
			std::cout << tagQueue.front();
			tagQueue.dequeue();
		}
		//Empty, opening tags matched closing tags
	}
	else
	{
		//Not empty, mismatched tags
	}


	return 0;
}
