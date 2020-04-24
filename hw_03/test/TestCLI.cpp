#include "doctest.h"
#include "../include/CLI.h"

TEST_CASE ("test_get_action_archivate") {
    int argc = 6;
    char *argv[6];
    argv[0] = "./hw_03";
    argv[1] = "-c";
    argv[2] = "-f";
    argv[3] = "input.txt";
    argv[4] = "-o";
    argv[5] = "output.bin";
    std::string in;
    std::string out;
    CLI cli(argc, argv);
    CHECK(cli.get_action(in, out) == ARCHIVATE);
    CHECK(in == "input.txt");
    CHECK(out == "output.bin");
}

TEST_CASE ("test_get_action_unarchivate") {
    int argc = 6;
    char *argv[6];
    argv[0] = "./hw_03";
    argv[1] = "-u";
    argv[2] = "-f";
    argv[3] = "output.bin";
    argv[4] = "-o";
    argv[5] = "input.txt";
    CLI cli(argc, argv);
    std::string in;
    std::string out;
    CHECK(cli.get_action(in, out) == ARCHIVATE);
    CHECK(out == "input.txt");
    CHECK(in == "output.bin");
}