#include <iostream>
#include "Timestamp.h"

int main() {
    Timestamp time1(10, 30, 45);
    Timestamp time2(2, 15, 20);

    std::cout << "Time 1: ";
    time1.printTime();
    std::cout << "Time 2: ";
    time2.printTime();

    std::cout << "\nAdding the timestamps:\n";
    Timestamp* sumTime = time1.addTimestamps(time2);
    std::cout << "Sum of Time 1 and Time 2: ";
    sumTime->printTime();

    delete sumTime;

    return 0;
}
