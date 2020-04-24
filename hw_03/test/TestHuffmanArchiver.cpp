#include "doctest.h"
#include <fstream>
#include "../include/HuffmanArchiver.h"

TEST_CASE ("test_get_action_archivate") {
    HuffmanArchiver zip;
    std::stringstream input("kokorihfvifdcshvhtrcfd reuig ew 3ir geirfy3biwegbhdfn a43gio rwegtjnbgkhewg");
    std::stringstream output;
    std::stringstream buffer;


    zip.archive(input, buffer);
    zip.unarchive(buffer, output);
    
    CHECK(input == output);
}