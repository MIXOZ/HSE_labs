#include "doctest.h"
#include <iostream>
#include "../include/HuffmanArchiver.h"

TEST_CASE ("test_end_to_end") {
    HuffmanArchiver::HuffmanArchiver zip;

    std::stringstream in("1");
    std::stringstream out;
    std::stringstream buf;

    zip.archive(in, buf);
    zip.unarchive(buf, out);

    CHECK(in.str() == out.str());
}