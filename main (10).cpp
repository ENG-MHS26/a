#include <iostream>
#include <string>
using namespace std;

class DayOfWeek {
private:
    static string days[7];
    string d_o_w;
    int ind;

public:
    // Constructor
    DayOfWeek(string day) {
        for (int i = 0; i < 7; ++i) {
            if (days[i] == day) {
                d_o_w = day;
                ind = i;
                break;
            }
        }
    }

    // Overload the prefix -- operator
    DayOfWeek& operator--() {
        ind = (ind - 1 + 7) % 7; // Move to the previous day, wrapping around if necessary
        d_o_w = days[ind];
        return *this;
    }

    // Overload the postfix ++ operator
    DayOfWeek operator++(int) {
        DayOfWeek temp = *this;
        ind = (ind + 1) % 7; // Move to the next day, wrapping around if necessary
        d_o_w = days[ind];
        return temp;
    }

    // Display the day of the week
    void display() const {
        cout << d_o_w << endl;
    }
};

// Initialize the static array of days
string DayOfWeek::days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main() {
    DayOfWeek today("Wednesday");
    today.display(); // Should display "Wednesday"

    DayOfWeek tomorrow = today++;
    tomorrow.display(); // Should display "Wednesday" (before increment)
    today.display(); // Should display "Thursday"

    DayOfWeek yesterday = --today;
    yesterday.display(); // Should display "Wednesday"
    today.display(); // Should display "Wednesday"

    return 0;
}
