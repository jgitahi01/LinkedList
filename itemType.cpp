
#include "itemType.h"
#include <iostream>
using namespace std;

itemType::itemType()
{
	identifier="~~~";
} // stubbed constructor

itemType::itemType(const itemType &p)
{
	identifier = p.identifier;
} // copy constructor

void itemType::operator =(itemType &i)
{
	identifier=i.identifier;
}

bool itemType::operator ==(itemType &i)
{
	return identifier==i.identifier;
}

bool itemType::operator >(itemType &i)
{
	return identifier>i.identifier;
}

bool itemType::operator <(itemType &i)
{
	return identifier<i.identifier;
}

bool itemType::operator !=(itemType &i)
{
	return identifier!=i.identifier;
}

bool itemType::operator >=(itemType &i)
{
	return identifier>=i.identifier;
}

bool itemType::operator <=(itemType &i)
{
	return identifier<=i.identifier;
}


void itemType::operator =(string s) // included only for the programmer's convieniance
{
	identifier=s;
}
/*	in driver.cpp, the code:

		itemType i;
		i.identifier="foo";

	would be perfectly legal.  This operator allows it to be simply:		i="foo";
	It's entirely optional.
*/

ostream &operator << (ostream &out, const itemType &c) // needed to print the list
{
    out << c.identifier;
    return out;
}


