#include <systemc.h>

const sc_uint<16> cor[5] = {3, 3, 1, 4, 9};

SC_MODULE(fir) {
	sc_in <bool> clk;
	sc_in <bool> reset;
	sc_in <sc_uint<16> > in;
	sc_out <sc_uint<16> > out;

	void fir_main();

	SC_CTOR(fir) {
		// SC_THREAD only wait() for clk, not for
		// 		others sensitive signal, and can wait for multiple clk
		SC_CTHREAD(fir_main, clk.pos());
		reset_signal_is(reset, true);
	}
};
