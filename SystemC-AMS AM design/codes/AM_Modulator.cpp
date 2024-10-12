#ifndef AM_MODULATOR_CPP
#define AM_MODULATOR_CPP
#include "Mixer.cpp"
#include "waves.cpp"
SC_MODULE(AM_Modulator) {
	sca_tdf::sca_signal<double> msg, carrier;
	sc_out<double>out;
	sc_out<double> message_trace, carrier_trace, mixer_trace;
	Mixer *mixer;
	message_src msg_src;
	carrier_src carrier_src;
	SC_CTOR(AM_Modulator): msg_src("msg_src_instance"),carrier_src("carrier_instance"){
		msg_src.out(msg);
		msg_src.Mt(message_trace);
		carrier_src.out(carrier);
		carrier_src.Ct(carrier_trace);
		mixer = new Mixer("mixer_instance");
		mixer->msg_in(msg);
		mixer->carrier_in(carrier);
		mixer->out(out);
		mixer->At(mixer_trace);
	}
};
#endif