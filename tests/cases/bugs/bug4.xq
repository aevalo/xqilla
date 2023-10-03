copy $a := document { "   ", processing-instruction hello {""}, <foo/>, comment { "Ok" } }
modify ()
return (
  count($a/self::document-node()),
  $a treat as document-node()
)
