The TestFrameworkExtention to LibIdentify
-----------------------------------------

The TestFrameworkExtention to LibIdentify allows a testrunning to list and run tests without knowing about the specific framework syntax.
This proposal consists to two commands:

list
----

- --libidentify-list-tests

lists all available tests in a json object tree, it can be a flat list (since a flat list is also a tree)


run
---

- --libidentify-run-test <name>

The output of the tests can be collected from std::cout, the output ends with 

libidentify-test-output
text...
text...
text...
text...
libidentify-test-output

libidentify-test-result
libidentify-test-result


....work in progress... 
