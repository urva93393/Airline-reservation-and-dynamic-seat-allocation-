========================================================
  README – Airline Reservation & Dynamic Seat Allocation
========================================================

Student Name  : urva
Roll Number   : 32
Topic         : Airline Reservation & Dynamic Seat Allocation Library

Description:
  This C++ library (AirlineReservation.h) models a flight reservation
  system with dynamic seat allocation across Economy, Business, and
  First-class categories. It demonstrates function overloading through
  three versions of initialize() and operator overloading for merging
  flights (+), removing a seat class (-), scaling fares (*), equality
  check (==), seat availability comparison (<), and formatted output (<<).

Files:
  AirlineReservation.h  – Class definition and full implementation
  main.cpp              – Demonstrates all overloaded functions/operators
 

 SAMPLE OUTPUT
===FUNCTION OVERLOADING===

Flight   : UNKNOWN
Route    : N/A to N/A
Base Fare: $0.00
Seats    : 0 total | 0 available

Flight   : PK-303
Route    : Karachi to Lahore
Base Fare: $150.00
Seats    : 0 total | 0 available

Flight   : PK-505
Route    : Islamabad to Dubai
Base Fare: $250.00
Seats    : 16 total | 16 available

===seat booking& allocation====
Seats 1, 2, 3, 7 booked successfully.
Auto-allocated Business seat #4 to Hasan Sheikh.
Error: Seat already booked.
Seat 7 booking cancelled.

--- Seat Manifest: PK-505 ---
Seat#   Class       Status    Passenger
--------------------------------------------------
1       First       Booked    Ali Khan
2       First       Booked    Sara Ahmed
3       Business    Booked    Omar Raza
4       Business    Booked    Hasan Sheikh
5       Business    Free      -
6       Business    Free      -
7       Economy     Free      -
8       Economy     Free      -
9       Economy     Free      -
10      Economy     Free      -
11      Economy     Free      -
12      Economy     Free      -
13      Economy     Free      -
14      Economy     Free      -
15      Economy     Free      -
16      Economy     Free      -

 ==== fair information ====
Economy  fare: $250.00
Business fare: $625.00
First    fare: $1000.00

Available seats:
  Economy : 10
  Business: 2
  First   : 0
  Total   : 12

 Merging f3 and f4:
Flight   : PK-505+EK-202
Route    : Islamabad to London
Base Fare: $325.00
Seats    : 28 total | 24 available

 f3 minus 'First' class seats:
Flight   : PK-505
Route    : Islamabad to Dubai
Base Fare: $250.00
Seats    : 14 total | 12 available

f4 fare scaled by 1.2 (peak season):
Flight   : EK-202
Route    : Dubai to London
Base Fare: $480.00
Seats    : 12 total | 12 available

f4 == f5 (same code EK-202)? YES (equal)
f3 == f4 (PK-505 vs EK-202)?  NO (not equal)

f3 available: 12  |  f4 available: 12
f3 < f4 (fewer seats available)? NO

[Operator <<] Direct cout of f4:
Flight   : EK-202
Route    : Dubai to London
Base Fare: $400.00
Seats    : 12 total | 12 available

=======================================================
  PROGRAM COMPLETE
=======================================================

C:\Users\DELL\OneDrive\Desktop\task and asignments\airline\x64\Debug\airline.exe (process 19416) exited with code 0 (0x0).
Press any key to close this window . . .