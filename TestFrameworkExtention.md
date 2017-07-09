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
  "status": "enabled",
  "group": "protocol"
  }
  {
  "name": "footest2",
  "status": "disabled",
  "group": "timing"
  }
}
```

run
---

- --libidentify-run-test <json-data>

```
{"tests":             // required
  {
  "name": "footest",  // required, all others are optional
  }
  {
  "name": "footest2"
  }
}
```

The output of the tests can be collected from std::cout, again from a json object:

```
{"testoutput:         
  {
  "line": "line1",        // the 'testoutput' object is optional
  }
  {
  "line": "line2"
  }
}
```

This is always the last object to be received, so receiving any other object means there is a next object to be read.
```
{"testresult:             // the 'restresult' object is mandatory
  {
  "result": "pass",       // only 'pass', 'fail' and 'undetermined' are valid values
  "reason": "disabled",   // optional: reason is a framework specific free text 
  }
}
```

Discussion / Thoughts
---------------------

- I've proposed JSON objects here and communication channels std::cout / std::cin
- alternatively temporary files could be used as 'data blocks'
- sockets could used, allowing to run tests remotely
- I'm open to other ideas! please contribute!



