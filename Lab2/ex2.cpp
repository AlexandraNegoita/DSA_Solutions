#include <iostream>

using namespace std;

// Write a structure to represent dates and write functions for:
//      Verifying if a date is valid
//      Calculating the next date (tomorrow) of a certain date
//      Calculating the previous date (yesterday) of a certain date
//Test the functions.

struct date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
}today;

int calculate_days(date d) {
    int limit_days = 0;
    switch(d.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            limit_days = 31;
            break;
        case 2:
            if((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
               limit_days = 29;
               break;
            }
            limit_days = 28;
            break;

        default:
            limit_days = 30;
            break;
        }

    return limit_days;
}

bool is_date_valid(date d) {
    if(d.month >= 1 && d.month <= 12) {
        int limit_days = calculate_days(d);
        if(d.day >= 1 && d.day <= limit_days){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

date tomorrow(date d) {
    int limit_days = calculate_days(d);
    if(is_date_valid(d)) {
        if(d.day + 1 > limit_days){
            if(d.month == 12) {
                d.year += 1;
                d.month = 1;
            } else {
                d.month += 1;
            }
            d.day = 1;
        } else {
            d.day += 1;
        }
    }
    return d;
}

date yesterday(date d) {
    if(is_date_valid(d)) {
        if(d.day == 1){
            if(d.month == 1) {
                d.year -= 1;
                d.month = 12;
            } else {
                d.month -= 1;
            }
            int limit_days = calculate_days(d);
            d.day = limit_days;
        } else {
            d.day -= 1;
        }
    }
    return d;
}


int main()
{
    cout << "Enter a date: \n";
    cout << "\tDay: "; cin >> today.day;
    cout << "\tMonth: "; cin >> today.month;
    cout << "\tYear: "; cin >> today.year;
    if(is_date_valid(today)) {
        cout << "Valid date!\n";

        date t = tomorrow(today);
        cout << "Tomorrow is: " << t.day << "." << t.month << "." << t.year << endl;

        date y = yesterday(today);
        cout << "Yesterday was: " << y.day << "." << y.month << "." << y.year << endl;
    } else {
        cout << "Invalid date\n";
    }

    return 0;
}
