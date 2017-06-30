# LibIdentify
Standard set of methods to identify a projects executable, for now specifically aimed at test-frameworks

# Abstract / Rationale
The initial reason for the existance of this set of methods is too let [BoostTestUI](https://github.com/djeedjay/BoostTestUi) identify the kind of test it is loading. BoostTestUI is a graphical test runner to run unittests, it has features such as auto-reload and auto-rerun tests.

BoostTestUI's name is kindof obsolete, it would better be named MultiTestUI, because it currently supports Boost.Test, Google Test, Catch and Nunit.

Currently tests need to be re-compiled with a special header that is different per test-framework to be able to do two things:
- identify the framework, in order to know what arguments to pass
- add an option --gui-wait to allow the UI to start the test-process without actually beginning to run anything, allowing the user to attach a debugger.

