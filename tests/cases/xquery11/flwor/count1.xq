for $a in (1 to 100)
order by $a descending
where $a mod 7 = 0
let $b := $a * $a
count $p
where $p mod 2 = 0
return <result p="{$p}" a="{$a}" b="{$b}"/>