/*
MIT License

Copyright (c) 2017 Jan Wilmans

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace LibIdentify {

static const char* category_unspecified = "unspecified";
static const char* category_testframework = "testframework";

// to make sure these remain unique, maintain this list in the LibIdentify repository, pull requests welcome!
static const char* framework_boosttest = "Boost.Test";
static const char* framework_catch = "Catch";
static const char* framework_googletest = "Google Test";

static void report(const std::string& description, const std::string& category, const std::string& framework, const std::string& version, int argc, char* argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        auto argument = std::string(argv[i]);
        if (argument == "--libidentify-identification")
        {
            std::cout << std::left << std::setw(16) << "description: " << description << "\n";
            std::cout << std::left << std::setw(16) << "category: " << category << "\n";
            std::cout << std::left << std::setw(16) << "framework: " << framework << "\n";
            std::cout << std::left << std::setw(16) << "version: " << version << std::endl;
            exit(0);
        }
    }
}

}; // namespace LibIdentify
