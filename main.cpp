#include "risk_event.hpp"
#include <iostream>
#include <ostream>
#include <thread>
#include <chrono>
using namespace std;

int main(){
	char command = '\0';
	char input;

	cout << "\x1b[2J"; // clear screen
	cout << "\x1b[2H"; // set cursor to home
	cout << "\x1b[?25l"; // hide cursor
	cout << "\x1b[035m";
	cout << "Welcome to the" << flush;
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "\x1b[036m"; 
	cout << " Antimony Engine: Your Risk Analysis Engine\n";
	cout << "\x1b[032m";
	cout << "_________________________________________________________________\n";
	this_thread::sleep_for(chrono::milliseconds(600));

	while(command == '\0'){
	
		cout << "What would you like to do?\nr)isk analysis\nq)uit\n\n>>";
		cin >> input;
		
		switch (input){
			
			case 'q':
				command = input;
				cout << "\x1b[031m";
				cout << "Goodbye\n";
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
		cout << "\nCalculating[.....]\r" << flush;
		this_thread::sleep_for(chrono::milliseconds(300));
		cout << "Calculating[*....]\r" << flush;
		this_thread::sleep_for(chrono::milliseconds(400));
		cout << "Calculating[**...]\r" << flush;
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << "Calculating[***..]\r" << flush;
		this_thread::sleep_for(chrono::milliseconds(600));
		cout << "Calculating[****.]\r" << flush;
		this_thread::sleep_for(chrono::milliseconds(650));
		cout << "Calculating[*****]\n";
		cout << "Inherent Risk: ";
		cout << risk->find_inherent_risk(risk);

	}
	
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "\x1b[037m";
	cout << "\x1b[2J";
	cout << "\x1b[2H";
	cout << "\x1b[?25h"; // show cursor
	return 0;	
}
