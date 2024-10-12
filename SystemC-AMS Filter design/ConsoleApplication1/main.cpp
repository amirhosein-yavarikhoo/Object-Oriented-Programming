#include "TB.cpp"

int sc_main(int argc, char* argv[]) {
	sc_set_time_resolution(0.01, SC_MS);

	TB* testbench = new TB("testbench_instance");
	sc_trace_file* HW6 = sc_create_vcd_trace_file("HW6");
	sc_trace(HW6, testbench->in, "vin");
	sc_trace(HW6, testbench->out, "vout");

	sc_start(500, SC_MS);
	return 0;
}