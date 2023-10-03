let $a := ("foo", "bar", "baz")
order by 5
let $b := 3
where $a = "baz"
for $a in $a
return ($a, $b)
