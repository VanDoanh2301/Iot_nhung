#include "tb_fir.h"

void tb_fir::source() {

	// complete reset pulse, make sure ready to receive signal
	reset.write(0);
	reset.write(1);
	wait();
	reset.write(0);
	wait();

	sc_uint<16> tmp = 0;

	// send simulation to fir
	for(int i=0; i < 64; i++) {
		if (i > 27 && i < 45)
			tmp = 255;
		else
			tmp = 0;
		in.write(tmp);
		wait();
	}

}

void tb_fir::sink() {
	sc_uint<16> tmpdata = 0;

	wait();
	for(int i=0; i < 64; i++) {
		tmpdata = out.read();
		wait();
		cout << i << " :\t" << tmpdata.to_int() << endl;
	}

	sc_stop();
}
