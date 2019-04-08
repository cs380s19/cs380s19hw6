//*****************************************************************************
// File name:  main.cpp
// Author:     Chris Lane 
// Date:       3/28/2019
// Class:      CS380
// Assignment: Pathfinder
// Purpose:    Driver for the project 
//*****************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

#include <Windows.h> // Needed for Shell Execute

void printTitle();

void graphPath(std::vector<int> route, int totalDistance);

//*****************************************************************************
// Method:			main
//
// Description: The main method for this application.
//
// Parameters:	none
//
// Returned:		none
//	
//*****************************************************************************
int main()
{
	const std::string INPUT_FILE = "points.txt";
	int numCities, numRoads;
	//int weight;
	int src, dest;
	int totalDistance = 0;

	std::string name;
	std::ifstream inFile;

	std::vector<int> path;

	// Node *pNode, *pNodeLeft, *pNodeRight;

	inFile.open(INPUT_FILE);

	inFile >> numCities;

	for (int i = 0; i < numCities; ++i)
	{
		// add node to graph
	}

	inFile >> numRoads;

	for (int i = 0; i < numRoads; i++)
	{
		//add edges to graph
	}

	inFile.close();

	printTitle();

	std::cout << "\nEnter number corresponding to starting city: " << std::endl;
	std::cin >> dest;
	std::cout << "Enter number corresponding to destination city: " << std::endl;
	std::cin >> src;

	// Send graph, src, destination ID's to disjktra returns vector 
	// from which you can compute the vector path and int total distance 
	// Here we are just displaying a path from the two nodes entered
	// There is no checking done here if the actual path exists!!

	path.push_back(dest);
	path.push_back(src);

	std::cout << "\nTotal Distance:" << totalDistance << std::endl;

	graphPath(path, totalDistance);

	// Ask user if they'd like to go again
	return 1; 
}

//*****************************************************************************
// Method:			printTitle
//
// Description: Print heading for application
//
// Parameters:	none
//
// Returned:		none
//	
//*****************************************************************************

void printTitle()
{
	std::cout << "***************************************************\n";
	std::cout << "*                CS 380: Pathfinder               *\n";
	std::cout << "***************************************************\n";
}

//*****************************************************************************
// Method:			graphPath
//
// Description: Creates a URL string and sends this string to the Chrome
//							browser. The PHP within the webpage parses the string and the
//							distance sent and	displays both using Google Maps
//
// Parameters:	route, vector containing the ID's of the route
//							totalDistance, total length of route
//
// Returned:		none
//	
//*****************************************************************************

void graphPath(std::vector<int> route, int totalDistance)
{
	std::string newRoute;
	std::string url =
		"http://webwork.math.pacificu.edu/cs380s19/googleMaps.php?path=";

	for (int i = 0; i < (int)route.size(); i++)
	{
		newRoute += std::to_string(route[i]);
		if (i < (int)route.size() - 1)
		{
			newRoute += ",";
		}
	}

	url += newRoute;

	url += "&totalDistance=";

	url += std::to_string(totalDistance);

	// ShellExecuteA needs long pointer to a constant string for URL
	// https://stackoverflow.com/questions/321413/lpcstr-lpctstr-and-lptstr

	LPCSTR fullUrl = url.c_str();

	ShellExecuteA(0, 0, "chrome.exe", fullUrl, 0, SW_SHOWMAXIMIZED);
}