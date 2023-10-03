import module namespace mod = "mod2" at "lmodule3.xq";

declare function local:f($a) { $a + 1 };

mod:func1(), mod:func2(), local:f(99)
