#include <iostream>
#include <iomanip>
#include "AirlineReservation.h"
using namespace std;
void printSeparator(const string& title) {
    cout << "\n" << string(55, '=') << "\n";
    cout << "  " << title << "\n";
    cout << string(55, '=') << "\n";
}

int main() {
    cout << "\n===FUNCTION OVERLOADING===\n";
    Flight f1;
    f1.initialize();
    cout << "\n" << f1;
    Flight f2;
    f2.initialize("PK-303", "Karachi", "Lahore", 150.0);
    cout << "\n" << f2;
    Flight f3;
    f3.initialize("PK-505", "Islamabad", "Dubai", 250.0, 10, 4, 2);
    cout << "\n" << f3;
    cout << "\n===seat booking& allocation====\n";
    try {
        f3.bookSeat(1, "Ali Khan");        // seat 1 = First class
        f3.bookSeat(2, "Sara Ahmed");      // seat 2 = First class
        f3.bookSeat(3, "Omar Raza");       // seat 3 = Business
        f3.bookSeat(7, "Fatima Malik");    // seat 7 = Economy
        cout << "Seats 1, 2, 3, 7 booked successfully.\n";
    } catch (const exception& e) {
        cout << "Booking error: " << e.what() << "\n";
    }
    try {
        int allocated = f3.allocateSeat("Business", "Hasan Sheikh");
        cout << "Auto-allocated Business seat #" << allocated<< " to Hasan Sheikh.\n";
    } catch (const exception& e) {
        cout << "Allocation error: " << e.what() << "\n";
    }
    try {
        f3.bookSeat(1, "Test User");
    } catch (const exception& e) {
        cout << "[Expected error] " << e.what() << "\n";
    }
    f3.cancelSeat(7);
    cout << "Seat 7 booking cancelled.\n";
    f3.displayManifest();
    cout << "\n ==== fair information ====\n";
    cout << "Economy  fare: $" << fixed << setprecision(2) << f3.getFare("Economy") << "\n";
    cout << "Business fare: $" << f3.getFare("Business") << "\n";
    cout << "First    fare: $" << f3.getFare("First")    << "\n";
    cout << "\nAvailable seats:\n";
    cout << "  Economy : " << f3.availableSeats("Economy")  << "\n";
    cout << "  Business: " << f3.availableSeats("Business") << "\n";
    cout << "  First   : " << f3.availableSeats("First")    << "\n";
    cout << "  Total   : " << f3.availableSeats() << "\n";
    Flight f4;
    f4.initialize("EK-202", "Dubai", "London", 400.0, 8, 3, 1);
    cout << "\n Merging f3 and f4:\n";
    Flight merged = f3 + f4;
    cout << merged;
    cout << "\n f3 minus 'First' class seats:\n";
    Flight noFirst = f3 - "First";
    cout << noFirst;
    cout << "\nf4 fare scaled by 1.2 (peak season):\n";
    Flight peakF4 = f4 * 1.2;
    cout << peakF4;
    Flight f5;
    f5.initialize("EK-202", "Dubai", "London", 400.0, 5, 2, 1);
    cout << "\n";
    cout << "f4 == f5 (same code EK-202)? "<< (f4 == f5 ? "YES (equal)" : "NO (not equal)") << "\n";
    cout << "f3 == f4 (PK-505 vs EK-202)?  "<< (f3 == f4 ? "YES (equal)" : "NO (not equal)") << "\n";
    cout << "\n";
    cout << "f3 available: " << f3.availableSeats() << "  |  f4 available: " << f4.availableSeats() << "\n";
    cout << "f3 < f4 (fewer seats available)? " << (f3 < f4 ? "YES" : "NO") << "\n";
    cout << "\n[Operator <<] Direct cout of f4:\n" << f4;
    printSeparator("PROGRAM COMPLETE");
    return 0;
}
