declare variable $var2 := local:price(10);

declare function local:price($b)
{
  1 to $b, $var1
};

declare variable $var1 := (1, 2, $var2);

$var1
