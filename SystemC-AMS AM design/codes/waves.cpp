#ifndef WAVES_CPP
#define WAVES_CPP
#include "systemc.h"
#include "systemc-ams.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#define PI 3.1415926535897932384626433832795
using namespace std;
SCA_TDF_MODULE(message_src)
{
	sca_tdf::sca_out<double> out; // output port
	sca_tdf::sca_de::sca_out<double> Mt;
	message_src(sc_core::sc_module_name nm, double ampl_ = 1, double freq_ = 1.0e4,
		sca_core::sca_time Tm_ = sca_core::sca_time(0.1, sc_core::SC_MS))
		: out("out"), ampl(ampl_), freq(freq_), Tm(Tm_) {}

	void set_attributes()
	{
		set_timestep(100, sc_core::SC_NS);
		out.set_rate(1);
		out.set_timestep(100, sc_core::SC_NS);
	}
	void processing()
	{
		double t = get_time().to_seconds(); // actual time
		out.write(ampl * std::sin(2.0 * PI * freq * t));
		Mt.write(ampl * std::sin(2.0 * PI * freq * t));
	}

private:
	double ampl; // amplitude
	double freq; // frequency
	sca_core::sca_time Tm; // module time step
};
SCA_TDF_MODULE(carrier_src)
{
	sca_tdf::sca_out<double> out; // output port
	sca_tdf::sca_de::sca_out<double> Ct;
	carrier_src(sc_core::sc_module_name nm, double ampl_ = 60, double freq_ = 1.0e6,
		sca_core::sca_time Tm_ = sca_core::sca_time(0.1, sc_core::SC_MS))
		: out("out"), ampl(ampl_), freq(freq_), Tm(Tm_), Ct("carrier") {}

	void set_attributes()
	{
		set_timestep(100, sc_core::SC_NS);
		out.set_rate(100);
		out.set_timestep(1, sc_core::SC_NS);
	}
	void processing()
	{
		double t = get_time().to_seconds(); // actual time
		out.write(ampl * std::sin(2.0 * PI * freq * t));
		Ct.write(ampl * std::sin(2.0 * PI * freq * t));
	}

private:
	double ampl; // amplitude
	double freq; // frequency
	sca_core::sca_time Tm; // module time step
};
#endif