#ifndef HALFR_H
#define HALFR_H
#include "systemc.h"
#include "systemc-ams.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
SCA_TDF_MODULE(Half_wave_rectifier) {
	sca_tdf::sca_de::sca_in<double> input;
	sca_tdf::sca_de::sca_out<double> output;
	SCA_CTOR(Half_wave_rectifier):input("input"), output("output"){}
	void set_attributes() {
		//set_timestep(sca_core::sca_time(100, SC_US));
		//input.set_timestep(10, sc_core::SC_NS);
		//input.set_rate(100);
		output.set_timestep(1, sc_core::SC_NS);
		//output.set_rate(100);
	}
	void processing() {
		double temp = input.read();
		if (temp > 0) output.write(temp);
		else output.write(0.0);
	}
};
#endif