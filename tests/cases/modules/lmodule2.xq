module namespace mod = "mod";
import module "mod" at "lmodule1.xq", "lmodule2.xq";

declare variable $mod:b := (10, <a/>);
