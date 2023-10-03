declare function local:a($count)
{
  let $s := ()
  order by $s
  return local:b($count treat as item()+)
};

declare function local:b($count)
{
  $count, if($count gt 1) then local:a($count - 1) else ()
};

local:a(10)
