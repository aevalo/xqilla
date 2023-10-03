import module namespace mod = "mod2" at "lmodule3.xq";

mod:func1(), mod:func2(),

mod:func1()[3] is mod:func2()[2]
