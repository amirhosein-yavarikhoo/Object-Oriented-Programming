#ifndef ELNMODULE_CPP
#define ELNMODULE_CPP
#include "systemc.h"
#include "systemc-ams.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
SC_MODULE(Filter) {
	sc_in<double> input;
	sc_out<double> output;
	sca_eln::sca_c *cap;
	sca_eln::sca_r *res;
	sca_eln::sca_de_isource i_in;
	sca_eln::sca_de_vsink v_out;
	SC_HAS_PROCESS(sc_module_name);
	Filter(sc_module_name) : i_in("i_input", 1.0), v_out("v_out", 1.0) {
		i_in.p(a);
		i_in.n(gnd);
		i_in.inp(input);
		i_in.set_timestep(1, SC_NS);
		cap = new sca_eln::sca_c("capacitor", 5e-8);
		cap->n(gnd);
		cap->p(a);
		cap->set_timestep(1, SC_NS);
		res = new sca_eln::sca_r("resistor", 3.183e-1);
		res->p(a);
		res->n(gnd);
		v_out.p(gnd);
		v_out.n(a);
		v_out.outp(output);
		v_out.set_timestep(1, SC_NS);
	}
private:
	sca_eln::sca_node_ref gnd;
	sca_eln::sca_node a;
};
#endif