module namespace mod = "mod2";
import module "mod2" at "lmodule4.xq";

declare function mod:func1()
{
  "string", mod:func2()
};
