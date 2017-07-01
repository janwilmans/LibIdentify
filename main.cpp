#include "libidentify.h"

#include <cstdio>
#include <string>

struct IdentificationType
{
    explicit IdentificationType() : frameworkId(LibIdentify::FrameworkId::framework_unknown) {}
    LibIdentify::FrameworkId frameworkId;
    std::string description;
    std::string category;
    std::string framework;
    std::string version;
};

static char * readLine(std::vector<char>& line, FILE * file)
{
    return std::fgets(line.data(), static_cast<int>(line.size()), file);
}

std::string parse(std::vector<char>& line)
{
    auto str = std::string(line.data()).substr(16);
    return str.substr(0, str.size()-1);
}

static IdentificationType identify(const std::string& filename)
{
    std::string cmd = filename + " --libidentify-identification";
    IdentificationType id;
    std::vector<char> line(1024);
    auto pipe = _popen(cmd.c_str(), "r");
    if (readLine(line, pipe) != nullptr)
        id.description = parse(line);
    if (readLine(line, pipe) != nullptr)
        id.category = parse(line);
    if (readLine(line, pipe) != nullptr)
        id.framework = parse(line);
    if (readLine(line, pipe) != nullptr)
        id.version = parse(line);

    if (id.framework== LibIdentify::framework_boosttest)
        id.frameworkId = LibIdentify::FrameworkId::framework_boost;
    else if (id.framework == LibIdentify::framework_catch)
        id.frameworkId = LibIdentify::FrameworkId::framework_catch;
    else if (id.framework == LibIdentify::framework_googletest)
        id.frameworkId = LibIdentify::FrameworkId::framework_google;
    return id;
}

int main(int argc, char* argv[])
{
    //LibIdentify::report("Boost.Test", LibIdentify::category_testframework, LibIdentify::framework_boosttest, "1.64.0", argc, argv);
    //LibIdentify::report("Catch C++ Framework", LibIdentify::category_testframework, LibIdentify::framework_catch, "1.9.6", argc, argv);
    //LibIdentify::report("Google Test", LibIdentify::category_testframework, LibIdentify::framework_googletest, "1.8.0", argc, argv);
    LibIdentify::report("My test description", LibIdentify::category_unspecified, "My unique framework string", "1.0", argc, argv);

    if (argc == 2)
    {
        std::string filename(argv[0]);
        std::cout << "Identify: " << filename << std::endl;
        auto executableId = identify(filename);

        if (executableId.frameworkId == LibIdentify::FrameworkId::framework_unknown)
        {
            std::cout << "Could not identify test framework\n";
            exit(1);
        }

        std::cout << "description: " << executableId.description << std::endl;
        std::cout << "category:    " << executableId.category << std::endl;
        std::cout << "framework:   " << executableId.framework << std::endl;
        std::cout << "version:     " << executableId.version << std::endl;
    }
}

void exampleTestMain(int argc, char* argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        auto argument = std::string(argv[i]);
        if (argument == "--wait-for-getchar")
        {
            std::cout << "#waiting" << std::endl;
            std::getchar();
            return;
        }
    }
    LibIdentify::report("My test description", LibIdentify::category_unspecified, "My unique framework string", "1.0", argc, argv);

    /*
    ... normal main() starts here...
    */
}

/*
console output:

>LibIdentify.exe --libidentify-identification
description:    My test description
category:       unspecified
framework:      My unique framework string
version:        1.0

*/