#include "risk_event.cpp"
#include <iostream>
#include <ostream>
#include <thread>
#include <chrono>
using namespace std;

int main(){
	char command = '\0';
	char input;
	
	cout << "\x1b[035m";
	cout << "Welcome to the";
	cout << "\x1b[036m"; 
	cout << " Antimony Engine: Your Risk Analysis Engine\n";
	cout << "\x1b[032m";
	cout << "_________________________________________________________________\n";
	
	while(command == '\0'){
	
		cout << "What would you like to do?\nr)isk analysis\nq)uit\n\n>>";
		cin >> input;
		
		switch (input){
			
			case 'q':
				command = input;
				cout << "\x1b[031m";
				cout << "Goodbye";
				cout << "\x1b[037m";
				break;
			
			case 'r':
				command = input;
				break;

			default:
				cout << "\x1b[031m";
				cout << "\n\nInvalid Operation Detected\x1b[032m";
				cout << "\n";
		}
	}

	if (command == 'r'){
		RiskEvent* risk = new RiskEvent();
		risk->user_input();
		cout << "\nCalculating[.....]\r";
		this_thread::sleep_for(chrono::milliseconds(50));
		cout << "Calculating[*....]\r";
		this_thread::sleep_for(chrono::milliseconds(50));
		cout << "Calculating[**...]\r";
		this_thread::sleep_for(chrono::milliseconds(50));
		cout << "Calculating[***..]\r";
		this_thread::sleep_for(chrono::milliseconds(50));
		cout << "Calculating[****.]\r";
		this_thread::sleep_for(chrono::milliseconds(200));
		cout << "Calculating[*****]\n";

	}

	return 0;	
}
