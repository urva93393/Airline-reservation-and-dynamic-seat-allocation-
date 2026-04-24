#ifndef AIRLINE_RESERVATION_H
#define AIRLINE_RESERVATION_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Seat {
public:
    int    seatNumber;
    string seatClass;   // "Economy", "Business", "First"
    bool   isBooked;
    string passengerName;

    Seat() : seatNumber(0), seatClass("Economy"), isBooked(false), passengerName("") {}

    Seat(int num, const string& cls)
        : seatNumber(num), seatClass(cls), isBooked(false), passengerName("") {}
};


class Flight {
private:
    string  flightCode;
    string  origin;
    string  destination;
    double  baseFare;        
    vector<Seat>   seats;
    int totalSeats;

    // Helper – find seat index by number (-1 if not found)
    int findSeatIndex(int seatNum) const {
        for (int i = 0; i < (int)seats.size(); i++) {
            if (seats[i].seatNumber == seatNum) return i;
        }
        return -1;
    }

    // Helper – fare multiplier per class
    double fareMultiplier(const string& cls) const {
        if (cls == "Business") return 2.5;
        if (cls == "First")    return 4.0;
        return 1.0; // Economy
    }

public:
    void initialize() {
        flightCode  = "UNKNOWN";
        origin      = "N/A";
        destination = "N/A";
        baseFare    = 0.0;
        totalSeats  = 0;
        seats.clear();
    }
    void initialize(const string& code, const string& org,
                    const string& dest, double fare) {
        flightCode  = code;
        origin      = org;
        destination = dest;
        baseFare    = fare;
        totalSeats  = 0;
        seats.clear();
    }
    void initialize(const string& code, const string& org, const string& dest, double fare,int econSeats, int busSeats, int firstSeats) {
        flightCode  = code;
        origin      = org;
        destination = dest;
        baseFare    = fare;
        seats.clear();
        int seatNum = 1;
        for (int i = 0; i < firstSeats;  i++) seats.push_back(Seat(seatNum++, "First"));
        for (int i = 0; i < busSeats;    i++) seats.push_back(Seat(seatNum++, "Business"));
        for (int i = 0; i < econSeats;   i++) seats.push_back(Seat(seatNum++, "Economy"));
        totalSeats = (int)seats.size();
    }
    bool bookSeat(int seatNum, const string& passengerName) {
        int idx = findSeatIndex(seatNum);
        if (idx == -1) {
            cout << "Error: Seat not found.\n";
            return false;
        }
        if (seats[idx].isBooked) {
            cout << "Error: Seat already booked.\n";
            return false;
        }
        seats[idx].isBooked = true;
        seats[idx].passengerName = passengerName;
        return true;
    }
    bool cancelSeat(int seatNum) {
        int idx = findSeatIndex(seatNum);
        if (idx == -1) {
            cout << "Error: Seat not found.\n";
            return false;
        }
        if (!seats[idx].isBooked) {
            cout << "Error: Seat not booked.\n";
            return false;
        }
        seats[idx].isBooked = false;
        seats[idx].passengerName = "";
        return true;
    }
    int allocateSeat(const string& cls, const string& passengerName) {
        for (auto& s : seats) {
            if (s.seatClass == cls && !s.isBooked) {
                s.isBooked = true;
                s.passengerName = passengerName;
                return s.seatNumber;
            }
        }
        cout << "Error: No available seats in class: " << cls << "\n";
        return -1;
    }
    double getFare(const string& cls) const {
        return baseFare * fareMultiplier(cls);
    }
    int availableSeats(const string& cls = "") const {
        int count = 0;
        for (const auto& s : seats) {
            if (!s.isBooked && (cls.empty() || s.seatClass == cls))
                count++;
        }
        return count;
    }
    string getFlightCode()  const { return flightCode;  }
    string getOrigin()      const { return origin;      }
    string getDestination() const { return destination; }
    double getBaseFare()    const { return baseFare;    }
    int    getTotalSeats()  const { return totalSeats;  }
    void displayManifest() const {
        cout << "\n--- Seat Manifest: " << flightCode << " ---\n";
        cout << left;
        cout << setw(8) << "Seat#"
            << setw(12) << "Class"
            << setw(10) << "Status"
            << "Passenger\n";
        cout << string(50, '-') << "\n";
        for (const auto& s : seats) {
            cout << setw(8) << s.seatNumber
                << setw(12) << s.seatClass
                << setw(10) << (s.isBooked ? "Booked" : "Free")
                << (s.isBooked ? s.passengerName : "-") << "\n";
        }
    }
    Flight operator+(const Flight& other) const {
        Flight merged;
        merged.initialize(
            flightCode + "+" + other.flightCode,
            origin, other.destination,
            (baseFare + other.baseFare) / 2.0
        );
        merged.seats      = seats;
        for (const auto& s : other.seats) merged.seats.push_back(s);
        merged.totalSeats = (int)merged.seats.size();
        return merged;
    }
    Flight operator-(const string& cls) const {
        Flight result;
        result.initialize(flightCode, origin, destination, baseFare);
        for (const auto& s : seats) {
            if (s.seatClass != cls) result.seats.push_back(s);
        }
        result.totalSeats = (int)result.seats.size();
        return result;
    }
    Flight operator*(double multiplier) const {
        Flight result = *this;
        result.baseFare = baseFare * multiplier;
        return result;
    }
    bool operator==(const Flight& other) const {
        return flightCode == other.flightCode;
    }
    bool operator<(const Flight& other) const {
        return availableSeats() < other.availableSeats();
    }

   
    friend ostream& operator<<(ostream& os, const Flight& f) {
        os << "Flight   : " << f.flightCode  << "\n"
           << "Route    : " << f.origin << " to " << f.destination << "\n"
           << "Base Fare: $" << fixed << setprecision(2) << f.baseFare << "\n"
           << "Seats    : " << f.totalSeats  << " total | "
           << f.availableSeats() << " available\n";
        return os;
    }
};

#include <iomanip>   // for setw / setprecision used above

#endif // AIRLINE_RESERVATION_H
