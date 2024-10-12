#include <systemc.h>
#include <systemc-ams.h>
SC_MODULE(Sinus) {
	sc_out<double> out;
	SC_CTOR(Sinus) {
		SC_THREAD(generate);
	}
	void generate() {
		for (int i = 0; i < 2000; i++) {
			out->write(sin(2 * 3.14 * 100 * i));
			wait(0.1, SC_MS);
		}
	}
};