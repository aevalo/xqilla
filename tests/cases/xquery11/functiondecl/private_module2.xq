module namespace pm = "http://snelson.org.uk/test/private_module2";
declare namespace tmp = "http://example.com/tmp";

declare function pm:imported($a)
{
  $a + 9
};

declare %private function pm:good-namespace($a)
{
  $a + 7
};

declare %private function tmp:bad-namespace($a)
{
  $a + 1
};

