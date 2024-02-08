// Homework 1, Question 1 
// AERSP 424
// Aspen Stocking
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{

	// start off by establishing all the variables for the inputs
	// then ask user for inputs
	unsigned int AEW, airMom, passFront, passRear, frontMom, rearMom, useFuel, bagWeight, fuelMom, bagMom, weightPG;
	cout << "input aircraft empty weight (lbs): ";
	cin >> AEW;
	cout << endl << "input aircraft empty-weight moment (lbs*in):";
	cin >> airMom;
	cout << endl << "input number of front passengers: ";
	cin >> passFront;

	// creates an array the size of the number of front passengers for the passengers weights
	vector<int> weightPassFront(passFront);

	// for loop for the front passenger weight input
	for (int i = 0; i < passFront; i++)
	{
		cout << "input front passenger " << i + 1 << "'s weight (lbs): ";
		cin >> weightPassFront[i];
	}

	cout << endl << "input front passenger moment arm (in.): ";
	cin >> frontMom;
	cout << endl << "input number of rear passengers: ";
	cin >> passRear;

	// creates an array the size of the number of rear passengers for the passengers weights
	vector<int> weightPassRear(passRear);

	// for loop for the rear passenger weight input
	for (int j = 0; j < passRear; j++)
	{
		cout << "input rear passenger " << j + 1 << "'s weight (lbs): ";
		cin >> weightPassRear[j];
	}

	cout << endl << "input rear passenger moment arm (in.): ";
	cin >> rearMom;
	cout << endl << "input ammount of useable fuel (gallons): ";
	cin >> useFuel;
	cout << endl << "input usable fuel weight per gallon (lbs): ";
	cin >> weightPG;
	cout << endl << "input fuel moment arm (in.): ";
	cin >> fuelMom;
	cout << endl << "input weight of baggage (lbs): ";
	cin >> bagWeight;
	cout << endl << "input baggage moment arm (in.): ";
	cin >> bagMom;

	double gross, frontWeight, rearWeight, fuelWeight;

	frontWeight = 0;
	rearWeight = 0;
	
	// these for loops calculate the total weight of all the passengers, front and rear
	for (int k = 0; k < passFront; k++)
	{
		frontWeight += weightPassFront[k];
	}

	for (int l = 0; l < passRear; l++)
	{
		rearWeight += weightPassRear[l];
	}

	// calculates the weight of the fuel
	fuelWeight = weightPG * useFuel;
	

	// calculates total weight
	gross = fuelWeight + rearWeight + frontWeight + bagWeight + AEW;

	double frontMoment, rearMoment, fuelMoment, bagMoment, newFuelMoment;

	// finds the individual moments and adds them together
	frontMoment = frontMom * frontWeight;
	rearMoment = rearMom * rearWeight;
	fuelMoment = fuelMom * fuelWeight;
	bagMoment = bagMom * bagWeight;

	// calculates total moment
	double totalMoment;

	totalMoment = bagMoment + fuelMoment + rearMoment + frontMoment + airMom;

	//calculates the current cg location from initial inputs
	double CG, counter;
	counter = 0;

	CG = totalMoment / gross;


	// The following series of if else statements and while loops check different cases of the CG, gross weight, and the CG location in relation to the fuel moment arm
	

	if (CG < 82.1 && gross < 2950)
	{
		if (CG < fuelMom)
		{
			while (CG < 82.1 && gross < 2950)
			{
				fuelWeight += 0.01;
				counter += 0.01;
				gross = fuelWeight + rearWeight + frontWeight + bagWeight + AEW;
				fuelMoment = fuelWeight * fuelMom;
				totalMoment = bagMoment + fuelMoment + rearMoment + frontMoment + airMom;
				CG = totalMoment / gross;

			}
			cout << "CG is (inches): " << CG << endl;
			cout << "Gross Weight is (lbs.): " << gross << endl;
			cout << "Ammount of fuel added is (lbs.): " << counter << endl;
		}
		else
		{
			while (CG < 82.1 && fuelWeight > 0)
			{
				fuelWeight -= 0.01;
				counter -= 0.01;
				gross = fuelWeight + rearWeight + frontWeight + bagWeight + AEW;
				fuelMoment = fuelWeight * fuelMom;
				totalMoment = bagMoment + fuelMoment + rearMoment + frontMoment + airMom;
				CG = totalMoment / gross;
			}
			cout << "CG is (inches): " << CG << endl;
			cout << "Gross Weight is (lbs.): " << gross << endl;
			cout << "Ammount of fuel removed is (lbs.): " << counter << endl;
		}
	}
	else
		if (CG > 84.7 && gross > 2950)
		{
			if (CG < fuelMom)
			{
				while (CG > 84.7 && fuelWeight > 0)
				{
					fuelWeight -= 0.01;
					counter -= 0.01;
					gross = fuelWeight + rearWeight + frontWeight + bagWeight + AEW;
					fuelMoment = fuelWeight * fuelMom;
					totalMoment = bagMoment + fuelMoment + rearMoment + frontMoment + airMom;
					CG = totalMoment / gross;

				}
				cout << "CG is (inches): " << CG << endl;
				cout << "Gross Weight is (lbs.): " << gross << endl;
				cout << "Ammount of fuel removed is (lbs.): " << counter << endl;
			}
			else
			{
				cout << "aircraft cannot meet specifications" << endl;
			}
		}
		else
			if (CG < 82.1 && gross > 2950)
			{
				if (CG < fuelMom)
				{
					cout << "aircraft cannot meet specifications" << endl;
				}
				else
				{
					while (CG < 82.1 && fuelWeight > 0)
					{
						fuelWeight -= 0.01;
						counter -= 0.01;
						gross = fuelWeight + rearWeight + frontWeight + bagWeight + AEW;
						fuelMoment = fuelWeight * fuelMom;
						totalMoment = bagMoment + fuelMoment + rearMoment + frontMoment + airMom;
						CG = totalMoment / gross;
					}
					cout << "CG is (inches): " << CG << endl;
					cout << "Gross Weight is (lbs.): " << gross << endl;
					cout << "Ammount of fuel removed is (lbs.): " << counter << endl;
				}
			}
			else
				if (CG > 84.7 && gross < 2950) 
				{
					if (CG < fuelMom)
					{
						while (CG < 82.1 && fuelWeight > 0)
						{
							fuelWeight -= 0.01;
							counter -= 0.01;
							gross = fuelWeight + rearWeight + frontWeight + bagWeight + AEW;
							fuelMoment = fuelWeight * fuelMom;
							totalMoment = bagMoment + fuelMoment + rearMoment + frontMoment + airMom;
							CG = totalMoment / gross;

						}
						cout << "CG is (inches): " << CG << endl;
						cout << "Gross Weight is (lbs.): " << gross << endl;
						cout << "Ammount of fuel removed is (lbs.): " << counter << endl;
					}
					else
					{
						while (CG > 84.7 && gross < 2950)
						{
							fuelWeight += 0.01;
							counter += 0.01;
							gross = fuelWeight + rearWeight + frontWeight + bagWeight + AEW;
							fuelMoment = fuelWeight * fuelMom;
							totalMoment = bagMoment + fuelMoment + rearMoment + frontMoment + airMom;
							CG = totalMoment / gross;
						}
						cout << "CG is (inches): " << CG << endl;
						cout << "Gross Weight is (lbs.): " << gross << endl;
						cout << "Ammount of fuel added is (lbs.): " << counter << endl;
					}
				}
				else
				{
					cout << "CG is (inches): " << CG << endl;
					cout << "Gross weight is (lbs.): " << gross << endl;
				}
		
	
	return 0;
}