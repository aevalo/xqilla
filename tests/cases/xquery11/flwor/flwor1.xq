for $a in (1 to 100)
order by $a descending
where $a mod 7 = 0
let $b := $a * $a
return <result a="{$a}" b="{$b}"/>