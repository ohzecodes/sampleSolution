#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

enum CARS { Car0 = 1,
            Car1 = 2,
            Car2 = 4,
            Car3 = 8,
            Car4 = 16,
            Car5 = 32,
            Car6 = 64,
            Car7 = 128 };

bool RentalStatus(unsigned char* fleet, int car);

void RentCar(unsigned char* fleet, int car) {
    int f = (int)*fleet;
    // (f ^ car) != 0
    if (!(RentalStatus(fleet, car))) {
        *fleet = *fleet | (unsigned char)car;
        cout << "Booking Successfull";
    } else {
        cout << "Booking unSuccessfull; car rented by another user ";
    }
    cout << endl;
}

void ReturnCar(unsigned char* fleet, int car) {
    int f = (int)*fleet;
    //     if (((f & car) == car)) {
    if (RentalStatus(fleet, car)) {
        *fleet = f ^ (unsigned char)car;
        cout << "return Succesfull";
    } else {
        cout << "return Unsuccesfull: car was never borrowed ";
    }
    cout << endl;
}

bool RentalStatus(unsigned char* fleet, int car) {
    int f = (int)*fleet;
    if (((f & car) == car)) {
        return true;

    } else {
        return false;
    }
}

void showfleet(unsigned char* fleet) {
    cout << boolalpha << endl;
    for (int i = pow(2, 0), j = 0; j < 8; i = pow(2, j + 1), j++) {
        cout << "  Car" << j << " : " << RentalStatus(fleet, i) << endl;
    }
    cout << endl;
}

int car(int number) {
    if (number <= 7 && number >= 0)
        return pow(2, number);
    else
        return 0;
}

void menu(unsigned char* fleet) {
    int ui;
    cout << "Welcome to my Car Rental Company: Pleaase Choose One Of The Following Options: \n";
    cout << "0: Exit Program\n1: Show Fleet \n2: Rent Car\n3: Return Car " << endl;
    cin >> ui;
    if (ui == 0) {
        return;
    } else {
        switch (ui) {
            case 1:
                showfleet(fleet);
                break;
            case 2:
                int ui0;

                cout << "enter car (0-7) " << endl;
                cin >> ui0;

                RentCar(fleet, car(ui0));

                break;
            case 3:
                int ui2;
                cout << "enter car (0-7) " << endl;
                cin >> ui2;

                ReturnCar(fleet, car(ui2));

                break;
        }

        menu(fleet);
    }
}

int main() {
    unsigned char p = (unsigned char)0;
    unsigned char* fleet = &p;

    menu(fleet);

    return 0;
}
