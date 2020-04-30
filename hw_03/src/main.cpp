#include "../include/CLI.h"
#include "../include/HuffmanArchiver.h"

int main(int argc, char** argv) {
    std::string in;
    std::string out;
    CLI cli (argc, argv);

    std::ifstream fin;
    std::ofstream fout;

    HuffmanArchiver::HuffmanArchiver zip;

    try {
        if (cli.get_action(in, out) == ARCHIVATE) {
            fin = std::ifstream(in, std::ifstream::in);
            fout = std::ofstream(out, std::ofstream::binary);
            if (!(fin.good() && fout.good())) throw FileException();
            zip.archive(fin, fout);
        } else {
            fin = std::ifstream(in, std::stringstream::binary);
            fout = std::ofstream(out, std::stringstream::out);
            if (!(fin.good() && fout.good())) throw FileException();
            zip.unarchive(fin, fout);
        }
    } catch (const std::bad_alloc&) {
        return -1;
    } catch(std::exception& e) {
        std::cout << e.what() << '\n';
        return 1;
    } 
    return 0;
}