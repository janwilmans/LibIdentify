#include "libidentify.h"

int main(int argc, char *argv[])
{
    LibIdentify::report("My test description", LibIdentify::category_unspecified, "My unique framework string", "1.0", argc, argv);
}

/*
console output:

>LibIdentify.exe --libidentify-identification
description:    My test description
category:       unspecified
framework:      My unique framework string
version:        1.0

*/