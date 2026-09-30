#include <iostream>
using namespace std;

class ThreePhaseMotorStarter {
private:
    bool motorRunning;
    bool overload;
    bool emergencyStop;

public:
    ThreePhaseMotorStarter() {
        motorRunning = false;
        overload = false;
        emergencyStop = false;
    }

    void startMotor() {
        if (overload) {
            cout << "\nCannot start motor!";
            cout << "\nReason: Overload detected.\n";
            return;
        }

        if (emergencyStop) {
            cout << "\nCannot start motor!";
            cout << "\nReason: Emergency stop is active.\n";
            return;
        }

        motorRunning = true;

        cout << "\nMotor Started Successfully!";
        cout << "\nThree-phase supply: ON";
        cout << "\nContactor: CLOSED\n";
    }

    void stopMotor() {
        motorRunning = false;

        cout << "\nMotor Stopped.";
        cout << "\nThree-phase supply: OFF";
        cout << "\nContactor: OPEN\n";
    }

    void setOverload(bool status) {
        overload = status;

        if (overload && motorRunning) {
            motorRunning = false;

            cout << "\nOVERLOAD DETECTED!";
            cout << "\nMotor automatically stopped.";
            cout << "\nProtection: ACTIVATED\n";
        }
    }

    void emergencyStopMotor() {
        emergencyStop = true;
        motorRunning = false;

        cout << "\nEMERGENCY STOP ACTIVATED!";
        cout << "\nMotor stopped immediately.\n";
    }

    void resetEmergency() {
        emergencyStop = false;

        cout << "\nEmergency stop reset.";
        cout << "\nSystem ready.\n";
    }

    void showStatus() {
        cout << "\n===== MOTOR STATUS =====\n";

        if (motorRunning)
            cout << "Motor Status : RUNNING\n";
        else
            cout << "Motor Status : STOPPED\n";

        cout << "Overload     : "
             << (overload ? "YES" : "NO") << endl;

        cout << "Emergency    : "
             << (emergencyStop ? "ACTIVE" : "OFF") << endl;
    }
};

int main() {
    ThreePhaseMotorStarter motor;

    int choice;

    cout << "====================================\n";
    cout << "     THREE-PHASE MOTOR STARTER\n";
    cout << "====================================\n";

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Start Motor\n";
        cout << "2. Stop Motor\n";
        cout << "3. Simulate Overload\n";
        cout << "4. Emergency Stop\n";
        cout << "5. Reset Emergency Stop\n";
        cout << "6. Show Motor Status\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                motor.startMotor();
                break;

            case 2:
                motor.stopMotor();
                break;

            case 3:
                motor.setOverload(true);
                break;

            case 4:
                motor.emergencyStopMotor();
                break;

            case 5:
                motor.resetEmergency();
                break;

            case 6:
                motor.showStatus();
                break;

            case 7:
                cout << "\nProgram terminated.\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
