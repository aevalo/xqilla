xquery version "3.0";

declare option xqilla:extensions "true";

for $a in (

let $map := empty-map()
let $map := map-put($map, "a", "aardvark")
let $map := map-put($map, "z", "zebra")
let $map := map-put($map, "e", ("elephant", "eagle"))
let $map := map-put($map, "o", "osterich")
let $map2 := map-put($map, "a", "antelope")
let $map := map-put($map, "t", "terrapin")
let $map3 := map-put($map, 5, "lala")
let $map4 := map-put($map2, "d", 1)
return (
  $map("a"),
  $map2("a"),
  map-get($map, "e"),
  map-contains($map, "k"),
  map-contains($map, "t"),
  map-contains($map2, "t"),

  map-entries($map),
  map-keys($map2),

  map-fold(
    function($a, $k, $v) {
      $a, concat("key: ", $k, ", value: (",
        string-join($v, ", "), ")")
    }, (), $map2),

  $map instance of map(),
  $map instance of map(xs:string, xs:string+),
  $map2 instance of map(xs:string, xs:string),
  $map3 instance of map(xs:string, xs:string*),
  $map3 instance of map(xs:anyAtomicType, xs:string*),
  $map4 instance of map(xs:string, xs:string*),
  $map4 instance of map(xs:string, item()*)
),
let $map := tuple { a := 5, b := 10 }
return (
$map(xs:QName("b")),
map-contains($map, xs:QName("a")),
$map instance of tuple(a as xs:integer),
$map instance of tuple(a as xs:string),
$map instance of tuple(a as xs:decimal, d as xs:date?),
map-new(($map, tuple { c := 99, a := "moo" }))
)

) return (<result>{$a}</result>, "&#10;")
