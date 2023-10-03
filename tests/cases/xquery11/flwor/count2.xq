for $p in (
<p name="courgettes" sales="40"/>,
<p name="tomatoes" sales="500"/>,
<p name="aubergine" sales="320"/>,
<p name="runner beans" sales="602"/>,
<p name="dwarf beans" sales="26"/>,
<p name="potatoes" sales="2002"/>
)
order by number($p/@sales) descending
count $rank
where $rank <= 5
return
   <product rank="{$rank}"> {$p/@name, $p/@sales} </product>
