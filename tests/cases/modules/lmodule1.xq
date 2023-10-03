module namespace mod = "mod";
import module "mod" at "lmodule1.xq", "lmodule2.xq";

declare variable $mod:a := (5, $mod:b);

declare function mod:func1()
{
  "string"
};
