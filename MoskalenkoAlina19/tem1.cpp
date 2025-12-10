#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void inputData(int &customerCount, vector<double> &serviceTime) {
    cout << "Enter number of customers: ";
    cin >> customerCount;

    if (customerCount <= 0) {
        cout << "Error! There must be at least 1 customer." << endl;
        customerCount = 1;
    }

    serviceTime.resize(customerCount);

    cout << "\nEnter service time for each customer (in minutes):" << endl;
    for (int i = 0; i < customerCount; i++) {
        cout << "Customer " << (i + 1) << ": ";
        cin >> serviceTime[i];
    }
    cout << endl;
}

void calculateTime(int count, const vector<double> &service,
                   vector<double> &timeInSystem, vector<double> &arrival,
                   vector<double> &start, vector<double> &finish) {
    double currentTime = 0;

    for (int i = 0; i < count; i++) {
        arrival[i] = i;

        if (arrival[i] < currentTime) {
            start[i] = currentTime;
        } else {
            start[i] = arrival[i];
        }

        finish[i] = start[i] + service[i];
        timeInSystem[i] = finish[i] - arrival[i];
        currentTime = finish[i];
    }
}

int findSmallestServiceTime(const vector<double> &service) {
    int index = 0;
    double smallest = service[0];

    for (int i = 1; i < service.size(); i++) {
        if (service[i] < smallest) {
            smallest = service[i];
            index = i;
        }
    }
    return index;
}

int findLongestTimeInSystem(const vector<double> &timeInSystem) {
    int index = 0;
    double longest = timeInSystem[0];

    for (int i = 1; i < timeInSystem.size(); i++) {
        if (timeInSystem[i] > longest) {
            longest = timeInSystem[i];
            index = i;
        }
    }
    return index;
}

void printTable(int count, const vector<double> &service,
                const vector<double> &timeInSystem, const vector<double> &arrival,
                const vector<double> &start, const vector<double> &finish) {
    cout << " RESULTS" << endl;

    cout << left << setw(10) << "Customer"
         << setw(15) << "Arrived at"
         << setw(20) << "Service start"
         << setw(20) << "Service time"
         << setw(20) << "Time in system" << endl;


    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << (i + 1)
             << setw(15) << fixed << setprecision(2) << arrival[i]
             << setw(20) << start[i]
             << setw(20) << service[i]
             << setw(20) << timeInSystem[i] << endl;
    }

}

void printSummary(int count, const vector<double> &service,
                  const vector<double> &timeInSystem, int minIndex, int maxIndex) {
    cout << "SUMMARY" << endl;

    cout << "1. The shortest service time: customer #" << (minIndex + 1) << endl;
    cout << "   Service time: " << service[minIndex] << " minutes" << endl << endl;

    cout << "2. The longest time in system: customer #" << (maxIndex + 1) << endl;
    cout << "   Time: " << timeInSystem[maxIndex] << " minutes" << endl << endl;

    double totalService = 0, totalSystem = 0;
    for (int i = 0; i < count; i++) {
        totalService += service[i];
        totalSystem += timeInSystem[i];
    }

    cout << "3. Average service time: " 
         << fixed << setprecision(2) << (totalService / count) << " minutes" << endl;
    cout << "4. Average time in system: " 
         << (totalSystem / count) << " minutes" << endl;

}

int main() {
    int n;
    vector<double> service;
    vector<double> timeInSystem;
    vector<double> arrival;
    vector<double> start;
    vector<double> finish;

    int minIndex;
    int maxIndex;

    inputData(n, service);

    timeInSystem.resize(n);
    arrival.resize(n);
    start.resize(n);
    finish.resize(n);

    calculateTime(n, service, timeInSystem, arrival, start, finish);

    minIndex = findSmallestServiceTime(service);
    maxIndex = findLongestTimeInSystem(timeInSystem);

    printTable(n, service, timeInSystem, arrival, start, finish);

    printSummary(n, service, timeInSystem, minIndex, maxIndex);

    cout << "  PROGRAM COMPLETED SUCCESSFULLY!" << endl;

    cout << "\nAdditional info: " << endl;
    cout << "The last customer finishes service at minute " 
         << finish[n - 1] << endl;

    return 0;
}
