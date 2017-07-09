The TestFrameworkExtention to LibIdentify
-----------------------------------------

The TestFrameworkExtention to LibIdentify allows a testrunning to list and run tests without knowing about the specific framework syntax.
This proposal consists to two commands:

list
----

- --libidentify-list-tests

outputs all available tests in a json object tree in std::cout, it can be a flat list (since a flat list is also a tree)
```
{"tests":             // required
  {
  "name": "footest",  // required, all others are optional
  "status": "enabled"
  "group": "protocol"
  }
  {
  "name": "footest2",
  "status": "disabled"
  "group": "timing"
  }
}
```

run
---

- --libidentify-run-test <json-data>

{"tests":             // required
  {
  "name": "footest",  // required, all others are optional
  }
  {
  "name": "footest2",
  }
}
```

The output of the tests can be collected from std::cout, again from a json object:


libidentify-test-output
text...
text...
text...
text...
libidentify-test-output

libidentify-test-result
libidentify-test-result


....work in progress... 
