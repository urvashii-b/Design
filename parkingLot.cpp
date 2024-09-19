/*
Requirements:
1. big parking lot - 10000 to 30000
2. 4 entrance and exit points
3. ticket is taken at the entrance spot
4. parking spot should be nearest to the entrance chosen
5. limit/capacity should not exceed (30000) 
6. parking spot types - motocycle, compact, large, disability
7. hourly charge
8. payment types - credit card, gpay
9. monitoring system

Objects:
1. parking lot system
2. entry/exit terminals
    i. printers
    ii. payment processor
3. parking spots
4. ticket
5. database
6. monitoring system

do not need vehicle object
parking spot types can be used instead - motocycle parking spot, compact parking spot, large parking spot, disability parking spot
(open close principle followed here)

strategy pattern for 
i. nearest parking spot - 4 min heaps for nearest distance, 2 sets for available/reserved
ii. payments

observer pattern for monitoring system

singleton pattern for parking lot system

factory pattern for instantiating all these objects

concurrency needs to be discussed - for which entry/exit

Complete Design Summary:
ParkingLot (Singleton): A single instance that manages parking spots and ensures total capacity is not exceeded.
Entry/Exit Terminals: Each terminal issues tickets and processes payments.
Parking Spots (Open/Closed Principle): Different types of spots (Motorcycle, Compact, Large, Disability) are created using factories.
Spot Allocation (Strategy Pattern): Nearest parking spot is allocated using different strategies based on the entrance.
Payments (Strategy Pattern): Handles different types of payments (Credit Card, GPay) in a flexible manner.
Monitoring System (Observer Pattern): Observes and updates on parking lot usage in real-time.
Concurrency: Ensures thread-safe operations at entry/exit points using mutexes.
*/

// singleton pattern
class ParkingLot{
private:
  static ParkingLot* instance;
  int totalSpots;
  int usedSpots;
  vector<ParkingSpot*> available;
  vector<ParkingSpot*> reserved;

  ParkingLot(int capacity): totalSpots(capacity), usedSpots(0) {}
public:
  static ParkingLot* getInstance(int capacity){
    if(!instance){
      instance = new ParkingLot(capacity);
    }
    return instance;
  }
  bool isFull(){
    return usedSpots >= totalSpots;
  }
};
ParkingLot* ParkingLot::instance = nullptr;

