#include <iostream>

using namespace std;

int now_hour, now_minute;
int time_take;
int finish_hour, finish_minute;

void read_data();
void solve();
void print_data();

int main() {
    read_data();
    solve();
    print_data();
}

void read_data() {
    cin >> now_hour >> now_minute >> time_take;
}

void solve() {
    finish_hour = ((time_take + now_minute) / 60 + now_hour) % 24;
    finish_minute = (time_take + now_minute) % 60;
}
void print_data() {
    cout << finish_hour << " " << finish_minute;
}
