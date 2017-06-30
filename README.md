# LibIdentify
Standard method to identify a project's executable, for now specifically aimed at test-frameworks.

# Abstract / Rationale
The initial reason for the existance of this project is too let [BoostTestUI](https://github.com/djeedjay/BoostTestUi) identify the kind of test it is loading. BoostTestUI is a graphical test runner for windows to run unittests, but this proposal should be useful to any test-runner that has to deal with executable binaries from several test frameworks, such as for example [Microsoft Visual Studio](https://www.visualstudio.com/) and possibly have wider application in identification of executables in general.

BoostTestUI's name is kindof obsolete, it would better be named MultiTestUI, because it currently supports Boost.Test, Google Test, Catch and Nunit.

Currently tests need to be re-compiled with a special header that is different per test-framework to be able to do two things:
- identify the framework, in order to know what arguments to pass, to for example list all test or execute a specific test.
- add an option --gui-wait to allow the UI to start the test-process without actually beginning to run anything, allowing the user to attach a debugger.

# Proposed standard

```
foobin --libidentify-identification returns on std:cout:
line 1: description:    <description>           [ascii string, starting at colomn 17, ending at but not including newline]
line 2: category:       <category>              [ascii string, starting at colomn 17, ending at but not including newline]
line 3: framework:      <frameworkname>         [ascii string, starting at colomn 17, ending at but not including newline]
line 4: version:        <version>               [ascii string, starting at colomn 17, ending at but not including newline]
```

- ```<description>``` ascii string for display purposes, not to be used for identification
- ```<category>``` identification of the category the binary belongs to
- ```<framework>``` major part of the identification
- ```<version>``` minor part of the identification 

```<framework>``` may be any string, it shall be unique and stable over all future version of your framework
```<version>``` shall start with <major_version_number>.<minor_version_number>. but after the second dot any text is allowed.

# categories

Currently there is only one valid category:
- testframework

# examples 

```
myboosttest --libidentify-identification
description:    Boost Test
category:       testframework
framework:      boost.test
version:        1.64.0

mygoogletest --libidentify-identification
description:    Google Test 
category:       testframework
framework:      Google Test
version:        1.8.0

mycatchtest --libidentify-identification
description:    Catch Test 
category:       testframework
framework:      Catch Test
version:        1.9.6

myrandomtest --libidentify-identification
description:    Any Random Discription Here
category:       testframework
framework:      RaNdOmTeSTFrAmEWoRk
version:        8.4.7.2-delta
```

# Proposed extention for all test frameworks

I propose to add an commandline argument extention to all test frameworks that do not have this yet:

```
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
```

Note that this argument can have any name you like, it is not part of the 'libidentify' standard as such.






