#include "../inc/ProgramHandler.h"
#include <signal.h>

int ProgramHandler::startApp(bool doYouWantToWaitForChild)
{
  if(!FileHandler::doesFileExist(this->m_programName))
  {
     return 0;
  }
  if(this->isProgramRunning())
  {
     std::cout <<"Program: " << m_programName  << " is already running\n" <<std::flush;
     return 0;
  }
  else
  {
    pid_t pid = fork();
    int statval;

    if(pid == 0) //child
    {
        execl(m_programName.c_str(), m_programName.c_str(), (char*) NULL);
        exit(3);
    }
    else if(pid <0)
    {
        std::cerr <<"Failed to fork\n";
        return 0;
    }
    else //Parent
    {
      if(doYouWantToWaitForChild)
      {
        waitpid( (pid <0), &statval, WCONTINUED);
        if(WIFEXITED(statval))
          printf("Child's exit code %d\n", WEXITSTATUS(statval));
        else
          printf("Child did not terminate with exit\n");
          //return 0;
      }
      child_pid = Helper::getPID(m_programName);
    }
  }
    return 1;
}

bool ProgramHandler::isProgramRunning()
{
  return Helper::getPID(m_programName) ? 1 : 0;
}

int ProgramHandler::performRestart()
{
  return performRestart(child_pid);
}

int ProgramHandler::performRestart(pid_t pid )
{
  int result;
  if(pid != 0)
  {
    std::cout <<"Restart of process with PID: " << pid <<"\n"<<std::flush;

    result = stop(pid);
    if(result != -1)
    {
      child_pid = -1;
      startApp();
    }
  }else
  {
    std::cout <<"Process does not exists\n" << std::flush;
    result = -1;
  }
 return result;
}

int ProgramHandler::stop(pid_t pid)
{
  kill(pid, SIGTERM );
  return waitpid(pid, 0, 0);
}

void ProgramHandler::stop()
{
  if(child_pid == 0) return;
  stop(child_pid);
}


std::string ProgramHandler::exec(const char* cmd, bool printOutput = 0)
{
  char buffer[128];
  std::string result = "";
  FILE* pipe = popen(cmd, "r");
  if (!pipe) throw std::runtime_error("popen() failed!");
  try 
  {
  	while (!feof(pipe)) 
    {
      if (fgets(buffer, 128, pipe) != NULL)
      {
        result += buffer;
        if(printOutput)
        {
          std::cout << buffer <<std::flush;
        }
      }
    }
  }
  catch (std::exception const& e)
  {
    pclose(pipe);
    throw;
  }
  pclose(pipe);
  return result;
	
}

void ProgramHandler::runMakefile()
{
    exec("make -C ../../Weather/WeatherForecast/", 1);
}

void ProgramHandler::cleanMakefile()
{
    exec("make clean -C ../../Weather/WeatherForecast/");
}

ProgramHandler::~ProgramHandler()
{
  if(isProgramRunning())
  {
    stop();
  }
}
