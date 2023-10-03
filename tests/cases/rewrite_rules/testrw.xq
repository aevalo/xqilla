xquery version "3.0";

declare variable $a as xs:untypedAtomic external;

element results { "&#10;",

element MapMapFusion {
xqilla:explain(map(string-length#1, map(concat(?, " green bottles"), 1 to $a)))
  /Binding[@name="{}f"]/exists(InlineFunction/Function[ends-with(@name,"string-length")]/
    Function[ends-with(@name,"concat")])
}, "&#10;",

element CountEqZero {
xqilla:explain(count(1 to $a) eq 0)
  /(ends-with(@name, "empty"))
}, "&#10;",
element CountNeZero {
xqilla:explain(count(1 to $a) ne 0)
  /(ends-with(@name, "not") and ends-with(Function/@name, "empty"))
}, "&#10;",
element CountGtZero {
xqilla:explain(count(1 to $a) gt 0)
  /(ends-with(@name, "not") and ends-with(Function/@name, "empty") and
    ends-with(Function/Function/@name, "tail"))
}, "&#10;",

element AndTrueFold {
xqilla:explain($a and true())
  /Variable/@name = "{}a"
}, "&#10;",
element AndFalseFold {
xqilla:explain($a and false())
  /exists(self::Literal)
}, "&#10;",
element OrTrueFold {
xqilla:explain($a or true())
  /exists(self::Literal)
}, "&#10;",
element OrFalseFold {
xqilla:explain($a or false())
  /Variable/@name = "{}a"
}, "&#10;",

element AddEmptyFold {
xqilla:explain(($a + ()) * (4 - 1))
  /(exists(self::Sequence) and empty(*))
}, "&#10;",
element MulZeroFold {
xqilla:explain($a cast as xs:decimal * 0)
  /exists(self::NumericLiteral)
}, "&#10;",
element notMulZeroFold {
xqilla:explain($a * 0)
  /exists(self::Mul)
}, "&#10;",
element MulOneFold {
xqilla:explain($a * 1)
  /(exists(self::PromoteUntyped) and Variable/@name = "{}a")
}, "&#10;",
element DivMulTransFold {
xqilla:explain(($a * 6) div 2)
  //NumericLiteral/@value = "3.0E0"
}, "&#10;",

element PredTrueFold {
xqilla:explain(($a, 2, 3)[true()])
  /empty(descendant-or-self::Predicate)
}, "&#10;",
element PredFalseFoldAndPredEmptyFold {
xqilla:explain(($a, 2, 3)[false()][$a mod 2 = 0])
  /(self::Sequence and empty(*))
}, "&#10;",

element IfTrueFold {
xqilla:explain(if(3 = 3) then concat("then_", $a) else concat("else_", $a))
  /Literal/@value = "then_"
}, "&#10;",
element IfFalseFold {
xqilla:explain(if(3 = 1) then concat("then_", $a) else concat("else_", $a))
  /Literal/@value = "else_"
}, "&#10;",
element BooleanIfElseTrue {
xqilla:explain(if($a > 3) then $a = 5 else true())
  /(self::Or and *[1]/self::Function[ends-with(@name,"not")])
}, "&#10;",
element BooleanIfThenTrue {
xqilla:explain(if($a > 3) then true() else $a = 0)
  /(self::Or and *[1]/self::GeneralComparison[@comparison="GT"])
}, "&#10;",

element FnEmptyFold1 {
xqilla:explain(empty(($a, 1, 2, 3)))
  /(self::Literal and @value = "false")
}, "&#10;",
element FnEmptyFold2 {
xqilla:explain(empty(trace((), $a)))
  /(self::Literal and @value = "true")
}, "&#10;",

element PredTypeAnalysis1 {
xqilla:explain(<a><b><c>{$a}</c></b></a>[b/c])
  /(ends-with(*[2]/@name, "not") and ends-with(*[2]/Function/@name, "empty"))
}, "&#10;",
(: element PredTypeAnalysis2 { :)
(: xqilla:explain((1 to $a)[5.1]) :)
(:   /(ends-with(@name, "subsequence-helper") and Binding[2]/NumericLiteral[@value = "5.0E0"]) :)
(: }, "&#10;", :)
element notPredTypeAnalysis2 {
xqilla:explain((1 to $a)[last()])
  /(self::Predicate and ends-with(*[2]/@name, "last"))
}, "&#10;",

()
}