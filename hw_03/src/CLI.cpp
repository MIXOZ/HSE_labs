#include "../include/CLI.h"


const char* ParceException::what() const noexcept {
    return "invalid arguments";
}

const char* FileException::what() const noexcept {
    return "read/write file error";
}

bool CLI::parseArguments(int pos, char** _argv, int& _type_id, int& _fin_id, int& _fout_id) {
    if (pos > 6) return false;
    if (pos == 6) return true;
    if (strcmp(_argv[pos], "-c") == 0 || strcmp(_argv[pos], "-u") == 0) {
        _type_id = pos;
        return parseArguments(pos + 1, _argv, _type_id, _fin_id, _fout_id);
    }
    if (strcmp(_argv[pos], "-f") == 0 || strcmp(_argv[pos], "--file") == 0) {
        _fin_id = pos + 1;
        return parseArguments(pos + 2, _argv, _type_id, _fin_id, _fout_id);
    }
    if (strcmp(_argv[pos], "-o") == 0 || strcmp(_argv[pos], "--output") == 0) {
        _fout_id = pos + 1;
        return parseArguments(pos + 2, _argv, _type_id, _fin_id, _fout_id);
    }
    return false;
}

Action CLI::get_action(std::string &in,std::string &out) {
    if (argc != 6) throw ParceException();
    int _type_id = -1, _fin_id = -1, _fout_id = -1;
    if (!parseArguments(1, argv, _type_id, _fin_id, _fout_id)) throw ParceException();
    if (_type_id == -1 || _fin_id == -1 || _fout_id == -1) throw ParceException();
    in = std::string(argv[_fin_id]);
    out = std::string(argv[_fout_id]);
    if (std::string(argv[_type_id]) == "-c") return ARCHIVATE;
    return UNARCHIVATE;
}
