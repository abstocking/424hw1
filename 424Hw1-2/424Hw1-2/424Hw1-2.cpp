// Homework 1, Question 2
// AERSP 424
// Aspen Stocking

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

	// sets up the container
	map<string, map< string, int >> miles;

	// creates the distances for each airport pair
	miles["SCE"]["PHL"] = 160;
	miles["SCE"]["ORD"] = 640;
	miles["SCE"]["EWR"] = 220;

	// outputs the distances
	cout << "Distance from State College to Philadelphia (miles): " << miles["SCE"]["PHL"];
	cout << endl << "Distance from State College to Chicago (miles): " << miles["SCE"]["ORD"];
	cout << endl << "Distance from State College to Newark (miles): " << miles["SCE"]["EWR"] << endl;


	return 0;
}
