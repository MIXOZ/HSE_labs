#ifndef C___CLI_H
#define C___CLI_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "HuffmanArchiver.h"

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
    Action get_action(std::string &in,std::string &out);
private:
    bool parseArguments(int pos, char** _argv, int& _type_id, int& _fin_id, int& _fout_id);
    int argc;
    char** argv;
};

#endif //C___CLI_H
