import module namespace func = "http://snelson.org.uk/functions/functional";

(: declare function local:fib() as xs:integer+ :)
(: { :)
(:   let $fib := local:fib() :)
(:   return ( :)
(:     0, 1, :)
(:     func:zipWith(function($a, $b) { $a + $b }, :)
(:                   $fib, subsequence($fib, 2)) :)
(:   ) :)
(: }; :)

declare function local:fib2_aux($result as xs:integer, $next as xs:integer) as xs:integer+
{
  $result, local:fib2_aux($next, $next + $result)
};

declare function local:fib2() as xs:integer+
{
  local:fib2_aux(0, 1)
};

string-join(
for $a in subsequence(

let $interleave := func:curry(map-pairs#3)(function($a, $b) { $a, $b })
let $enumerate := $interleave(func:iterate(func:incr#1, 0))
return
$enumerate(local:fib2())

, 1, 100)
return string($a)
, "&#10;")
