#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Bus {
    string busNo, driver, arrival, depart, from, to;
    string seats[8][4];  // 8 rows x 4 columns

public:
    void addBus();
    void showBus();
    void bookSeat();
    void showSeats();
};

void Bus::addBus() {
    cout << "\nEnter Bus No: ";
    cin >> busNo;
    cout << "Driver Name: ";
    cin >> driver;
    cout << "Arrival Time: ";
    cin >> arrival;
    cout << "Departure Time: ";
    cin >> depart;
    cout << "From: ";
    cin >> from;
    cout << "To: ";
    cin >> to;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++)
            seats[i][j] = "Empty";

    cout << "\nBus Added Successfully!\n";
}

void Bus::showBus() {
    cout << "\nBus No: " << busNo
         << "\nDriver: " << driver
         << "\nArrival: " << arrival
         << "\nDeparture: " << depart
         << "\nFrom: " << from
         << "\nTo: " << to << endl;
}

void Bus::bookSeat() {
    int seat;
    cout << "\nEnter Seat Number (1-32): ";
    cin >> seat;

    int row = (seat - 1) / 4;
    int col = (seat - 1) % 4;

    if (seats[row][col] == "Empty") {
        cout << "Enter Passenger Name: ";
        cin >> seats[row][col];
        cout << "Seat booked successfully!\n";
    } else {
        cout << "Sorry, this seat is already booked.\n";
    }
}

void Bus::showSeats() {
    cout << "\nSeat Arrangement:\n";
    int seatNo = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            cout << seatNo++ << "." << seats[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    Bus b;
    int choice;

    while (true) {
        cout << "\n=== BUS RESERVATION SYSTEM ===\n";
        cout << "1. Add Bus\n2. Show Bus Details\n3. Book Seat\n4. Show Seat Arrangement\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: b.addBus(); break;
            case 2: b.showBus(); break;
            case 3: b.bookSeat(); break;
            case 4: b.showSeats(); break;
            case 5: exit(0);
            default: cout << "Invalid choice!\n";
        }
    }
    return 0;
}