// listType.cpp				S.W. Smith

#ifndef LISTTYPE_FLAG
#define LISTTYPE_FLAG
#include <iostream>
#include <cmath>
using namespace std;

template <class elementType>
class listType
{
private:
	// the definition of the struct nodeType is private
	struct nodeType
	{
		elementType payLoad;
		nodeType *left, *right;

		nodeType()
		{
			left = NULL;
			right = NULL;
			return;
		}
	};

	int numNodes, numLvls;

	nodeType *root;

	nodeType **envPtr; // double Pointer!!!  (This is new.)

	//**************************************
	// called by create() and the destructor;
	void altDeleteTree(nodeType *p) // version with the recursion at end of the logic.
	{
		if (p)
		{
			altDeleteTree(p->left);
			altDeleteTree(p->right);
			delete p;
		}

		return;
	}

	//***********************************
	// wrapper method for print()
	void altPrint(nodeType *p, int level)
	{
		if (p)
		{
			cout << "Level - " << level << '\t' << p->payLoad << '\n';
			altPrint(p->right, level + 1);
			altPrint(p->left, level + 1);
		}
		return;
	}
	//************************************
	// diagnostic routines

	int cntLvls(nodeType *p)
	{
		numLvls = 0;
		altCntLvls(p, 1);
		return numLvls;
	}

	void altCntLvls(nodeType *p, int i)
	{
		if (!p)
			return;
		else
		{
			if (i > numLvls)
				numLvls = i; // numLvls is a class variable

			altCntLvls(p->left, i + 1);
			altCntLvls(p->right, i + 1);
		}
	}

	//***************************************

	int calcLvls()
	{
		return ceil(log(numNodes + 1) / log(2));
	}

public:
	listType()
	{
		numNodes = 0;
		root = NULL;
		envPtr = NULL;

		return;
	} // constructor.

	//******************************

	~listType()
	{
		altDeleteTree(root); // this deletes an existing list

		return;
	} // destructor.

	//******************************

	void create()
	{
		altDeleteTree(root);
		root = NULL;
		numNodes = 0;

		return;
	}

	//******************************

	bool isRoom()
	{
		// There is no standard way to do this with 100% certainty.
		// Here is one approach:

		nodeType *p;
		p = new nodeType;
		if (p) // allocation failure returns NULL pointer
		{
			delete p;
			return true;
		}
		else
			return false;
	}

	//****************************************

	bool isThere(elementType &e)
	{
		envPtr = &root;
		while (*envPtr && (*envPtr)->payLoad != e)
			if ((*envPtr)->payLoad > e)
				envPtr = &(*envPtr)->left;
			else
				envPtr = &(*envPtr)->right;

		return *envPtr;
	}

	//******************************

	void showTreeStats()
	{
		cout << "\n\nnumNodes = " << numNodes << "\tcalcLvls = " << calcLvls() << "\tcntLvls = " << cntLvls(root) << "\n\n";
		//<<'\t'<<(double)numLvls(root)/calcLvls()<<"\n\n";
	}

	void put(elementType &e)
	{
		// I should check isRoom() here.  Not sure what I'd do
		// if it failed to allocate.  I suppose ask the user?

		// inserting a node into a leaf of a binary tree:
		if (!isThere(e))
		{
			*envPtr = new nodeType;
			(*envPtr)->payLoad = e; // note: always inserts at a "leaf" node.
			numNodes++;
		}

		return;
	}

	//******************************
	void remove(elementType &e)

	{

		nodeType **dp = NULL, *p = NULL, *q = NULL;

		if (isThere(e))

		{

			if (!(*envPtr)->left || !(*envPtr)->right)

			{

				if ((*envPtr)->left)

				{

					(*envPtr)->right = NULL;

					nodeType *p;

					p = *envPtr;

					p->left = (*dp);

					(*dp) = p;
				}

				// both nodes are NULL
				else

				{

					nodeType *p;

					p = *envPtr;

					p->right = *dp;

					(*dp) = p;
				}
			}

				else

			{

				dp = &(*envPtr)->left;

				// largest node in the binary tree is the rightmost node

				while ((*dp)->right)

				{

					dp = &(*dp)->right;
				}

				p = *envPtr;

				q = *dp;
			}
		}

		return;
	}

	//******************************

	void print() // for diagnostics only
	{
		cout << "\n\n*********************\n";

		altPrint(root, 0);

		cout << "\n\n*********************\n";
		return;
	}
};
#endif
