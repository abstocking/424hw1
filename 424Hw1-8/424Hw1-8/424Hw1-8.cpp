#include <iostream>
#include <string>
#include <map>
#include <memory>

using namespace std;

class Plane {
private:
    double pos, vel, distance;
    bool at_SCE;
    string origin, destination;
    map<string, map<string, int>> miles;

public:
    Plane(const string& from, const string& to) : origin(from), destination(to) 
    {
        miles["SCE"]["PHL"] = 160;
        miles["SCE"]["ORD"] = 640;
        miles["SCE"]["EWR"] = 220;
        distance = miles[origin][destination];
        pos = 0;
        vel = 0;
        cout << "Plane created at: " << this << endl;
    }

    ~Plane() 
    {
        cout << "Plane Destroyed" << endl;
    }

    void operate(double dt) 
    {
        if (pos < distance) 
        {
            pos += vel * dt / 3600;
            at_SCE = false;
        }
        else 
        {
            if (destination == "SCE") 
            {
                at_SCE = true;
            }
            swap(origin, destination);
            pos = 0.0;
        }
    }

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
    shared_ptr<Plane> myPlane;

    Pilot(const string& pilotName, shared_ptr<Plane> p) : name(pilotName), myPlane(move(p)) 
    {
        cout << name << " is at the gate ready to board the plane." << endl;
        cout << "Memory address: " << this << endl;
    }

    ~Pilot() 
    {
        cout << name << " is out of the plane." << endl;
    }

    string getName() const 
    {
        return name;
    }

    shared_ptr<Plane> getPlane() const 
    {
        return myPlane;
    }
};

int main()
{
    // Create a shared pointer to a Plane
    shared_ptr<Plane> plane = make_shared<Plane>("SCE", "PHL");

    // Create pilots and pass the plane by reference
    shared_ptr<Pilot> alpha = make_shared<Pilot>("Alpha", plane);
    shared_ptr<Pilot> bravo = make_shared<Pilot>("Bravo", plane);

    double speed = 400; // mph
    double step = 10;   // seconds
    int iter = 1000;

    alpha->getPlane()->set_vel(speed);

    // Start with alpha
    auto currentPilot = alpha;

    cout << "Plane is at SCE, Pilot: " << currentPilot->getName() << " Plane: " << currentPilot->getPlane() << endl;

    // iterates the solution 
    for (int i = 0; i < iter; i++)
    {
        currentPilot->getPlane()->operate(step);
        //checks to see if at SCE
        if (currentPilot->getPlane()->get_at_SCE())
        {
            cout << "Plane is at SCE" << endl;
            cout << "Switching pilot..." << endl;
            // Toggle between alpha and bravo
            if (currentPilot == alpha)
                currentPilot = bravo;
            else
                currentPilot = alpha;
            cout << "New Pilot: " << currentPilot->getName() << endl;

        }
    }

    return 0;
}
