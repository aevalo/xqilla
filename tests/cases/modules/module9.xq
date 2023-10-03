declare variable $var1 := local:price(10);

declare function local:price($b)
{
  1 to $b
};

$var1
