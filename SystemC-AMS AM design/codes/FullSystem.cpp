#ifndef FULLSYSTEM_CPP
#define FULLSYSTEM_CPP
#include "AM_Modulator.cpp"
#include "demodulator.cpp"
SC_MODULE(FullSystem) {
	AM_Modulator transmitter;
	Demodulator reciever;
	sc_signal<double> connection;
	sc_out<double> out,message_trace,carrier_trace;
	sc_out<double> modulated;
	SC_CTOR(FullSystem):transmitter("transmitter"),reciever("reciever") {
		transmitter.out(connection);
		reciever.input(connection);
		reciever.output(out);
		transmitter.message_trace(message_trace);
		transmitter.carrier_trace(carrier_trace);
		transmitter.mixer_trace(modulated);
	}
};
#endif