(: Testing the ASTCopier for FunctionsMatches:)
let $var := matches("1234A", "1234(zz)?\1A") return $var
