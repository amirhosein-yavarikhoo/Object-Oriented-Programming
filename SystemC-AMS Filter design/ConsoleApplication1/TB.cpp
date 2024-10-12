#include "MyFilter.cpp"
#include "Sin.cpp"
SC_MODULE(TB) {
	sc_signal<double> in, out;
	MyFilter* UUT;
	Sinus* input_wave;
	SC_CTOR(TB) {
		input_wave = new Sinus("wave_instance");
		input_wave->out(in);
		UUT = new MyFilter("filter_instance");
		UUT->in(in);
		UUT->out(out);
	}
};