for $f in (concat("one ", ?, " three"), substring-before("one two three", ?), matches(?, "t.*o"), xs:NCName(?))
return <result>{$f("two")}</result>
