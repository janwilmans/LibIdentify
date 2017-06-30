# LibIdentify
Standard set of methods to identify a projects executable, for now specifically aimed at test-frameworks

# Abstract / Rationale
The initial reason for the existance of this set of methods is too let [BoostTestUI](https://github.com/djeedjay/BoostTestUi) identify the kind of test it is loading. BoostTestUI is a graphical test runner to run unittests, it has features such as auto-reload and auto-rerun tests.

BoostTestUI's name is kindof obsolete, it would better be named MultiTestUI, because it currently supports Boost.Test, Google Test, Catch and Nunit.

Currently tests need to be re-compiled with a special header that is different per test-framework to be able to do two things:
- identify the framework, in order to know what arguments to pass
- add an option --gui-wait to allow the UI to start the test-process without actually beginning to run anything, allowing the user to attach a debugger.

# Proposed standard

```
foobin --libidentify-identification returns on std:cout:
line 1: description:    <description>           [ascii string, starts at colomn 17, ends at newline]
line 2: framework:      <frameworkname>         [ascii string, starts at colomn 17, ends at newline]
line 3: version:        <version>               [ascii string, starts at colomn 17, ends at newline]
```

- <description> ascii string for display purposes, not to be used for identification
- <framework> major part of the identification
- <version> minor part of the identification 

<framework> may be any string, it shall be unique and stable over all future version of your framework
<version> shall start with <major_version_number>.<minor_version_number>. but after the second dot any text is allowed.

# examples 

```
myboosttest --libidentify-identification
description:    Boost Test 
framework:      boost.test
version:        1.64.0

mygoogletest --libidentify-identification
description:    Google Test 
framework:      Google Test
version:        1.8.0

mycatchtest --libidentify-identification
description:    Catch Test 
framework:      Catch Test
version:        1.9.6

myrandomtest --libidentify-identification
description:    Any Random Discription Here
framework:      RaNdOmTeSTFrAmEWoRk
version:        8.4.7.2-delta

```



