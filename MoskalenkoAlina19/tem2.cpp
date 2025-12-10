#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<double> inputVector(int d) {
    vector<double> vec(d);
    cout << "  Enter " << d << " coordinate(s): ";
    for (int i = 0; i < d; i++) {
        cin >> vec[i];
    }
    return vec;
}

double computeNorm(const vector<double>& vec) {
    double sumSq = 0.0;
    for (double x : vec) sumSq += x * x;
    return sqrt(sumSq);
}

void printVector(const vector<double>& vec) {
    cout << "(";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << ")";
}

int main() {
    int d, n;
    double sumNorms = 0.0;

    cout << "          VECTOR PROCESSING PROGRAM\n";

    cout << "Enter vector dimension (d): ";
    cin >> d;

    if (d <= 0) {
        cout << "Error! Dimension must be positive.\n";
        return 1;
    }

    cout << "Enter number of vectors (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Error! Number of vectors must be positive.\n";
        return 1;
    }

    vector<vector<double>> vectors(n, vector<double>(d));

    cout << " VECTOR INPUT\n";

    for (int i = 0; i < n; i++) {
        cout << "\nVector " << (i + 1) << ":\n";
        vectors[i] = inputVector(d);
    }

    cout << " RESULTS\n";

    cout << "\nVectors and their norms:\n";

    for (int i = 0; i < n; i++) {
        double norm = computeNorm(vectors[i]);
        sumNorms += norm;

        cout << "Vector " << (i + 1) << ": ";
        printVector(vectors[i]);
        cout << "   Norm: " << fixed << setprecision(4) << norm << endl;
    }

    cout << "Sum of norms of all " << n << " vectors: " << sumNorms << endl;
    cout << "Average norm value: " << (sumNorms / n) << endl;
    if (n > 0) {
        int idxMax = 0, idxMin = 0;
        double maxNorm = computeNorm(vectors[0]);
        double minNorm = maxNorm;

        for (int i = 1; i < n; i++) {
            double norm = computeNorm(vectors[i]);
            if (norm > maxNorm) {
                maxNorm = norm;
                idxMax = i;
            }
            if (norm < minNorm) {
                minNorm = norm;
                idxMin = i;
            }
        }

        cout << "\nAdditional info:\n";
        cout << "Largest norm: " << maxNorm << " (vector " << (idxMax + 1) << ")\n";
        cout << "Smallest norm: " << minNorm << " (vector " << (idxMin + 1) << ")\n";
    }

    return 0;
}
