#ifndef DEMODULATOR_CPP
#define DEMODULATOR_CPP
#include "ELNmodule.cpp"
#include "HalfR.cpp"
SC_MODULE(Demodulator) {
	sc_in<double> input;
	sc_out<double> output;
	sc_signal<double> connection;
	Filter myfilter;
	Half_wave_rectifier rectifier;
	SC_CTOR(Demodulator):rectifier("rectifier"), myfilter("RC_filter"){
		rectifier.input(input);
		rectifier.output(connection);
		myfilter.input(connection);
		myfilter.output(output);
	}
};
#endif