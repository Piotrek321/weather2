#include "../inc/Helper.h"

pid_t Helper::getPID(std::string processName)	
{
    /*char buf[512];
    std::string prName("pidof -s ");
    prName += processName;
    FILE *cmd_pipe = popen(prName.c_str(), "r");

    fgets(buf, 512, cmd_pipe);
    pid_t pid = strtoul(buf, NULL, 10);

    pclose( cmd_pipe );
        std::cout <<"PID: " << pid <<std::endl;
    return pid;*/

    FILE *pf;
    char command[20];
    char data[512];
    pid_t pid = 0;
    std::string grep = "ps aux |grep ";
    grep += processName;
    // Execute a process listing
    strcpy(command, grep.c_str());

    // Setup our pipe for reading and execute our command.
    pf = popen(command,"r");

    // Error handling

    // Get the data from the process execution
    fgets(data, 512 , pf);

    // the data is now in 'data'
    
    if (pclose(pf) != 0)
        fprintf(stderr," Error: Failed to close command stream \n");
    std::string output (data);
    std::size_t found = output.find(grep);
    if (found==std::string::npos)
    {
        int firstIndex=0, lastIndex=0;
        bool isFirst = true;
        for(unsigned int i=0;i<output.size();i++)
        {
            if(isdigit(output[i]))
            {
                if(isFirst)
                {
                    isFirst = false;
                    firstIndex = i;
                }
                if(output[i+1] == ' ')
                {
                    lastIndex = i;
                    break;
                }
            }
        }
        std::string str = output.substr(firstIndex, lastIndex-firstIndex+1);

        pid = std::stoi(str);
    }

    return pid;


}
