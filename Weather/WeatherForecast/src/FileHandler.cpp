#include "../inc/FileHandler.h"

FileHandler::~FileHandler()
{
    fileHnd.close();
}

bool FileHandler::openFile()
{
    if(!doesFileExist(fileName))	return 0;
    fileHnd.open(fileName.c_str());
    if(!fileHnd.is_open())
    {
        std::cout <<"Could not open file\n";
        return 0;
    }
    return 1;
};

void FileHandler::close()
{
    fileHnd.close();
}
void FileHandler::createFile()
{
    fileHnd.open(fileName.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
}

void FileHandler::removeFile()
{
    if( unlink( fileName.c_str()) != 0 )
        perror( "Error deleting file" );
    else
        std::cout <<"File successfully deleted\n";
};

std::string FileHandler::readFileToString()
{
    if(! doesFileExist(fileName)) return "";
    std::ifstream ifs(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

    std::ifstream::pos_type fileSize = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    std::vector<char> bytes(fileSize);
    ifs.read(&bytes[0], fileSize);

    return std::string(&bytes[0], fileSize);
}

inline bool FileHandler::doesFileExist(const std::string& name, bool printInfo)
{
    if (std::ifstream(name)) return true;

    if(printInfo)
        std::cout << "File does not exist: " << name <<"\n" <<std::endl;
    return false;
};

std::string FileHandler::findLineWithData(std::string data)
{
    std::string line;
    while(std::getline(fileHnd, line))
    {
        std::size_t found = line.find(data);
        if(found!=std::string::npos)
        {
            return line;
        }
    }
    std::cout << "\n" << data << " was not found in " << fileName << "\n";
    return "";
};
