declare default element namespace "http://default.org/ns";
declare namespace a = "http://custom.org/ns";

<elem>test</elem>, 
element elem {'test'},
element a:elem {'test'},
<a:node> {attribute attr {'test'}}</a:node>,
<a:node attr="test"></a:node>,
<a:node> {attribute { fn:QName("http://anamespa.ce", "attr") } {'test'}}</a:node>,
<a:node> {attribute { fn:QName("http://custom.org/ns", "attr") } {'test'}}</a:node>,
<newElement xmlns="www.mynamespace.com">{element original {"Original Content"}}</newElement>/*
