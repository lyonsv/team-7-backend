
float calculate_tenderness(const float impedance, const float ph, const float reflectance) {
	float tenderness = 0.0;
	Boolean dfd = false;
	tenderness = calculate_ultimate_ph(ph_ultimate_reading) + calculate_delta_ph(ph_delta_reading) + calculate_nir(nir_reading) + calculate_impedance(impedance_reading);

	dfd = dfd_zero(ph_ultimate);

	tenderness = impeance + ph + reflectance;
	return tenderness;
}

float to_percentage(const float raw_value) {
	return raw_value*100;
}

int to_star_rating(const float raw_value) {
	if(percentage => 0.8) {
		return 3;
	} else if(percentage >= 0.5 && percentage < 0.8) {
		return 2;
	} else if(percentage >= 0.3 && percenteage < 0.5) {
		return 1;
	} else {
		return 0;
	}
}

void calculate_delta_ph(float temperature, float ph) {
	//temperature at ph of 6
	//if ph == 5.9 6.1
	if(ph == 6) {
		//record temperature
		if(temperature >= 15 && temperature < 20) {
			return 0.3;
		} else if(temperature >= 20 && temperature < 25) { 
			return 0.2;
		} else if(temperature >= 25 && temperature < 39) {
			return 0.25
		} else if(temperature >= 10 && temperature < 15) {
			return 0.2
		} else {
			return 0.1;
		} //delta ph
	}
}

void calculate_ultimate_ph(float ph_ultimate) {
	//when ph has settled
	if(ph_ultimate < 5.6) {
		return 0.3;
	} else if(ph_ultimate => 5.6 && ph_ultimate =< 6) {
		return 0.15;
	} else if(ph_ultimate > 6) {
		return 0;
		dfd_zero();
	}
}

Boolean dfd_zero(float ph_ultimate) {
	// dark firm dry
	// for ultimate ph
	if(calculate_ultimate_ph(ph_ultimate) == 0.0) {
		return true
	} else {
		return false;
	}
}

float calculate_nir() {
	// TODO read nir sensor and classify
	return 0.2;
}

calculate_impedance() {
	// TODO read impedance sensor and classify
	return 0.2;
}

void loop() {
	Boolean dfd_error = false;

	float ph_ultimate_reading = read_ph_sensor1();
	float ph_delta_reading = read_ph_sensor2();
	float nir_reading = read_nir_sensor();
	float impedance_reading = read_impedance_sensor();

	float tenderness = calculate_tenderness(impedance_reading, ph_ultimate_reading, ph_delta_reading, reflectance_reading);

	send_reading(tenderness);
}
//impedance weight
//450 cattle