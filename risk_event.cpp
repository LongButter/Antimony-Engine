#include <array>
#include <iostream>
#include "control.hpp"
#include "risk_event.hpp"
#include <string>
using namespace std;

RiskEvent::RiskEvent() : RiskEvent("No Event", 0, 0, {}, 0) {}	
		
RiskEvent::RiskEvent(string eventId, float probability, int impact, array<control_t, CONTROL_NUM> control,
				float appetite){
			this->eventId = eventId;
			this->probability = probability;
			this->impact = impact;
			this->control = control;
			this->appetite = appetite;
		}

		string RiskEvent::get_event_id(){
			return eventId;
		}
		float RiskEvent::get_probability(){
			return probability;
		}
		int RiskEvent::get_impact(){
			return impact;
		}
		array<control_t, CONTROL_NUM> RiskEvent::get_control(){
			return control;
		}
		float RiskEvent::get_appetite(){
			return appetite;
		}

		void RiskEvent::set_event_id(string eventId){
			this->eventId = eventId;
		}
		void RiskEvent::set_probability(float probability){
			this->probability = probability;
			if (probability > 1 || probability < 0){
				this->probability = 0;
			}
		}
		void RiskEvent::set_impact(int impact){
			this->impact = impact;
			if (impact < 0){
				this->impact = 0;
			}
		}
		void RiskEvent::set_control(){
			for (int i = 0; i < CONTROL_NUM; i++){
				cout << "\n\nEnter control for probability " + to_string(i) + " : ";
				cin >> this->control[i].control_probability;
				cout << "\nEnter control for impact " + to_string(i) + " : ";
				cin >> this->control[i].control_impact;
				cout << "\nEnter control for both " + to_string(i) + " : ";
				cin >> this->control[i].control_both;
			}
		}
		void RiskEvent::set_appetite(float appetite){
			this->appetite = appetite;
		
		}
		// find inherent risk probability * impact
		float RiskEvent::find_inherent_risk(RiskEvent* risk){
			return  risk->get_probability() * risk->get_impact();
		} 

		// find residual risk probility * prod(control.probability & control.both) * (prod(control.impact * control.both))
		float RiskEvent::find_residual_risk(RiskEvent* risk){
			float control_probability = 1;
			float control_impact = 1;
			for (int i = 0; i < CONTROL_NUM; i++){
				control_probability *= risk->control[i].control_probability * risk->control[i].control_both;
				control_impact *= risk->control[i].control_impact * risk->control[i].control_both;  
			}
			return risk->get_probability() * control_probability * (risk->get_impact() * control_impact);
		}

		// find if residual risk is below appetite
		bool RiskEvent::is_acceptable(RiskEvent* risk, float residual_risk){
			if (risk->get_appetite() > residual_risk) return true;
			return false;
		}

		// get user input
		void RiskEvent::user_input(RiskEvent* risk){
																																																																			
			string id;
			float prob;
			int imp;
			float app;

			cout << "\nEnter Risk Event Id: ";
			cin.ignore(); // ignores \n from old cin extraction
			getline(cin, id);
			cout << "\nEnter probability: ";
			cin >> prob;
			cout << "\nEnter impact: ";
			cin >> imp;
			risk->set_control();
			cout << "\nEnter risk appetite: ";
			cin >> app;
			risk->set_event_id(id);
			risk->set_probability(prob);
			risk->set_impact(imp);
			risk->set_appetite(app);
			
		}

