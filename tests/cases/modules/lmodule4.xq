module namespace mod = "mod2";
import module "mod2" at "lmodule3.xq";

declare function mod:func2()
{
  "and again", <b/>
};
