<days>&#10;{string-join(
for $a in ("Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday")
count $p
return concat($p, ". ", $a),
"&#10;")}&#10;</days>