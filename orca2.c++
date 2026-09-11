#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class MissionManager {
private:
    string currentState;
    string action;

public:
    MissionManager() {
        currentState = "IDLE";
        action = "WAITING";
    }

void updateState(string objectName, double confidence, double distance) {
   
    if (objectName != "" && confidence >= 0.70) {
        if (distance <= 0.5) {
            currentState = "MISSION_COMPLETE";
            action = "HOLD POSITION";
        } 
        else if (distance <= 2.0) {
            currentState = "APPROACHING";
            action = "ALIGN AND MOVE FORWARD";
        } 
        else {
            currentState = "DETECTED";
            action = "APPROACH TARGET";
        }
    } 
    else {
        currentState = "SEARCHING";
        action = "SEARCH TARGET";
    }
}
    string getState() {
        return currentState;
    }

    string getAction() {
        return action;
    }
};

int main() {
    string objectName;
    double confidence, distance;

    // Hanya membaca 3 nilai murni
    if (cin >> objectName >> confidence >> distance) {
        
        MissionManager manager;
        manager.updateState(objectName, confidence, distance);

        cout << fixed << setprecision(2);
        cout << "Object detected: " << objectName 
             << " Confidence: " << confidence 
             << " Distance: " << distance << " m" << endl;

        cout << "Mission State: " << manager.getState() 
             << " Action: " << manager.getAction() << endl;
    }

    return 0;
}