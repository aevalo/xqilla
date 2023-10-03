module namespace pm = "http://snelson.org.uk/test/private_module1";

declare %private function pm:not-imported($a)
{
  $a + 7
};

declare %public function pm:imported($a)
{
  pm:not-imported($a) * 2
};

declare function pm:imported2($a)
{
  pm:not-imported($a) * 5
};

