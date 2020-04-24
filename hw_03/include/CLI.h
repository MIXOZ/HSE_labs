#ifndef C___CLI_H
#define C___CLI_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

enum Action {
    ARCHIVATE,
    UNARCHIVATE
};

class ParceException : public std::exception {
public:
    const char* what() const throw();
};

class FileException : public std::exception {
public:
    const char* what() const throw();
};

class CLI {
public:
    CLI(int _argc, char** _argv) : argc(_argc), argv(_argv) {};
    bool parseArguments(int pos, char** _argv, int& _type_id, int& _fin_id, int& _fout_id);
    Action get_action(std::string &in,std::string &out);
private:
    int argc;
    char** argv;
    int type_id = -1; 
    int fin_id = -1;
    int fout_id = -1;
};

#endif //C___CLI_H
