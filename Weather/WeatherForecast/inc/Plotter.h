#ifndef Plotter_H_
#define Plotter_H_

#include <iostream>
#include <sys/shm.h>
#include <signal.h>
#include "gnuplot-iostream.h"

#define SHMSZ     100
#define KEY_VALUE 5678

class Plotter
{
	public:
		Gnuplot gp;

		int *SharedMemoryPTR;
		
		void init();
		void handleSignal();//TODO
		void plotChart();
		void waitForUsersResond();
		void plotChart(Gnuplot &gp);			
};

#endif
