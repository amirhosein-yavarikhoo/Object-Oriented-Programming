#include <systemc.h>
#include <systemc-ams.h>
SC_MODULE(MyFilter) {
public:
	sc_in<double> in;
	sc_out <double> out;
	sca_eln::sca_de_vsource Vin;
	sca_eln::sca_de_vsink Vout;
	sca_eln::sca_r *R1;
	sca_eln::sca_r *Rload;
	sca_eln::sca_c *C1;
	sca_eln::sca_c *C2;
	sca_eln::sca_node a;
	sca_eln::sca_node b;
	sca_eln::sca_node c;
	sca_eln::sca_node_ref gnd;
	MyFilter(sc_module_name): Vin("Vin"),Vout("Vout") {
		R1 = new sca_eln::sca_r("r1", 200);
		R1->n(a);
		R1->p(b);
		R1->set_timestep(1, SC_MS);
		Rload = new sca_eln::sca_r("rload", 1000);
		Rload->n(c);
		Rload->p(gnd);
		C1 = new sca_eln::sca_c("c1", 2.5e-6);
		C1->n(b);
		C1->p(gnd);
		C2 = new sca_eln::sca_c("c2", 1e-6);
		C2->n(b);
		C2->p(c);
		Vin.p(a);
		Vin.n(gnd);
		Vin.inp(in);
		Vin.set_timestep(1, SC_MS);
		Vout.p(c);
		Vout.n(gnd);
		Vout.outp(out);
	}

};