#include <iostream>
#include <istream>

using namespace std;
double sum (double a) {
    double count = 0;
    int n = 1;
    cin >> a;
    while (count < a) {
        count +=1.0/n;
        n++;
    }
    cout <<"n="<< n <<endl;
    return count;
}
int main() {
    double a;
    cin >> a;
    cout << sum(a) << endl;
    return 0;
}

