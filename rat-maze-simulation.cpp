#include <cstdlib>
#include <vector>
#include <ctime>
#include <iostream>
using namespace std;

bool goRight(double);
bool goLeftExit(double);

const int NUM_SIMULATIONS = 10000;
bool exitMaze = false; 	 //check if rat is in maze

int main() {
	vector<double> minutes; //vector containing time rat spends in maze each simulation

	srand((unsigned)time(NULL)); //generate random seed

	for (int counter = 0; counter < NUM_SIMULATIONS; ++counter) {
		double time = 0;

		while (!exitMaze) {
			if (goRight(rand() % 100)) {
				//cout << "Going right!" << endl;
				time += 4; //add 4 minutes to total time spent
			}
			else {
				if (goLeftExit(rand() % 100)) {
					time += 3; //add 3 minutes to total time spent
					//cout << "Goodbye!" << endl;
					exitMaze = true;
					//cout << "Total minutes spent in simulation #" << counter << ": " << time << " minutes." << endl;
					minutes.push_back(time);
				}
				else { //this is goLeftStay()
					time += 6; //add 6 minutes to total time spent
					//cout << "Going left!" << endl;
				}
			}
		}
		exitMaze = false;
	}
	
	/*calculating mean*/
	double meanTime; //average time spent in maze across all simulations
	double tmp = 0; //temporary value to hold totals
	for (int i = 0; i < minutes.size(); ++i) {
		tmp += minutes[i];
	}
	meanTime = tmp / NUM_SIMULATIONS;
	cout << "PART A" << endl;
	cout << "Mean time spent in maze: " << meanTime << " minutes. " << endl;

	/*calculating standard deviation*/
	double standardDeviation;
	tmp = 0;
	vector<double> std = minutes;
	for (int i = 0; i < std.size(); ++i) {
		std[i] = std[i] - meanTime; //subtracting value by mean
		std[i] = pow(std[i], 2); //squaring by 2
		tmp += std[i]; //adding up value
	}
	tmp = tmp / NUM_SIMULATIONS;
	standardDeviation = sqrt(tmp);

	cout << endl << endl;
	cout << "PART B" << endl;
	cout << "Standard deviation: " << standardDeviation << endl;
	
	return 0;
}

/*roll if rat goes left and departs maze*/
bool goLeftExit(double num) {
	double p = (.4 * .5 * 100); //probability this event occurs

	if (num < p)
		return true;
	else
		return false;
}

/*roll if rat goes to the left and returns to initial position*/
bool goLeftStay(double num) {
	double p = (.6 * .5 * 100); //probability this event occurs

	if (num < p)
		return true;
	else
		return false;
}

/*roll if rat goes right and returns to initial position*/
bool goRight(double num) { 
	double p = (.5 * 100); //probability this event occurs

	if (num < p)
		return true;
	else
		return false;
}
