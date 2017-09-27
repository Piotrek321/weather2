#ifndef ProgramHandler_H_
#define ProgramHandler_H_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include "../inc/Helper.h"
#include "../inc/FileHandler.h"

class ProgramHandler
{

  public:
    virtual int startApp(bool doYouWantToWaitForChild =0);
    virtual int performRestart(pid_t pid);
    virtual int performRestart();
    virtual void stop(); 
		virtual int stop(pid_t pid);
    static void runMakefile();
    static void cleanMakefile();
    virtual bool isProgramRunning(); 
    virtual ~ProgramHandler();
    ProgramHandler(std::string programName) : m_programName(programName){};
  private:
    std::string m_programName;
    pid_t child_pid;
    static std::string exec(const char* cmd, bool printOutput);
};

#endif

