#include <cstdlib>
#include <vector>
using namespace std;

void calcSampleMean();
void calcStandardDeviation();

const int NUM_SIMULATIONS = 10000;

int main() {
    double leftExit = .4; //P(turn left and exit maze)
    double leftStay = .6; //P(turn left and stay in maze)
    vector<double> minutes; //vector containing time rat spends in maze each simulation
    srand((unsigned)time(0)); //generate random seed


    /* code here */
    minutes.push_back(yesOrNo(leftExit));
    return 0;
}

bool yesOrNo(float probabilityOfYes) {
  return rand()%100 < (probabilityOfYes * 100);
}