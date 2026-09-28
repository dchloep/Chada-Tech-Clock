/*
* Chloe Padilla
* CS 210
* Project One - Chada Tech Clocks
* Displays time in 12-hour and 24-hour formats
*	and allows users to adjust the time.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Function declarations allows main() to call the functions below.
void getInitialTime(int& hour, int& minute, int& second);
void displayMenu();
void displayTime(int hour, int minute, int second);
void addHour(int& hour);
void addMinute(int& hour, int& minute);
void addSecond(int& hour, int& minute, int& second);

int main() {

	//Variables used to store the user's starting time.
	int hour;
	int minute;
	int second;

	//Variable used to store the user's menu selection.
	int choice = 0;

	//Get the initial time from the user.
	getInitialTime(hour, minute, second);

	//Display the starting time on both clocks.
	displayTime(hour, minute, second);

	//Continue showing the menu until the user selects option 4.
	while (choice != 4) {

		//Display the available menu options.
		displayMenu();

		//Get the user's menu option.
		cin >> choice;

		//Add one hour is the user selects option 1.
		if (choice == 1) {
			addHour(hour);

			//Display the updated time on both clocks.
			displayTime(hour, minute, second);
		}

		//Add one minute if the user selects option 2.
		else if (choice == 2) {
			addMinute(hour, minute);

			//Display the updated time on both clocks.
			displayTime(hour, minute, second);
		}

		//Add one second if the user selects option 3.
		else if (choice == 3) {
			addSecond(hour, minute, second);


			//Display the updated time on both clocks.
			displayTime(hour, minute, second);
		}

		//Exit the program if the user selects option 4.
		else if (choice == 4) {
			cout << "Exiting program." << endl;
		}

		//Display an error message for an invlaid menu selection.
		else {
			cout << "Invalid selection. Please choose 1-4." << endl;
		}
	}

	//Return 0 to show that the program ended successfully.
	return 0;
}

//Gets the starting hour, minute, and second from the user.
void getInitialTime(int& hour, int& minute, int& second) {

	//Ask the user to enter the starting hour in 24-hour format.
	cout << "Enter the starting hour (0-23): ";
	cin >> hour;

	//Ask the user for the starting minute.
	cout << "Enter the starting minute (0-59): ";
	cin >> minute;

	//Ask the user for the starting second.
	cout << "Enter the starting second (0-59): ";
	cin >> second;
}

//Display the current time in both 12-hour and 24-hour formats.
void displayTime(int hour, int minute, int second) {

	//Create a separate hour variable for the 12-hour clock.
	int hour12 = hour;

	//The clock begins by assuming the time is AM.
	string amPm = "AM";

	//Hours of 12 or greater are in the PM portion of the day.
	if (hour >= 12) {
		amPm = "PM";
	}

	//Midnight is displayed as 12 instead of 0 on a 12-hour clock.
	if (hour12 == 0) {
		hour12 = 12;
	}

	//Convert hours greater than 12 to 12-hour format.
	else if (hour12 > 12) {
		hour12 = hour12 - 12;
	}

	//Display the top borders and names of both clocks.
	cout << "***************************   ***************************" << endl;
	cout << "*      12-Hour Clock      *   *      24-Hour Clock      *" << endl;

	//Display the time on both clocks.
	//setfill('0') and setw(2) make each number display with two digits.
	cout << "*       "
		<< setfill('0') << setw(2) << hour12 << ":"
		<< setw(2) << minute << ":"
		<< setw(2) << second << " " << amPm
		<< "       *   *        "
		<< setw(2) << hour << ":"
		<< setw(2) << minute << ":"
		<< setw(2) << second
		<< "         *" << endl;

	//Display the bottom borders of both clocks.
	cout << "***************************   ***************************" << endl;

	//Change the fill character back to a space for a later output.
	cout << setfill(' ');
}

//Displays the available clock adjustments and exit option.
void displayMenu() {

	//Display the four menu options available to the user.
	cout << "***************************" << endl;
	cout << "* 1 - Add One Hour        *" << endl;
	cout << "* 2 - Add One Minute      *" << endl;
	cout << "* 3 - Add One Second      *" << endl;
	cout << "* 4 - Exit Program        *" << endl;
	cout << "***************************" << endl;
}

//Adds one hour to the current time.
void addHour(int& hour) {

	//Increase the current hour by one.
	hour = hour + 1;

	//After 23 comes 0 on a 24-hour clock.
	if (hour == 24) {
		hour = 0;
	}
}

//Adds one minute to the current time. 
void addMinute(int& hour, int& minute) {

	//Increase the current minute by one.
	minute - minute + 1;

	//If the minutes reaches 60, reset them to 0.
	if (minute == 60) {
		minute = 0;

		//Adding 60 minutes also increases the hour by one.
		addHour(hour);
	}
}

//Adds one second to the current time.
void addSecond(int& hour, int& minute, int& second) {

	//Increase the current second by one. 
	second = second + 1;

	//If the seconds reach 60, reset them to 0.
	if (second == 60) {
		second = 0;

		//Adding 60 seconds also increases the minute by one.
		addMinute(hour, minute);
	}
}
