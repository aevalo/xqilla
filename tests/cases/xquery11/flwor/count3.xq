for $s in ("oxford", "london")
for $p in (
<p name="courgettes" store="london"/>,
<p name="tomatoes" store="london"/>,
<p name="aubergine" store="oxford"/>,
<p name="runner beans" store="london"/>,
<p name="dwarf beans" store="oxford"/>,
<p name="potatoes" store="london"/>
)
where $p/@store = $s
count $c
let $column := $c mod 2
order by $column
return <product column="{$column}">{ $p/@name, $p/@store }</product>
