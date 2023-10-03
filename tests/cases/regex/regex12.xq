(: Testing the ASTCopier for FunctionsTokenize:)
let $var := replace('2006-10-18', '\d{2}(\d{2})-(\d{2})-(\d{2})', '$2/$3/$1') return $var
