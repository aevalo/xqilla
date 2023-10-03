xquery version "3.0";

(:
 : Copyright (c) 2010-2011
 :     John Snelson. All rights reserved.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 :     http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
 :)

module namespace rw = "http://xqilla.sourceforge.net/rewrite";

(:--------------------------:)
(: Arithmetic folding rules :)
(:--------------------------:)

declare option rw:rule "rw:MulMulTransFold: ((~A * ~B) * ~C)
  where rw:is-constant(~C) and (rw:subtype(~this, 'xs:decimal?') or
    rw:subtype(~this, 'xs:float?') or rw:subtype(~this, 'xs:double?'))
-> ((~A * ~C) * ~B) where rw:is-constant(~A) and not(rw:is-constant(~B))
-> (~A * (~C * ~B)) where rw:is-constant(~B) and not(rw:is-constant(~A))";
declare option rw:rule "rw:MulDivTransFold: ((~A div ~B) * ~C)
  where rw:is-constant(~C) and (rw:subtype(~this, 'xs:decimal?') or
    rw:subtype(~this, 'xs:float?') or rw:subtype(~this, 'xs:double?'))
-> ((~A * ~C) div ~B) where rw:is-constant(~A) and not(rw:is-constant(~B))
-> (~A * (~C div ~B)) where rw:is-constant(~B) and not(rw:is-constant(~A))";

(: duration div duration = decimal :)
declare option rw:rule "rw:DivMulTransFold: ((~A * ~B) div ~C)
  where rw:is-constant(~C) and (rw:subtype(~this, 'xs:decimal?') or
    rw:subtype(~this, 'xs:float?') or rw:subtype(~this, 'xs:double?')) and
    not(rw:subtype(~A, 'xs:duration')) and not(rw:subtype(~B, 'xs:duration')) and
    not(rw:subtype(~C, 'xs:duration'))
-> ((~A div ~C) * ~B) where rw:is-constant(~A) and not(rw:is-constant(~B))
-> (~A * (~B div ~C)) where rw:is-constant(~B) and not(rw:is-constant(~A))";
declare option rw:rule "rw:DivDivTransFold: ((~A div ~B) div ~C)
  where rw:is-constant(~C) and (rw:subtype(~this, 'xs:decimal?') or
    rw:subtype(~this, 'xs:float?') or rw:subtype(~this, 'xs:double?')) and
    not(rw:subtype(~A, 'xs:duration')) and not(rw:subtype(~B, 'xs:duration')) and
    not(rw:subtype(~C, 'xs:duration'))
-> ((~A div ~C) div ~B) where rw:is-constant(~A) and not(rw:is-constant(~B))
-> (~A div (~B * ~C)) where rw:is-constant(~B) and not(rw:is-constant(~A))";

declare option rw:rule "rw:AddAddTransFold: ((~A + ~B) + ~C)
  where rw:is-constant(~C) and (rw:subtype(~this, 'xs:decimal?') or
    rw:subtype(~this, 'xs:float?') or rw:subtype(~this, 'xs:double?'))
-> ((~A + ~C) + ~B) where rw:is-constant(~A) and not(rw:is-constant(~B))
-> (~A + (~C + ~B)) where rw:is-constant(~B) and not(rw:is-constant(~A))";
declare option rw:rule "rw:AddSubTransFold: ((~A - ~B) + ~C)
  where rw:is-constant(~C) and (rw:subtype(~this, 'xs:decimal?') or
    rw:subtype(~this, 'xs:float?') or rw:subtype(~this, 'xs:double?'))
-> ((~A + ~C) - ~B) where rw:is-constant(~A) and not(rw:is-constant(~B))
-> (~A + (~C - ~B)) where rw:is-constant(~B) and not(rw:is-constant(~A))";

