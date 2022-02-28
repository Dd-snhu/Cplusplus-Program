#include <iostream>
#include <iomanip>


using namespace std;
int hour = 0;    // used for 12hour
int minutes = 0;
int sec = 0;
int t_hour ;    // used for 24hour time
int t_min ;
int t_sec ;
int user_input;
string AM_PM = "AM";

void Print_Time() {  // displays clocks
		
	cout << "***************************" << "      " << "***************************" << endl;
	cout << "*      12-Hour Clock      *" << "      " << "*      24-Hour Clock      *" << endl;
	cout << "*       " << setfill('0') << setw(2) << hour << ":" 
		<< setfill('0') << setw(2) << minutes << ":" <<
		setfill('0') << setw(2) << sec << " " << AM_PM << "       *" <<
		"      " << "*         " << setfill('0') << setw(2) << t_hour << ":" <<
		setfill('0') << setw(2) << setfill('0') << setw(2) << t_min << ":" 
		<< setfill('0') << setw(2) << t_sec << "        *" << endl;
	cout << "***************************" << "      " << "***************************" << endl;
	
	}

void Disp_Menu() { // displays menu to choose from
	cout << "***************************" << endl;
	cout << "* 1- Add One Hour         *" << endl;
	cout << "* 2- Add One Minute       *" << endl;
	cout << "* 3- Add One Second       *" << endl;
	cout << "* 4- Exit Program         *" << endl;
	cout << "***************************" << endl;
}

void Time_Adjust() { // handles time increments and AM / PM

	cin >> user_input;
	while (user_input != 4) { // exit program check
		switch (user_input) {
			
		case 1:		// add hour
			hour += 1;
			if (hour > 12) {
				hour = hour - 12; // after 12 must rest back to 1
			}
			t_hour += 1;
			
			if (t_hour == 24) {  // hour 24 is 0 in 24-hour time
				t_hour = 0; 
			}
			break;

			
		case 2:		// add minutes
			minutes += 1;
			t_min += 1;
			break;

			
		case 3:		// add seconds
			sec += 1;
			if (sec > 59) {		// will increment min by one and reset sec
				minutes += 1;
				sec = 0;
			}

			t_sec += 1;
			if (t_sec > 59) {
				t_min += 1;
				t_sec = 0;
			}
			break;

		default: // does nothing if bad input

			break;
			}

		if (minutes > 59) {  // checks minutes and increment hour if need be
			hour += 1;
			minutes = 0;
		}
		if (t_min > 59) {
			t_hour += 1;
			t_min = 0;
		}
		if (t_hour >= 12) {   // checks to see if 12-hour clock needs AM or PM
			AM_PM = "PM";
		}
		else {
			AM_PM = "AM";
		}
	

		system("CLS");  // clears screen and reprints menu and new time
		Print_Time();
		Disp_Menu();
		cin >> user_input;
	}
}


	


	
		int main() // starts program / displays inital screen / starts time adjustment loop
		{
			Print_Time();
			Disp_Menu();
			Time_Adjust();

			return 0;			
		}
		

