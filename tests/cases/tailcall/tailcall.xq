declare function local:pow1($x, $n)
{
  if($n = 0) then 1
  else $x * local:pow1($x, $n - 1)
};

declare function local:pow2($x, $n, $r)
{
  if($n = 0) then $r
  else local:pow2($x, $n - 1, $x * $r)
};

declare function local:pow3($x, $n)
{
  if($n = 0) then 1
  else (
    let $a := local:pow3($x, $n idiv 2)
    return ($a * $a * (if($n mod 2 = 1) then $x else 1))
  )
};

declare function local:pow4($x as xs:decimal, $n as xs:decimal, $r as xs:decimal) as xs:decimal
{
  if($n = 0) then $r
  else if($n mod 2 = 0) then local:pow4($x * $x, $n idiv 2, $r)
  else local:pow4($x, $n - 1, $x * $r)
};

string-join( for $a in (
xqilla:time(local:pow1(2, 2000), "pow"),
xqilla:time(local:pow2(2, 2000, 1), "pow2"),
xqilla:time(local:pow3(2, 2000), "pow3"),
xqilla:time(local:pow4(2, 2000, 1), "pow4")
) return string($a), "&#10;")
