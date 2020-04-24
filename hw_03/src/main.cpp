#include "../include/CLI.h"
#include "../include/HuffmanArchiver.h"

int main(int argc, char** argv) {
    static std::string in;
    static std::string out;
    CLI cli(argc, argv);

    std::stringstream fin;
    std::stringstream fout;

    HuffmanArchiver zip;

    try {
        if (cli.get_action(in, out) == ARCHIVATE) {
            fin = std::stringstream(in, std::stringstream::in);
            fout = std::stringstream(out, std::stringstream::binary);
            if (!(fin.good() && fout.good())) throw FileException();
            zip.archive(fin, fout);
        } else {
            fin = std::stringstream(in, std::stringstream::binary);
            fout = std::stringstream(out, std::stringstream::out);
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