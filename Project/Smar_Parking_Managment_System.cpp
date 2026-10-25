#include <iostream>
#include <string>
#include <queue>
#include<stack>
#include<vector>

using namespace std;

struct HistoryNode
{
    string message;
    HistoryNode * next;
};

HistoryNode* historyHead = nullptr;

struct ParkingSlot {
int slotNumber;
bool occupied;
string vehicleNumber;
};

int TOTAL_SLOTS = 10;
vector<ParkingSlot> slots;
queue<string> waitingQueue;
stack<string> recentOperations;

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- addRecentOperation()
// Description   :- Manages the stack of recent parking operations and keeps at most 10 records.
// DSA Topic     :- Stack (LIFO)
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void addRecentOperation(string message) {
    if (recentOperations.size() == 10) {
        stack<string> temp;

        while (recentOperations.size() > 1) {
            temp.push(recentOperations.top());
            recentOperations.pop();
        }

        recentOperations.pop();

        while (!temp.empty()) {
            recentOperations.push(temp.top());
            temp.pop();
        }
    }

    recentOperations.push(message);
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- sortParkingRecords()
// Description   :- Sorts the vehicle numbers of currently parked vehicles in ascending order.
// DSA Topic     :- Bubble Sort, Vector, Array Traversal
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void sortParkingRecords() {
    vector<string> vehicles;
    int count = 0;

    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (slots[i].occupied) {
            vehicles.push_back(slots[i].vehicleNumber);
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (vehicles[j] > vehicles[j + 1]) {
                string temp = vehicles[j];
                vehicles[j] = vehicles[j + 1];
                vehicles[j + 1] = temp;
            }
        }
    }

    cout << "\n===== SORTED VEHICLE RECORDS =====\n";

    if (count == 0) {
        cout << "No vehicles are currently parked.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << vehicles[i] << endl;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- displayParkingStatistics()
// Description   :- Displays total, occupied, and available parking slots and waiting vehicle count.
// DSA Topic     :- Array Traversal, Queue
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void displayParkingStatistics() {
    int occupied = 0;
    int available = 0;

    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (slots[i].occupied) {
            occupied++;
        } else {
            available++;
        }
    }

    cout << "\n===== PARKING STATISTICS =====\n";
    cout << "Total Parking Slots: " << TOTAL_SLOTS << endl;
    cout << "Occupied Slots: " << occupied << endl;
    cout << "Available Slots: " << available << endl;
    cout << "Waiting Vehicles: "
         << waitingQueue.size() << endl;
}
//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- calculateParkingFees()
// Description   :- Calculates and displays parking fees for a currently parked vehicle.
// DSA Topic     :- Linear Search, Arithmetic Operations
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void calculateParkingFees() {
    string vehicle;
    int hours;

    cout << "Enter vehicle number: ";
    cin >> vehicle;

    bool found = false;

    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (slots[i].occupied &&
            slots[i].vehicleNumber == vehicle) {
            
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Vehicle is not currently parked!\n";
        return;
    }

    cout << "Enter parking duration in hours: ";
    cin >> hours;

    if (hours <= 0) {
        cout << "Please enter valid parking hours!\n";
        return;
    }

    const int RATE_PER_HOUR = 20;
    int totalFees = hours * RATE_PER_HOUR;

    cout << "\n===== PARKING FEE RECEIPT =====\n";
    cout << "Vehicle Number: " << vehicle << endl;
    cout << "Parking Duration: " << hours << " hour(s)\n";
    cout << "Rate Per Hour: Rs. " << RATE_PER_HOUR << endl;
    cout << "Total Parking Fees: Rs. " << totalFees << endl;
}
//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- displayRecentOperations()
// Description   :- Displays recent parking operations without changing the original stack.
// DSA Topic     :- Stack (LIFO)
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void displayRecentOperations() {
    if (recentOperations.empty()) {
        cout << "\nNo recent operations available.\n";
        return;
    }

    stack<string> temp = recentOperations;
    int count = 1;

    cout << "\n===== RECENT PARKING OPERATIONS =====\n";

    while (!temp.empty()) {
        cout << count << ". " << temp.top() << endl;
        temp.pop();
        count++;
    }
}
//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- initializeSlots()
// Description   :- Initializes all parking slots as available and clears their vehicle numbers.
// DSA Topic     :- Vector, Array Initialization
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void initializeSlots() 
{
    slots.resize(TOTAL_SLOTS);
for (int i = 0; i < TOTAL_SLOTS; i++) {
slots[i].slotNumber = i + 1;
slots[i].occupied = false;
slots[i].vehicleNumber = "";
}
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- addHistory()
// Description   :- Adds a parking operation message to the end of the linked-list history.
// DSA Topic     :- Singly Linked List
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void addHistory(string message) {
    HistoryNode* newNode = new HistoryNode;

    newNode->message = message;
    newNode->next = nullptr;

    if (historyHead == nullptr) {
        historyHead = newNode;
    } else {
        HistoryNode* temp = historyHead;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- displayHistory()
// Description   :- Displays all parking history records stored in the linked list.
// DSA Topic     :- Singly Linked List Traversal
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void displayHistory() {
    HistoryNode* temp = historyHead;
    int count = 1;

    cout << "\n===== PARKING HISTORY =====\n";

    if (temp == nullptr) {
        cout << "No parking history available.\n";
        return;
    }

    while (temp != nullptr) {
        cout << count << ". " << temp->message << endl;
        temp = temp->next;
        count++;
    }

    cout << "Total Operations: " << count - 1 << endl;
}
//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- isParked()
// Description   :- Checks whether a given vehicle is currently parked in any slot.
// DSA Topic     :- Linear Search, Vector
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
bool isParked(string vehicle) {
for (int i = 0; i < TOTAL_SLOTS; i++) {
if (slots[i].occupied &&
slots[i].vehicleNumber == vehicle) {
return true;
}
}
return false;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- isWaiting()
// Description   :- Checks whether a given vehicle exists in the waiting queue.
// DSA Topic     :- Queue (FIFO), Queue Traversal
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
bool isWaiting(string vehicle) {
queue<string> temp = waitingQueue;

while (!temp.empty()) {
    if (temp.front() == vehicle) {
        return true;
    }
    temp.pop();
}

return false;

}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- findAvailableSlot()
// Description   :- Finds and returns the index of the first available parking slot.
// DSA Topic     :- Linear Search, Vector
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
int findAvailableSlot() {
for (int i = 0; i < TOTAL_SLOTS; i++) {
if (!slots[i].occupied) {
return i;
}
}
return -1;
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- displaySlots()
// Description   :- Displays the status of every parking slot and its vehicle, if occupied.
// DSA Topic     :- Array/Vector Traversal
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void displaySlots() {
cout << "\n----- PARKING SLOT STATUS -----\n";

for (int i = 0; i < TOTAL_SLOTS; i++) {
    cout << "Slot " << slots[i].slotNumber << " : ";

    if (slots[i].occupied) {
        cout << "Occupied by "
             << slots[i].vehicleNumber;
    } else {
        cout << "Available";
    }

    cout << endl;
}

}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- displayAvailableSlots()
// Description   :- Displays all available parking slots and counts them.
// DSA Topic     :- Array/Vector Traversal, Counting
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void displayAvailableSlots() {
    int count = 0;

    cout << "\n----- AVAILABLE PARKING SLOTS -----\n";

    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (!slots[i].occupied) {
            cout << "Slot "
                 << slots[i].slotNumber
                 << ": Available" << endl;

            count++;
        }
    }

    if (count == 0) {
        cout << "No parking slots available!\n";
    }

    cout << "\nTotal Available Slots: "
         << count << endl;
}
//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- searchVehicle()
// Description   :- Searches for a vehicle in the parking slots and checks whether it is waiting.
// DSA Topic     :- Linear Search, Queue
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void searchVehicle() {
    string vehicle;

    cout << "Enter vehicle number to search: ";
    cin >> vehicle;

    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (slots[i].occupied &&
            slots[i].vehicleNumber == vehicle) {

            cout << "\nVehicle found!\n";
            cout << "Vehicle Number: "
                 << slots[i].vehicleNumber << endl;
            cout << "Parking Slot: "
                 << slots[i].slotNumber << endl;

            return;
        }
    }

    cout << "\nVehicle is not currently parked.\n";

    if (isWaiting(vehicle)) {
        cout << "This vehicle is in the waiting queue.\n";
    }
}
//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- allocateSlot()
// Description   :- Allocates an available parking slot or adds the vehicle to the waiting queue.
// DSA Topic     :- Queue (FIFO), Linear Search, Vector
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void allocateSlot() {
string vehicle;

cout << "Enter vehicle number: ";
cin >> vehicle;

if (vehicle.empty()) {
    cout << "Vehicle number cannot be empty!\n";
    return;
}

if (isParked(vehicle) || isWaiting(vehicle)) {
    cout << "Vehicle is already registered!\n";
    return;
}

int index = findAvailableSlot();

if (index != -1) {
    slots[index].occupied = true;
    slots[index].vehicleNumber = vehicle;
    addHistory("Vechicle " + vehicle + " parked in slot " + to_string(slots[index].slotNumber));
    cout << "\nParking allocated successfully!\n";
    addRecentOperation("Vechile " + vehicle + " parked in Slot "+ to_string(slots[index].slotNumber));
    cout << "Vehicle: " << vehicle << endl;
    cout << "Slot: " << slots[index].slotNumber << endl;
} else {
    waitingQueue.push(vehicle);

    cout << "\nParking is full!\n";
    cout << "Vehicle added to waiting queue.\n";
    cout << "Queue position: "
         << waitingQueue.size() << endl;
}

}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- displayWaitingQueue()
// Description   :- Displays waiting vehicles in their first-in, first-out order.
// DSA Topic     :- Queue (FIFO)
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void displayWaitingQueue() {
if (waitingQueue.empty()) {
cout << "\nWaiting queue is empty.\n";
return;
}

queue<string> temp = waitingQueue;

cout << "\n----- WAITING QUEUE (FIFO) -----\n";

int position = 1;

while (!temp.empty()) {
    cout << position << ". " << temp.front() << endl;
    temp.pop();
    position++;
}

}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- releaseSlot()
// Description   :- Releases a vehicle's parking slot and allocates it to the next waiting vehicle.
// DSA Topic     :- Queue (FIFO), Linear Search, Vector
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
void releaseSlot() {
string vehicle;

cout << "Enter vehicle number to release: ";
cin >> vehicle;

for (int i = 0; i < TOTAL_SLOTS; i++) {
    if (slots[i].occupied &&
    slots[i].vehicleNumber == vehicle) {

    int releasedSlot = slots[i].slotNumber;

    slots[i].occupied = false;
    slots[i].vehicleNumber = "";

    addRecentOperation(
        "Vehicle " + vehicle + " released from Slot " + to_string(releasedSlot));

        cout << "\nParking slot released: "
             << slots[i].slotNumber << endl;

        if (!waitingQueue.empty()) {
            string nextVehicle = waitingQueue.front();
            waitingQueue.pop();

            slots[i].occupied = true;
            slots[i].vehicleNumber = nextVehicle;

            cout << "Next waiting vehicle allocated!\n";
            cout << "Vehicle: " << nextVehicle << endl;
            cout << "Slot: " << slots[i].slotNumber << endl;
        }

        return;
    }
}

cout << "Vehicle not found in parking slots!\n";

}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Function Name :- main()
// Description   :- Runs the Smart Parking Management System menu and processes user choices.
// DSA Topic     :- Menu-Driven Program, Functions, Switch, DSA Integration
// Author        :- Vaibhav Ravindra Gade
// Date          :- 25/10/2026
//
//////////////////////////////////////////////////////////////////////////////////////
int main() {
    int totalSlots;

    cout << "Enter total number of parking slots: ";
    cin >> totalSlots;

    if (totalSlots <= 0) {
        cout << "Please enter a valid number of slots!\n";
        return 1;
    }

    TOTAL_SLOTS = totalSlots;
    initializeSlots();

    cout << "Parking system initialized with "
         << TOTAL_SLOTS << " slots!\n";

    int choice;

do {
    cout << "\n====================================\n";
    cout << " SMART PARKING MANAGEMENT SYSTEM\n";
    cout << "====================================\n";
    cout << "1. Allocate Parking Slot\n";
    cout << "2. View Parking Slots\n";
    cout << "3. Release Parking Slot\n";
    cout << "4. View Waiting Queue\n";
    cout << "5. Search Vehicle\n";
    cout << "6. View Avaiable Slots\n";
    cout << "7. View Parking History\n";
    cout << "8. View Recent Operations\n";
    cout << "9. Sort Parking Recordes\n";
    cout << "10. View Parking Statistics\n";
    cout << "11 Calculate Parking Fees\n";
    cout << "11. Exit\n";
    cout << "Enter your choice: ";

    if (!(cin >> choice)) {
        cout << "Invalid input!\n";
        return 1;
    }

    switch (choice) {
        case 1:
            allocateSlot();
            break;

        case 2:
            displaySlots();
            break;

        case 3:
            releaseSlot();
            break;

        case 4:
            displayWaitingQueue();
            break;

         case 5:
             searchVehicle();
             break; 
        case 6:
             displayAvailableSlots();
             break;   
        case 7:
                displayHistory();
                break;    
        case 8:
              displayRecentOperations();
              break; 
        case 9:
              sortParkingRecords();
              break;  
        case 10:
             displayParkingStatistics();
             break;  
        case 11:
              calculateParkingFees();
              break;             
        case 12:
            cout << "Thank you for using Smart Parking!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
    }

} while (choice != 12);

return 0;

}