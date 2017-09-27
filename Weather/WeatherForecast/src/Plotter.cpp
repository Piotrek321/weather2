#include "../inc/Plotter.h"

void Plotter::plotChart(Gnuplot &gp)
{
  gp << " set xdata time\n";
  //gp << "set yrange [0:22]\n";
  gp <<" set timefmt '%Y%m%d %H:M'\n";
  gp << "plot 'abc.txt' using 1:3 title 'Yahoo' with lines, '' using 1:4 title 'OWM' with lines\n";
  gp.flush();
}


void Plotter::init()
{
/*
  pid_t pid;
  key_t MyKey = KEY_VALUE;
  int   SharedMemoryID;
  char  line[SHMSZ], c;
  bool  first = true;

  SharedMemoryID   = shmget(MyKey, SHMSZ, 0666);
  SharedMemoryPTR  = (int *) shmat(SharedMemoryID, NULL, 0);
  pid     	       = *SharedMemoryPTR;  */
}
