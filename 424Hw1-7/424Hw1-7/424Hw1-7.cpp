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

	// constructor
	Plane(const string& from, const string& to) : origin(from), destination(to)
	{
		this->origin = from;
		destination = to;

		// sets up the container values
		miles["SCE"]["PHL"] = 160;
		miles["SCE"]["ORD"] = 640;
		miles["SCE"]["EWR"] = 220;


		// takes the inputs and creates the distance 
		distance = miles[origin][destination];

		// initializes pos and vel
		pos = 0;
		vel = 0;

		// outputs the memory location of plane
		cout << "Plane created at: " << this << endl;
	}

	// deconstructor
	~Plane()
	{
		cout << "Plane Destroyed" << endl;
	}

	void operate(double dt)
	{

		// follows the flow chart seen in the problem statement 
		if (pos < distance)
		{
			// increments the position 
			pos += vel * dt / 3600; // 3600 used to maintain consistent dimensions
			// shows plane is not at the destination
			at_SCE = 0;
		}
		else
		{
			if (destination == "SCE")
			{
				at_SCE = 1;
			}

			// temp is a temperary variable to help swap the two strings
			string temp;
			temp = origin;
			origin = destination;
			destination = temp;

			// sets pos to 0
			pos = 0.0;

		}
	}
	// get functions
	double get_pos() const
	{
		return pos;
	}

	string get_origin() const
	{
		return origin;
	}

	string get_destination() const
	{
		return destination;
	}

	bool get_at_SCE() const
	{
		return at_SCE;
	}

	double get_vel() const
	{
		return vel;
	}

	void set_vel(const double vel)
	{
		this->vel = vel;
	}


};

class Pilot
{
private:
	string name;

public:
	//pointer to plane
	Plane* myPlane;

	//pilot constructor 
	Pilot(const string& pilotName, Plane* p) : name(pilotName), myPlane(p)
	{
		cout << name << " is at the gate ready to board the plane." << endl;
		cout << "Memory address: " << this << endl;
	}

	//pilot deconstructor 
	~Pilot()
	{
		cout << name << " is out of the plane." << endl;
	}

	string getName() const
	{
		return name;
	}

	Plane* getPlane()
	{
		return myPlane;
	}

};

int main()
{
	//sets up the plane with locations and names of pilots specified 
	Plane plane("SCE", "PHL");
	Pilot alpha("Alpha", &plane);
	Pilot bravo("Bravo", &plane);

	double speed = 400; //mph
	double step = 10; //seconds
	int iter = 1000;

	//sets speed
	plane.set_vel(speed);

	//starts with alpha
	Pilot* currentPilot = &alpha;


	cout << "Plane is at SCE, Pilot: " << currentPilot->getName() << " Plane: " << currentPilot->getPlane() << endl;
	//loop that iterates the time step to see when the pilot needs to be changed
	for (int i = 0; i < iter; i++)
	{
		plane.operate(step);
		if (plane.get_at_SCE())
		{
			cout << "Plane is at SCE" << endl;
			cout << "Switching pilot..." << endl;
			if (currentPilot == &alpha)
				currentPilot = &bravo;
			else
				currentPilot = &alpha;
			cout << "New Pilot: " << currentPilot->getName() << endl;
		}
	}


	return 0;
}


