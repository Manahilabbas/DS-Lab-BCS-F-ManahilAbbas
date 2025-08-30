//  Create a dynamic program to store temperature readings of a city for n days and m different times in a day
// using a 2D array.
// => Calculate the daily average temperature.
// => Find the hottest and coldest day.
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter number of readings per day: ";
    cin >> m;

    int **temps = new int*[n];
    for (int i = 0; i < n; i++) {
        temps[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        cout << "\nEnter readings for Day " << i + 1 << ":\n";
        for (int j = 0; j < m; j++) {
            cout << "  Reading " << j + 1 << ": ";
            cin >> temps[i][j];
        }
    }

    float *avg = new float[n];

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += temps[i][j];
        }
        avg[i] = sum / m;
    }

    int hottestDay = 0, coldestDay = 0;
    for (int i = 1; i < n; i++) {
        if (avg[i] > avg[hottestDay]) hottestDay = i;
        if (avg[i] < avg[coldestDay]) coldestDay = i;
    }

    cout << " Results ";
    for (int i = 0; i < n; i++) {
        cout << "Day " << i + 1 << " Average Temperature: " << avg[i] << endl;
    }
    cout << "Hottest Day: Day " << hottestDay + 1 << " (Avg Temp: " << avg[hottestDay] << ")" << endl;
    cout << "Coldest Day: Day " << coldestDay + 1 << " (Avg Temp: " << avg[coldestDay] << ")" << endl;

    for (int i = 0; i < n; i++) {
        delete[] temps[i];
    }
    delete[] temps;
    delete[] avg;

    return 0;
}
