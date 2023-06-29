#include <systemc.h>

SC_MODULE (tb_fir) {
	sc_in <bool> clk;
	sc_out <bool> reset;
	sc_out <sc_uint<16> > in;
	sc_in <sc_uint<16> > out;

	// thread will make new value
	void source();

	// thread wil read value
	void sink();

	SC_CTOR(tb_fir) {
		SC_CTHREAD(source, clk.pos());
		SC_CTHREAD(sink, clk.pos());
	}
};
