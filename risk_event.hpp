#pragma once
#include <array>
#include "control.hpp"
#include <string>
#define CONTROL_NUM 3
using namespace std;

class RiskEvent{
	private:
		string eventId; // identification of the risk event
		float probability; // probability of risk occuring 0 - 1
		int impact; // impact event will have higher number means more severe
		array<control_t, CONTROL_NUM> control; // 10 control events that lesson the probability or impact or both
		float appetite; // allowable risk for risk event
	public:
		RiskEvent(); 		
		RiskEvent(string eventId, float probability, int impact, array<control_t, CONTROL_NUM> control,
				float appetite);
		// find inherent risk probability * impact
		float find_inherent_risk(RiskEvent* risk);

		// find residual risk probility * prod(control.probability & control.both) * (prod(control.impact * control.both))
		float find_residual_risk(RiskEvent* risk);

		// find if residual risk is below appetite
		bool is_acceptable(RiskEvent* risk, float residual_risk);

		// get user input
		RiskEvent user_input();
		
		string get_event_id();
		
		float get_probability();
		
		int get_impact();

		array<control_t, CONTROL_NUM> get_control();
		
		float get_appetite();

		void set_event_id(string eventId);
		
		void set_probability(float probability);
		
		void set_impact(int impact);
		
		void set_control();
		
		void set_appetite(float appetite);
};
