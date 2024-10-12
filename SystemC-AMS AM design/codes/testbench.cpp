#ifndef TESTBENCH_CPP
#define TESTBENCH_CPP
#include "FullSystem.cpp"
SC_MODULE(Testbench) {
	sc_signal <double> modulated,output,msg_trace,carrier_trace;
	FullSystem* system;
	SC_CTOR(Testbench) {
		system = new FullSystem("HW7");
		system->out(output);
		system->modulated(modulated);
		system->message_trace(msg_trace);
		system->carrier_trace(carrier_trace);
	}
};
int sc_main(int argc, char* argv[]) {
	sc_set_time_resolution(1.0, SC_NS);
	sc_trace_file* tracefile = sc_create_vcd_trace_file("output");
	Testbench* tb = new Testbench("TB");
	sc_trace(tracefile, tb->output, "output");
	sc_trace(tracefile, tb->modulated, "mixer_out");
	sc_trace(tracefile, tb->msg_trace, "msg");
	sc_trace(tracefile, tb->carrier_trace, "carrier");
	sc_trace(tracefile, tb->system->reciever.connection, "HRout");
	sc_trace(tracefile, tb->system->reciever.myfilter.input, "filter_input");
	sc_start(1,SC_MS);
	return 0;
}
#endif