declare option rw:rule "rw:SubAddTransFold: ((~A + ~B) - ~C)
  where rw:is-constant(~C) and (rw:subtype(~this, 'xs:decimal?') or
    rw:subtype(~this, 'xs:float?') or rw:subtype(~this, 'xs:double?'))
-> ((~A - ~C) + ~B) where rw:is-constant(~A) and not(rw:is-constant(~B))
-> (~A + (~B - ~C)) where rw:is-constant(~B) and not(rw:is-constant(~A))";
declare option rw:rule "rw:SubSubTransFold: ((~A - ~B) - ~C)
  where rw:is-constant(~C) and (rw:subtype(~this, 'xs:decimal?') or
    rw:subtype(~this, 'xs:float?') or rw:subtype(~this, 'xs:double?'))
-> ((~A - ~C) - ~B) where rw:is-constant(~A) and not(rw:is-constant(~B))
-> (~A - (~B + ~C)) where rw:is-constant(~B) and not(rw:is-constant(~A))";

(: Only for xs:decimal, since otherwise "-0" messes things up :)
declare option rw:rule "rw:MulZeroFold: ~e * 0 -> 0
  where rw:subtype(~e, 'xs:decimal?')";
declare option rw:rule "rw:MulOneFold: ~e * 1 -> ~e
  where rw:subtype(~this, 'xs:decimal?') or rw:subtype(~this, 'xs:float?') or
    rw:subtype(~this, 'xs:double?')";
declare option rw:rule "rw:DivOneFold: ~e div 1 -> ~e
  where rw:subtype(~e, 'xs:decimal?') or rw:subtype(~this, 'xs:float?') or
    rw:subtype(~this, 'xs:double?')";
declare option rw:rule "rw:AddZeroFold: ~e + 0 -> ~e
  where rw:subtype(~e, 'xs:decimal?') or rw:subtype(~this, 'xs:float?') or
    rw:subtype(~this, 'xs:double?')";
declare option rw:rule "rw:SubZeroFold: ~e - 0 -> ~e
  where rw:subtype(~e, 'xs:decimal?') or rw:subtype(~this, 'xs:float?') or
    rw:subtype(~this, 'xs:double?')";
declare option rw:rule "rw:ZeroSubFold: 0 - ~e -> - ~e
  where rw:subtype(~e, 'xs:decimal?') or rw:subtype(~this, 'xs:float?') or
    rw:subtype(~this, 'xs:double?')";

declare option rw:rule "rw:AddEmptyFold: ~e + () -> ()";
declare option rw:rule "rw:SubEmptyFold1: ~e - () -> ()";
declare option rw:rule "rw:SubEmptyFold2: () - ~e -> ()";
declare option rw:rule "rw:MulEmptyFold: ~e * () -> ()";
declare option rw:rule "rw:DivEmptyFold1: ~e div () -> ()";
declare option rw:rule "rw:DivEmptyFold2: () div ~e -> ()";
declare option rw:rule "rw:IDivEmptyFold1: ~e idiv () -> ()";
declare option rw:rule "rw:IDivEmptyFold2: () idiv ~e -> ()";
declare option rw:rule "rw:ModEmptyFold1: ~e mod () -> ()";
declare option rw:rule "rw:ModEmptyFold2: () mod ~e -> ()";
declare option rw:rule "rw:UnaryMinusEmptyFold: -() -> ()";

(:--------------------------:)
(: Conditions folding rules :)
(:--------------------------:)

declare option rw:rule "rw:IfTrueFold: if(true()) then ~then else ~else -> ~then";
declare option rw:rule "rw:IfFalseFold: if(false()) then ~then else ~else -> ~else";
declare option rw:rule "rw:BooleanIfElseTrue: if(~condition) then ~then else true()
-> (not(~condition) or ~then) where rw:subtype(~then, 'xs:boolean?')";
declare option rw:rule "rw:BooleanIfThenTrue: if(~condition) then true() else ~else
-> (~condition or ~else) where rw:subtype(~else, 'xs:boolean?')";
