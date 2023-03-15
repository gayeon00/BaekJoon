#include <iostream>

using namespace std;

int beforeHour, beforeMinute;
int afterHour, afterMinute;

void read_data();
void solve();
void print_data();

int main() {
    read_data();
    solve();
    print_data();
}

void read_data() {
    cin >> beforeHour >> beforeMinute;
}

//void solve() {
//    if (beforeMinute - 45 < 0) {
//        if (beforeHour - 1 < 0) afterHour = 23;
//        else afterHour = beforeHour - 1;
//
//        afterMinute = beforeMinute + 60 - 45;
//    } else {
//        afterMinute = beforeMinute - 45;
//        afterHour = beforeHour;
//    }
//}

void solve() {
    afterMinute = beforeMinute - 45;
    afterHour = beforeHour;
    if (afterMinute < 0) {
        afterMinute += 60;
        afterHour -= 1;

        if (afterHour < 0) afterHour = 23;
    }
}
void print_data() {
    cout << afterHour << " " << afterMinute;
}
