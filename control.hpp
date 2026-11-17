#pragma once

typedef struct risk_control{ // control struct with control for impact, probability or both, init as 1 for no control
	float control_impact = 1;
	float control_probability = 1;
	float control_both = 1;

} control_t;
