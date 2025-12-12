#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Country {
    string name;
    double population;
    double area;
};

double calculateDensity(double population, double area) {
    if (area == 0) {
        return 0;
    }
    return population / area;
}

int main() {
    int N;

    cout << "Enter number of countries: ";
    cin >> N;

    Country countries[100];

    for (int i = 0; i < N; i++) {
        cout << "\nCountry " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, countries[i].name);
        cout << "Population (in millions): ";
        cin >> countries[i].population;
        cout << "Area (in thousand km^2): ";
        cin >> countries[i].area;
    }

    int minIndex = 0;
    double minDensity = calculateDensity(countries[0].population, countries[0].area);

    for (int i = 1; i < N; i++) {
        double currentDensity = calculateDensity(countries[i].population, countries[i].area);

        if (currentDensity < minDensity) {
            minDensity = currentDensity;
            minIndex = i;
        }
    }

    cout << "Results:" << endl;

    cout << fixed << setprecision(2);
    for (int i = 0; i < N; i++) {
        double density = calculateDensity(countries[i].population, countries[i].area);
        cout << countries[i].name << ": ";
        cout << "population=" << countries[i].population << " mln, ";
        cout << "area=" << countries[i].area << " thousand km^2, ";
        cout << "density=" << density << " mln/thousand km^2" << endl;
    }

    cout << "\nCountry with the lowest population density:" << endl;
    cout << countries[minIndex].name << endl;
    cout << "Density: " << minDensity << " mln/thousand km^2" << endl;

    return 0;
}
