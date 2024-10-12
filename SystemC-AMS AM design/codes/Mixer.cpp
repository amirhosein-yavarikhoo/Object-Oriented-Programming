#ifndef MIXER_H
#define MIXER_H
#include "systemc.h"
#include "systemc-ams.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#define PI 3.1415926535897932384626433832795
using namespace std;
SCA_TDF_MODULE(Mixer) {
	sca_tdf::sca_in<double>msg_in;
	sca_tdf::sca_in<double>carrier_in;
	sca_tdf::sca_de::sca_out<double> out; // output port
	sca_tdf::sca_de::sca_out<double> At;
	SCA_CTOR(Mixer) : out("out"), At("At") {}
	void set_attributes() {
		msg_in.set_rate(1);
		msg_in.set_timestep(100, sc_core::SC_NS);
		carrier_in.set_rate(100);
		carrier_in.set_timestep(1, sc_core::SC_NS);
		out.set_rate(100);
		out.set_timestep(1, sc_core::SC_NS);
		At.set_rate(100);
		At.set_timestep(1, sc_core::SC_NS);
		//set_timestep(sca_core::sca_time(0.1, sc_core::SC_MS));
	}
	void processing() {
		for (unsigned long i = 0; i < 100; i++) {
			double temp = (msg_in.read() * carrier_in.read(i)) + carrier_in.read(i);
			out.write(temp, i);
			At.write(temp, i);
		}
	}
};
#endif