#include "fir.h"

void fir::fir_main(void) {
	// reset signal come, you should reset output, local variable

	sc_uint<16> in_arr[5];
	for(int i = 0; i < 4; i++)
		in_arr[i] = 0;
	sc_uint <16> tmp = 0;
	out.write(0);
	wait(); // wait for next clock, only reset signal can take out of while loop

	while(true) {


		// agorithm
		for (int i = 4; i > 0; i--)
			in_arr[i-1] = in_arr[i];

		// read data
		in_arr[4] = in.read();

		for (int i = 0; i <= 4; i++)
			tmp += in_arr[i] * cor[i];

		// write data
		out.write(tmp);
		wait(); // wait() for next positive clock, then may be read because synchonizm
	}


}
