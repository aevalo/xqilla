import module namespace mod = "mod2" at "lmodule3.xq";

declare variable $f := 77;

mod:func1(), mod:func2(), $f
