#include <iostream>
#include <string>
#include <map>

using namespace std;


class Plane
{
private:

	double pos, vel, distance;
	bool at_SCE;
	string origin, destination;

	// sets up the container
	map<string, map< string, int >> miles;
	
public:

	Plane(const string& from, const string& to) : origin(from), destination(to)
	{
		
	}

	~Plane()
	{
	}

	void operate(double dt)
	{
		
	}

	double get_pos()
	{
		return pos;
	}
	
	string get_origin()
	{
		return origin;
	}

	string get_destination()
	{
		return destination;
	}

	bool get_at_SCE()
	{
		return at_SCE;
	}

	double get_vel()
	{
		return vel;
	}

	void set_vel(double vel2)
	{
		vel = vel2;
	}


};