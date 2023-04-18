#include <iostream>
#include "itemType.h"
/*	I would like to #include itemType.h only
	but that does not work for class templates.  */
#include "listType.cpp"   // for class templates, the source file (.cpp) is included
										// other methods exist; however, none are particularly graceful.
using namespace std;

/*
	The main point is to demonstrate abstraction.  The operations on an elementType
	are all properties of and defined by elementType.  The list template "knows"
	nothing of these, except that they must be defined.  In this example, a listType object
	is instantiated passing it type int:  listType<int> myList2;  It works fine because int
	has all of the required operators defined.  Type float, char, or string would also
	work.

	the job of "driver.cpp" [which contains main() ] is simply to test the listType.  The driver
	code has intimate knowledge of itemType... itemType might as well be defined within
	that file; it would work if it were so long as, whatever it is, has the six relational operators,
	assignment, and insertion defined upon it.
*/

int main()
{

    listType<itemType> myLinkedList;
	myLinkedList.create();

	itemType e;

	e="test value 40";
	myLinkedList.put(e);


	e="test value 20";
	myLinkedList.put(e);


	e="test value 60";
	myLinkedList.put(e);


	e="test value 30";
	myLinkedList.put(e);


	e="test value 50";
	myLinkedList.put(e);


	e="test value 70";
	myLinkedList.put(e);


	e="test value 10";
	myLinkedList.put(e);


	e="test value 25";
	myLinkedList.put(e);


	e="test value 55";
	myLinkedList.put(e);
	myLinkedList.showTreeStats();
	myLinkedList.print();
	cin.get();


/*			At this point, your tree looks like this on my input.

										40(0)
					20(1)										60(1)
			10(2)		30(2)						50(2)		70(2)
						25(3)								55(3)


numNodes = 9    calcLvls = 4    cntLvls = 4

*********************
Level - 0       test value 40
Level - 1       test value 60
Level - 2       test value 70
Level - 2       test value 50
Level - 3       test value 55
Level - 1       test value 20
Level - 2       test value 30
Level - 3       test value 25
Level - 2       test value 10


*********************



*/

	e="test value 25";
	myLinkedList.remove(e); // zero children
	myLinkedList.showTreeStats();
	myLinkedList.print();
	cin.get();

/*		After removing 25, it should be:


										40(0)
					20(1)										60(1)
			10(2)		30(2)						50(2)		70(2)
																55(3)

numNodes = 8    calcLvls = 4    cntLvls = 4



*********************
Level - 0       test value 40
Level - 1       test value 60
Level - 2       test value 70
Level - 2       test value 50
Level - 3       test value 55
Level - 1       test value 20
Level - 2       test value 30
Level - 2       test value 10


*********************

*/

	e="test value 50";
	myLinkedList.remove(e); // one child
	myLinkedList.showTreeStats();
	myLinkedList.print();
	cin.get();

/*

After removing 50, it should be:


										40(0)
					20(1)										60(1)
			10(2)		30(2)						55(2)		70(2)


numNodes = 7    calcLvls = 3    cntLvls = 3

*********************
Level - 0       test value 40
Level - 1       test value 60
Level - 2       test value 70
Level - 2       test value 55
Level - 1       test value 20
Level - 2       test value 30
Level - 2       test value 10


*********************
*/

	e="test value 40";
	myLinkedList.remove(e); // two children
	myLinkedList.showTreeStats();
	myLinkedList.print();
	cin.get();

/*

After removing 40, it should be:


										30(0)
					20(1)										60(1)
			10(2)									55(2)				70(2)


numNodes = 6    calcLvls = 3    cntLvls = 3

*********************
Level - 0       test value 30
Level - 1       test value 60
Level - 2       test value 70
Level - 2       test value 55
Level - 1       test value 20
Level - 2       test value 10
*********************

					OR (option two)  Either is valid!
					The first option is how I developed it; however, the second is also correct



										55(0)
					20(1)										60(1)
			10(2)		30(2)											70(2)


numNodes = 6    calcLvls = 3    cntLvls = 3

*********************
Level - 0       test value 55
Level - 1       test value 60
Level - 2       test value 70
Level - 1       test value 20
Level - 2		test value 30
Level - 2       test value 10
*********************

*/

	cout<<"\n\t*** Run Complete ***\n\n";
    return 0;
}
