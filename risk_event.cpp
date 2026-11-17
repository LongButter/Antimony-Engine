#include <array>
#include <iostream>
#include "control.hpp"
#include <string>
#define CONTROL_NUM 10
using namespace std;

class RiskEvent{
	private:
		string eventId; // identification of the risk event
		float probability; // probability of risk occuring 0 - 1
		int impact; // impact event will have higher number means more severe
		array<control_t, CONTROL_NUM> control; // 10 control events that lesson the probability or impact or both
		float appetite; // allowable risk for risk event
	public:
		RiskEvent() : RiskEvent("No Event", 0, 0, {}, 0) {}	
		
		RiskEvent(string eventId, float probability, int impact, array<control_t, CONTROL_NUM> control,
				float appetite){
			this->eventId = eventId;
			this->probability = probability;
			this->impact = impact;
			this->control = control;
			this->appetite = appetite;
		}

		string get_event_id(){
			return eventId;
		}
		float get_probability(){
			return probability;
		}
		int get_impact(){
			return impact;
		}
		array<control_t, CONTROL_NUM> get_control(){
			return control;
		}
		float get_appetite(){
			return appetite;
		}

		void set_event_id(string eventId){
			this->eventId = eventId;
		}
		void set_probability(float probability){
			this->probability = probability;
			if (probability > 1 || probability < 0){
				this->probability = 0;
			}
		}
		void set_impact(int impact){
			this->impact = impact;
			if (impact < 0){
				this->impact = 0;
			}
		}
		void set_control(){
			for (int i = 0; i < CONTROL_NUM; i++){
				cout << "\n\nEnter control for probability " + to_string(i) + " : ";
				cin >> this->control[i].control_probability;
				cout << "\nEnter control for impact " + to_string(i) + " : ";
				cin >> this->control[i].control_impact;
				cout << "\nEnter control for both " + to_string(i) + " : ";
				cin >> this->control[i].control_both;
			}
		}
		void set_appetite(float appetite){
			this->appetite = appetite;
		
		}
		// find inherent risk probability * impact
		float find_inherent_risk(RiskEvent* risk){
			return  risk->get_probability() * risk->get_impact();
		} 

		// find residual risk probility * prod(control.probability & control.both) * (prod(control.impact * control.both))
		float find_residual_risk(RiskEvent* risk){
			float control_probability = 1;
			float control_impact = 1;
			for (int i = 0; i < CONTROL_NUM; i++){
				control_probability *= risk->control[i].control_probability * risk->control[i].control_both;
				control_impact *= risk->control[i].control_impact * risk->control[i].control_both;  
			}
			return risk->get_probability() * control_probability * (risk->get_impact() * control_impact);
		}

		// find if residual risk is below appetite
		bool is_acceptable(RiskEvent* risk, float residual_risk){
			if (risk->get_appetite() > residual_risk) return true;
			return false;
		}

		// get user input
		RiskEvent user_input(){
			
			RiskEvent new_risk_event = RiskEvent();
			string id;
			float prob;
			int imp;
			float app;

			cout << "\nEnter Risk Event Id: ";
			cin >> id;
			cout << "\nEnter probability: ";
			cin >> prob;
			cout << "\nEnter impact: ";
			cin >> imp;
			new_risk_event.set_control();
			cout << "\nEnter risk appetite: ";
			new_risk_event.set_event_id(id);
			new_risk_event.set_probability(prob);
			new_risk_event.set_impact(imp);
			new_risk_event.set_appetite(app);
			
			return new_risk_event;
		}
};

