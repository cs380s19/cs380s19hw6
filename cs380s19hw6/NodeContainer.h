//*****************************************************************************
// File name:  NodeContainer.h
// Author:     Chadd Williams
// Date:       10/2/2013
// Class:      CS380
// Assignment: Path Finder
// Purpose:    To define an interface to walk through nodes in a container
//*****************************************************************************

#pragma once
#include "Node.h"

class NodeContainer
{
public:

	virtual ~NodeContainer() {};

	/* set the iterator at the first Node*/
	virtual void beginNode() = 0;

	/* get the Node and move the iterator.  If no Node is available, return NULL*/
	// http://stackoverflow.com/questions/5598703/c-const-usage-explanation
	virtual  Node const * const getNextNode() = 0;

	virtual int getNumberOfNodes() const = 0;
};