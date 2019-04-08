//*****************************************************************************
// File name:  Node.h 
// Author:     Chadd Williams (mod Chris Lane)
// Date:       10/2/2013 (3/27/2019)
// Class:      CS380
// Assignment: Path Finder
// Purpose:    Define a node in a graph
//*****************************************************************************

#pragma once
#include <string>
#include <vector>
#include "Edge.h"

class Edge;

class Node
{
public:
	// Each node must have a name
	Node(std::string name) : mName(name) {};

	// virtual destructor
	virtual ~Node() {};

	// get the name
	std::string getName() const { return mName; };

	void addEdge(Edge *edge) { edges.push_back(edge); };

	std::vector<Edge*> getEdges() { return edges; };

	void setNodeID(int id) { mNodeID = id; };

	int getNodeID() const { return mNodeID; };

private:
	std::string mName;
	std::vector<Edge*> edges;
	int mNodeID;
};
