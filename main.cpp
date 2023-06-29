#include <systemc.h>
#include "fir.h"
#include "tb_fir.h"


SC_MODULE( SYSTEM ) {
	tb_fir *tb0;
	fir *fir0;

	sc_signal <sc_uint<16> > in_signal;
	sc_signal <sc_uint<16> > out_signal;
	sc_signal <bool> reset_signal;
	sc_clock clk_signal;


	SC_CTOR( SYSTEM )
		: clk_signal("CLK_SIGNAL", 10, SC_NS)
	{
		fir0 = new fir("FIR0");
		tb0 = new tb_fir("TB0");

		tb0->reset(reset_signal);
		tb0->in(in_signal);
		tb0->out(out_signal);
		tb0->clk(clk_signal);

		fir0->reset(reset_signal);
		fir0->in(in_signal);
		fir0->out(out_signal);
		fir0->clk(clk_signal);
	}

	~SYSTEM() {
		delete fir0;
		delete tb0;
	}
};




int sc_main(int agrc, char* argv[]) {
	 SYSTEM *top = new SYSTEM ("TOPSYSTEM");
	 // Sim for 200
	 int end_time = 2000;
	 cout << "INFO: Simulating" << endl;
	 // start simulation
	 sc_start(end_time, SC_NS);

	return 0;
}


