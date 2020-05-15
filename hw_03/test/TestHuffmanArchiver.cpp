#include "doctest.h"
#include <iostream>
#include "../include/HuffmanArchiver.h"

TEST_CASE ("test_end_to_end") {
    HuffmanArchiver::HuffmanArchiver zip1;
    HuffmanArchiver::HuffmanArchiver zip2;

    std::stringstream in("123");
    std::stringstream out;
    std::stringstream buf;

    zip1.archive(in, buf);

   // zip2.unarchive(buf, out);

    CHECK(in.str() == out.str());
}