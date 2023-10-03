declare boundary-space preserve;
declare namespace math = "http://exslt.org/math";

<tests>
 <abs-tests>
  <abs arg="xs:double(-1.0)" typecheck="{(math:abs(xs:double(-1.0))) instance of xs:double}" val="{math:abs(xs:double(-1.0))}"/>
  <abs arg="xs:double(0.0)" typecheck="{(math:abs(xs:double(0.0))) instance of xs:double}" val="{math:abs(xs:double(0.0))}"/>
  <abs arg="xs:double(1.0)" typecheck="{(math:abs(xs:double(1.0))) instance of xs:double}" val="{math:abs(xs:double(1.0))}"/>
 </abs-tests>
 <sqrt-tests>
  <sqrt arg="xs:double(0.0)" typecheck="{(math:sqrt(xs:double(0.0))) instance of xs:double}" val="{math:sqrt(xs:double(0.0))}"/>
  <sqrt arg="xs:double(1.0)" typecheck="{(math:sqrt(xs:double(1.0))) instance of xs:double}" val="{math:sqrt(xs:double(1.0))}"/>
  <sqrt arg="xs:double(2.0)" typecheck="{(math:sqrt(xs:double(2.0))) instance of xs:double}" val="{math:sqrt(xs:double(2.0))}"/>
  <sqrt arg="xs:double(4.0)" typecheck="{(math:sqrt(xs:double(4.0))) instance of xs:double}" val="{math:sqrt(xs:double(4.0))}"/>
  <sqrt arg="xs:double(-1.0)" typecheck="{(math:sqrt(xs:double(-1.0))) instance of xs:double}" val="{math:sqrt(xs:double(-1.0))}"/>
  <sqrt arg="xs:double(NaN)" typecheck="{(math:sqrt(xs:double("NaN"))) instance of xs:double}" val="{math:sqrt(xs:double("NaN"))}"/>
  <sqrt arg="xs:double(INF)" typecheck="{(math:sqrt(xs:double("INF"))) instance of xs:double}" val="{math:sqrt(xs:double("INF"))}"/>
  <sqrt arg="xs:double(-INF)" typecheck="{(math:sqrt(-xs:double("INF"))) instance of xs:double}" val="{math:sqrt(-xs:double("INF"))}"/>
  <sqrt arg="xs:float(0.0)" typecheck="{(math:sqrt(xs:float(0.0))) instance of xs:float}" val="{math:sqrt(xs:float(0.0))}"/>
  <sqrt arg="xs:float(1.0)" typecheck="{(math:sqrt(xs:float(1.0))) instance of xs:float}" val="{math:sqrt(xs:float(1.0))}"/>
  <sqrt arg="xs:float(2.0)" typecheck="{(math:sqrt(xs:float(2.0))) instance of xs:float}" val="{math:sqrt(xs:float(2.0))}"/>
  <sqrt arg="xs:float(4.0)" typecheck="{(math:sqrt(xs:float(4.0))) instance of xs:float}" val="{math:sqrt(xs:float(4.0))}"/>
  <sqrt arg="xs:float(-1.0)" typecheck="{(math:sqrt(xs:float(-1.0))) instance of xs:float}" val="{math:sqrt(xs:float(-1.0))}"/>
  <sqrt arg="xs:float(NaN)" typecheck="{(math:sqrt(xs:float("NaN"))) instance of xs:float}" val="{math:sqrt(xs:float("NaN"))}"/>
  <sqrt arg="xs:float(INF)" typecheck="{(math:sqrt(xs:float("INF"))) instance of xs:float}" val="{math:sqrt(xs:float("INF"))}"/>
  <sqrt arg="xs:float(-INF)" typecheck="{(math:sqrt(-xs:float("INF"))) instance of xs:float}" val="{math:sqrt(-xs:float("INF"))}"/>
  <sqrt arg="xs:decimal(0.0)" typecheck="{(math:sqrt(xs:decimal(0.0))) instance of xs:decimal}" val="{math:sqrt(xs:decimal(0.0))}"/>
  <sqrt arg="xs:decimal(1.0)" typecheck="{(math:sqrt(xs:decimal(1.0))) instance of xs:decimal}" val="{math:sqrt(xs:decimal(1.0))}"/>
  <sqrt arg="xs:decimal(2.0)" typecheck="{(math:sqrt(xs:decimal(2.0))) instance of xs:decimal}" val="{math:sqrt(xs:decimal(2.0))}"/>
  <sqrt arg="xs:decimal(4.0)" typecheck="{(math:sqrt(xs:decimal(4.0))) instance of xs:decimal}" val="{math:sqrt(xs:decimal(4.0))}"/>
  <sqrt arg="xs:decimal(-1.0)" typecheck="{(math:sqrt(xs:decimal(-1.0))) instance of xs:decimal}" val="{math:sqrt(xs:decimal(-1.0))}"/>
 </sqrt-tests>
 <sin-tests>
  <sin arg="xs:double(0.0)" typecheck="{(math:sin(xs:double("NaN"))) instance of xs:double}" val="{math:sin(xs:double("NaN"))}"/>
  <sin arg="xs:double(0.0)" typecheck="{(math:sin(xs:double("INF"))) instance of xs:double}" val="{math:sin(xs:double("INF"))}"/>
  <sin arg="xs:double(0.0)" typecheck="{(math:sin(-xs:double("INF"))) instance of xs:double}" val="{math:sin(-xs:double("INF"))}"/>
  <sin arg="xs:double(0.0)" typecheck="{(math:sin(xs:double(0.0))) instance of xs:double}" val="{math:sin(xs:double(0.0))}"/>
  <sin arg="xs:double(~pi/2)" typecheck="{(math:sin(xs:double(3.1415 div 2))) instance of xs:double}" val="{math:sin(xs:double(3.1415 div 2))}"/>
  <sin arg="xs:double(~pi)" typecheck="{(math:sin(xs:double(3.1415))) instance of xs:double}" val="{math:sin(xs:double(3.1415))}"/>
  <sin arg="xs:float(0.0)" typecheck="{(math:sin(xs:float("NaN"))) instance of xs:float}" val="{math:sin(xs:float("NaN"))}"/>
  <sin arg="xs:float(0.0)" typecheck="{(math:sin(xs:float("INF"))) instance of xs:float}" val="{math:sin(xs:float("INF"))}"/>
  <sin arg="xs:float(0.0)" typecheck="{(math:sin(-xs:float("INF"))) instance of xs:float}" val="{math:sin(-xs:float("INF"))}"/>
  <sin arg="xs:float(0.0)" typecheck="{(math:sin(xs:float(0.0))) instance of xs:float}" val="{math:sin(xs:float(0.0))}"/>
  <sin arg="xs:float(~pi/2)" typecheck="{(math:sin(xs:float(3.1415 div 2))) instance of xs:float}" val="{math:sin(xs:float(3.1415 div 2))}"/>
  <sin arg="xs:float(~pi)" typecheck="{(math:sin(xs:float(3.1415))) instance of xs:float}" val="{math:sin(xs:float(3.1415))}"/>
  <sin arg="xs:decimal(0.0)" typecheck="{(math:sin(xs:decimal(0.0))) instance of xs:decimal}" val="{math:sin(xs:decimal(0.0))}"/>
  <sin arg="xs:decimal(~pi/2)" typecheck="{(math:sin(xs:decimal(3.1415 div 2))) instance of xs:decimal}" val="{math:sin(xs:decimal(3.1415 div 2))}"/>
  <sin arg="xs:decimal(~pi)" typecheck="{(math:sin(xs:decimal(3.1415))) instance of xs:decimal}" val="{math:sin(xs:decimal(3.1415))}"/>
 </sin-tests>
 <cos-tests>
  <cos arg="xs:double(0.0)" typecheck="{(math:cos(xs:double("NaN"))) instance of xs:double}" val="{math:cos(xs:double("NaN"))}"/>
  <cos arg="xs:double(0.0)" typecheck="{(math:cos(xs:double("INF"))) instance of xs:double}" val="{math:cos(xs:double("INF"))}"/>
  <cos arg="xs:double(0.0)" typecheck="{(math:cos(-xs:double("INF"))) instance of xs:double}" val="{math:cos(-xs:double("INF"))}"/>
  <cos arg="xs:double(0.0)" typecheck="{(math:cos(xs:double(0.0))) instance of xs:double}" val="{math:cos(xs:double(0.0))}"/>
  <cos arg="xs:double(~pi/2)" typecheck="{(math:cos(xs:double(3.1415 div 2))) instance of xs:double}" val="{math:cos(xs:double(3.1415 div 2))}"/>
  <cos arg="xs:double(~pi)" typecheck="{(math:cos(xs:double(3.1415))) instance of xs:double}" val="{math:cos(xs:double(3.1415))}"/>
  <cos arg="xs:float(0.0)" typecheck="{(math:cos(xs:float(0.0))) instance of xs:float}" val="{math:cos(xs:float(0.0))}"/>
  <cos arg="xs:float(0.0)" typecheck="{(math:cos(xs:float("NaN"))) instance of xs:float}" val="{math:cos(xs:float("NaN"))}"/>
  <cos arg="xs:float(0.0)" typecheck="{(math:cos(xs:float("INF"))) instance of xs:float}" val="{math:cos(xs:float("INF"))}"/>
  <cos arg="xs:float(0.0)" typecheck="{(math:cos(-xs:float("INF"))) instance of xs:float}" val="{math:cos(-xs:float("INF"))}"/>
  <cos arg="xs:float(~pi/2)" typecheck="{(math:cos(xs:float(3.1415 div 2))) instance of xs:float}" val="{math:cos(xs:float(3.1415 div 2))}"/>
  <cos arg="xs:float(~pi)" typecheck="{(math:cos(xs:float(3.1415))) instance of xs:float}" val="{math:cos(xs:float(3.1415))}"/>
  <cos arg="xs:decimal(0.0)" typecheck="{(math:cos(xs:decimal(0.0))) instance of xs:decimal}" val="{math:cos(xs:decimal(0.0))}"/>
  <cos arg="xs:decimal(~pi/2)" typecheck="{(math:cos(xs:decimal(3.1415 div 2))) instance of xs:decimal}" val="{math:cos(xs:decimal(3.1415 div 2))}"/>
  <cos arg="xs:decimal(~pi)" typecheck="{(math:cos(xs:decimal(3.1415))) instance of xs:decimal}" val="{math:cos(xs:decimal(3.1415))}"/>
 </cos-tests>
 <tan-tests>
  <tan arg="xs:double(0.0)" typecheck="{(math:tan(xs:double("NaN"))) instance of xs:double}" val="{math:tan(xs:double("NaN"))}"/>
  <tan arg="xs:double(0.0)" typecheck="{(math:tan(xs:double("INF"))) instance of xs:double}" val="{math:tan(xs:double("INF"))}"/>
  <tan arg="xs:double(0.0)" typecheck="{(math:tan(-xs:double("INF"))) instance of xs:double}" val="{math:tan(-xs:double("INF"))}"/>
  <tan arg="xs:double(0.0)" typecheck="{(math:tan(xs:double(0.0))) instance of xs:double}" val="{math:tan(xs:double(0.0))}"/>
  <tan arg="xs:double(~pi/2)" typecheck="{(math:tan(xs:double(3.1415 div 2))) instance of xs:double}" val="{math:tan(xs:double(3.1415 div 2))}"/>
  <tan arg="xs:double(~pi)" typecheck="{(math:tan(xs:double(3.1415))) instance of xs:double}" val="{math:tan(xs:double(3.1415))}"/>
  <tan arg="xs:float(0.0)" typecheck="{(math:tan(xs:float("NaN"))) instance of xs:float}" val="{math:tan(xs:float("NaN"))}"/>
  <tan arg="xs:float(0.0)" typecheck="{(math:tan(xs:float("INF"))) instance of xs:float}" val="{math:tan(xs:float("INF"))}"/>
  <tan arg="xs:float(0.0)" typecheck="{(math:tan(-xs:float("INF"))) instance of xs:float}" val="{math:tan(-xs:float("INF"))}"/>
  <tan arg="xs:float(0.0)" typecheck="{(math:tan(xs:float(0.0))) instance of xs:float}" val="{math:tan(xs:float(0.0))}"/>
  <tan arg="xs:float(~pi/2)" typecheck="{(math:tan(xs:float(3.1415 div 2))) instance of xs:float}" val="{math:tan(xs:float(3.1415 div 2))}"/>
  <tan arg="xs:float(~pi)" typecheck="{(math:tan(xs:float(3.1415))) instance of xs:float}" val="{math:tan(xs:float(3.1415))}"/>
  <tan arg="xs:decimal(0.0)" typecheck="{(math:tan(xs:decimal(0.0))) instance of xs:decimal}" val="{math:tan(xs:decimal(0.0))}"/>
  <tan arg="xs:decimal(~pi/2)" typecheck="{(math:tan(xs:decimal(3.1415 div 2))) instance of xs:decimal}" val="{math:tan(xs:decimal(3.1415 div 2))}"/>
  <tan arg="xs:decimal(~pi)" typecheck="{(math:tan(xs:decimal(3.1415))) instance of xs:decimal}" val="{math:tan(xs:decimal(3.1415))}"/>
 </tan-tests>
 <asin-tests>
  <asin arg="{math:sin(xs:double(0.0))}" arg_pre="0.0" type="xs:double" val="{math:asin(math:sin(xs:double(0.0)))}"/>
  <asin arg="{math:sin(xs:double(0.5))}" arg_pre="0.5" type="xs:double" val="{math:asin(math:sin(xs:double(0.5)))}"/>
  <asin arg="{math:sin(xs:double(1.0))}" arg_pre="1.0" type="xs:double" val="{math:asin(math:sin(xs:double(1.0)))}"/>
  <asin arg="{math:sin(xs:double(-0.5))}" arg_pre="-0.5" type="xs:double" val="{math:asin(math:sin(xs:double(-0.5)))}"/>
  <asin arg="{math:sin(xs:double(-1.0))}" arg_pre="-1.0" type="xs:double" val="{math:asin(math:sin(xs:double(-1.0)))}"/>
  <asin arg="NaN" arg_pre="undef" type="xs:double" val="{math:asin(xs:double("NaN"))}"/>
  <asin arg="INF" arg_pre="undef" type="xs:double" val="{math:asin(xs:double("INF"))}"/>
  <asin arg="-INF" arg_pre="undef" type="xs:double" val="{math:asin(-xs:double("INF"))}"/>
  <asin arg="2.0" arg_pre="undef" type="xs:double" val="{math:asin(xs:double(2.0))}"/>
  <asin arg="-2.0" arg_pre="undef" type="xs:double" val="{math:asin(xs:double(-2.0))}"/>
  <asin arg="{math:sin(xs:float(0.0))}" arg_pre="0.0" type="xs:float" val="{math:asin(math:sin(xs:float(0.0)))}"/>
  <asin arg="{math:sin(xs:float(0.5))}" arg_pre="0.5" type="xs:float" val="{math:asin(math:sin(xs:float(0.5)))}"/>
  <asin arg="{math:sin(xs:float(1.0))}" arg_pre="1.0" type="xs:float" val="{math:asin(math:sin(xs:float(1.0)))}"/>
  <asin arg="{math:sin(xs:float(-0.5))}" arg_pre="-0.5" type="xs:float" val="{math:asin(math:sin(xs:float(-0.5)))}"/>
  <asin arg="{math:sin(xs:float(-1.0))}" arg_pre="-1.0" type="xs:float" val="{math:asin(math:sin(xs:float(-1.0)))}"/>
  <asin arg="NaN" arg_pre="undef" type="xs:float" val="{math:asin(xs:float("NaN"))}"/>
  <asin arg="INF" arg_pre="undef" type="xs:float" val="{math:asin(xs:float("INF"))}"/>
  <asin arg="-INF" arg_pre="undef" type="xs:float" val="{math:asin(-xs:float("INF"))}"/>
  <asin arg="2.0" arg_pre="undef" type="xs:float" val="{math:asin(xs:float(2.0))}"/>
  <asin arg="-2.0" arg_pre="undef" type="xs:float" val="{math:asin(xs:float(-2.0))}"/>
  <asin arg="{math:sin(xs:decimal(0.0))}" arg_pre="0.0" type="xs:decimal" val="{math:asin(math:sin(xs:decimal(0.0)))}"/>
  <asin arg="{math:sin(xs:decimal(0.5))}" arg_pre="0.5" type="xs:decimal" val="{math:asin(math:sin(xs:decimal(0.5)))}"/>
  <asin arg="{math:sin(xs:decimal(1.0))}" arg_pre="1.0" type="xs:decimal" val="{math:asin(math:sin(xs:decimal(1.0)))}"/>
  <asin arg="{math:sin(xs:decimal(-0.5))}" arg_pre="-0.5" type="xs:decimal" val="{math:asin(math:sin(xs:decimal(-0.5)))}"/>
  <asin arg="{math:sin(xs:decimal(-1.0))}" arg_pre="-1.0" type="xs:decimal" val="{math:asin(math:sin(xs:decimal(-1.0)))}"/>
 </asin-tests>
 <acos-tests>
  <acos arg="{math:cos(xs:double(0.0))}" arg_pre="0.0" type="xs:double" val="{math:acos(math:cos(xs:double(0.0)))}"/>
  <acos arg="{math:cos(xs:double(0.5))}" arg_pre="0.5" type="xs:double" val="{math:acos(math:cos(xs:double(0.5)))}"/>
  <acos arg="{math:cos(xs:double(1.0))}" arg_pre="1.0" type="xs:double" val="{math:acos(math:cos(xs:double(1.0)))}"/>
  <acos arg="{math:cos(xs:double(-0.5))}" arg_pre="1.5" type="xs:double" val="{math:acos(math:cos(xs:double(1.5)))}"/>
  <acos arg="{math:cos(xs:double(-1.0))}" arg_pre="2.0" type="xs:double" val="{math:acos(math:cos(xs:double(2.0)))}"/>
  <acos arg="NaN" arg_pre="undef" type="xs:double" val="{math:acos(xs:double("NaN"))}"/>
  <acos arg="INF" arg_pre="undef" type="xs:double" val="{math:acos(xs:double("INF"))}"/>
  <acos arg="-INF" arg_pre="undef" type="xs:double" val="{math:acos(-xs:double("INF"))}"/>
  <acos arg="2.0" arg_pre="undef" type="xs:double" val="{math:acos(xs:double(2.0))}"/>
  <acos arg="-2.0" arg_pre="undef" type="xs:double" val="{math:acos(xs:double(-2.0))}"/>
  <acos arg="{math:cos(xs:float(0.0))}" arg_pre="0.0" type="xs:float" val="{math:acos(math:cos(xs:float(0.0)))}"/>
  <acos arg="{math:cos(xs:float(0.5))}" arg_pre="0.5" type="xs:float" val="{math:acos(math:cos(xs:float(0.5)))}"/>
  <acos arg="{math:cos(xs:float(1.0))}" arg_pre="1.0" type="xs:float" val="{math:acos(math:cos(xs:float(1.0)))}"/>
  <acos arg="{math:cos(xs:float(-0.5))}" arg_pre="1.5" type="xs:float" val="{math:acos(math:cos(xs:float(1.5)))}"/>
  <acos arg="{math:cos(xs:float(-1.0))}" arg_pre="2.0" type="xs:float" val="{math:acos(math:cos(xs:float(2.0)))}"/>
  <acos arg="NaN" arg_pre="undef" type="xs:float" val="{math:acos(xs:float("NaN"))}"/>
  <acos arg="INF" arg_pre="undef" type="xs:float" val="{math:acos(xs:float("INF"))}"/>
  <acos arg="-INF" arg_pre="undef" type="xs:float" val="{math:acos(-xs:float("INF"))}"/>
  <acos arg="2.0" arg_pre="undef" type="xs:float" val="{math:acos(xs:float(2.0))}"/>
  <acos arg="-2.0" arg_pre="undef" type="xs:float" val="{math:acos(xs:float(-2.0))}"/>
  <acos arg="{math:cos(xs:decimal(0.0))}" arg_pre="0.0" type="xs:decimal" val="{math:acos(math:cos(xs:decimal(0.0)))}"/>
  <acos arg="{math:cos(xs:decimal(0.5))}" arg_pre="0.5" type="xs:decimal" val="{math:acos(math:cos(xs:decimal(0.5)))}"/>
  <acos arg="{math:cos(xs:decimal(1.0))}" arg_pre="1.0" type="xs:decimal" val="{math:acos(math:cos(xs:decimal(1.0)))}"/>
  <acos arg="{math:cos(xs:decimal(-0.5))}" arg_pre="1.5" type="xs:decimal" val="{math:acos(math:cos(xs:decimal(1.5)))}"/>
  <acos arg="{math:cos(xs:decimal(-1.0))}" arg_pre="2.0" type="xs:decimal" val="{math:acos(math:cos(xs:decimal(2.0)))}"/>
 </acos-tests>
 <atan-tests>
  <atan arg="{math:tan(xs:double(0.0))}" arg_pre="0.0" type="xs:double" val="{math:atan(math:tan(xs:double(0.0)))}"/>
  <atan arg="{math:tan(xs:double(0.5))}" arg_pre="0.5" type="xs:double" val="{math:atan(math:tan(xs:double(0.5)))}"/>
  <atan arg="{math:tan(xs:double(1.0))}" arg_pre="1.0" type="xs:double" val="{math:atan(math:tan(xs:double(1.0)))}"/>
  <atan arg="{math:tan(xs:double(-0.5))}" arg_pre="1.5" type="xs:double" val="{math:atan(math:tan(xs:double(1.5)))}"/>
  <atan arg="{math:tan(xs:double(-1.0))}" arg_pre="2.0" type="xs:double" val="{math:atan(math:tan(xs:double(2.0)))}"/>
  <atan arg="NaN" arg_pre="undef" type="xs:double" val="{math:atan(xs:double("NaN"))}"/>
  <atan arg="INF" arg_pre="undef" type="xs:double" val="{math:atan(xs:double("INF"))}"/>
  <atan arg="-INF" arg_pre="undef" type="xs:double" val="{math:atan(-xs:double("INF"))}"/>
  <atan arg="2.0" arg_pre="undef" type="xs:double" val="{math:atan(xs:double(2.0))}"/>
  <atan arg="-2.0" arg_pre="undef" type="xs:double" val="{math:atan(xs:double(-2.0))}"/>
  <atan arg="{math:tan(xs:float(0.0))}" arg_pre="0.0" type="xs:float" val="{math:atan(math:tan(xs:float(0.0)))}"/>
  <atan arg="{math:tan(xs:float(0.5))}" arg_pre="0.5" type="xs:float" val="{math:atan(math:tan(xs:float(0.5)))}"/>
  <atan arg="{math:tan(xs:float(1.0))}" arg_pre="1.0" type="xs:float" val="{math:atan(math:tan(xs:float(1.0)))}"/>
  <atan arg="{math:tan(xs:float(-0.5))}" arg_pre="1.5" type="xs:float" val="{math:atan(math:tan(xs:float(1.5)))}"/>
  <atan arg="{math:tan(xs:float(-1.0))}" arg_pre="2.0" type="xs:float" val="{math:atan(math:tan(xs:float(2.0)))}"/>
  <atan arg="NaN" arg_pre="undef" type="xs:float" val="{math:atan(xs:float("NaN"))}"/>
  <atan arg="INF" arg_pre="undef" type="xs:float" val="{math:atan(xs:float("INF"))}"/>
  <atan arg="-INF" arg_pre="undef" type="xs:float" val="{math:atan(-xs:float("INF"))}"/>
  <atan arg="2.0" arg_pre="undef" type="xs:float" val="{math:atan(xs:float(2.0))}"/>
  <atan arg="-2.0" arg_pre="undef" type="xs:float" val="{math:atan(xs:float(-2.0))}"/>
  <atan arg="{math:tan(xs:decimal(0.0))}" arg_pre="0.0" type="xs:decimal" val="{math:atan(math:tan(xs:decimal(0.0)))}"/>
  <atan arg="{math:tan(xs:decimal(0.5))}" arg_pre="0.5" type="xs:decimal" val="{math:atan(math:tan(xs:decimal(0.5)))}"/>
  <atan arg="{math:tan(xs:decimal(1.0))}" arg_pre="1.0" type="xs:decimal" val="{math:atan(math:tan(xs:decimal(1.0)))}"/>
  <atan arg="{math:tan(xs:decimal(-0.5))}" arg_pre="1.5" type="xs:decimal" val="{math:atan(math:tan(xs:decimal(1.5)))}"/>
  <atan arg="{math:tan(xs:decimal(-1.0))}" arg_pre="2.0" type="xs:decimal" val="{math:atan(math:tan(xs:decimal(2.0)))}"/>
 </atan-tests>
 <log-tests>
  <log arg="xs:double(0.0)" typecheck="{(math:log(xs:double(0.0))) instance of xs:double}" val="{math:log(xs:double(0.0))}"/>
  <log arg="xs:double(1.0)" typecheck="{(math:log(xs:double(1.0))) instance of xs:double}" val="{math:log(xs:double(1.0))}"/>
  <log arg="xs:double(2.0)" typecheck="{(math:log(xs:double(2.0))) instance of xs:double}" val="{math:log(xs:double(2.0))}"/>
  <log arg="xs:double(4.0)" typecheck="{(math:log(xs:double(4.0))) instance of xs:double}" val="{math:log(xs:double(4.0))}"/>
  <log arg="xs:double(-1.0)" typecheck="{(math:log(xs:double(-1.0))) instance of xs:double}" val="{math:log(xs:double(-1.0))}"/>
  <log arg="xs:float(0.0)" typecheck="{(math:log(xs:float(0.0))) instance of xs:float}" val="{math:log(xs:float(0.0))}"/>
  <log arg="xs:float(1.0)" typecheck="{(math:log(xs:float(1.0))) instance of xs:float}" val="{math:log(xs:float(1.0))}"/>
  <log arg="xs:float(2.0)" typecheck="{(math:log(xs:float(2.0))) instance of xs:float}" val="{math:log(xs:float(2.0))}"/>
  <log arg="xs:float(4.0)" typecheck="{(math:log(xs:float(4.0))) instance of xs:float}" val="{math:log(xs:float(4.0))}"/>
  <log arg="xs:float(-1.0)" typecheck="{(math:log(xs:float(-1.0))) instance of xs:float}" val="{math:log(xs:float(-1.0))}"/>
  <log arg="xs:decimal(0.0)" typecheck="{(math:log(xs:decimal(0.0))) instance of xs:decimal}" val="{math:log(xs:decimal(0.0))}"/>
  <log arg="xs:decimal(1.0)" typecheck="{(math:log(xs:decimal(1.0))) instance of xs:decimal}" val="{math:log(xs:decimal(1.0))}"/>
  <log arg="xs:decimal(2.0)" typecheck="{(math:log(xs:decimal(2.0))) instance of xs:decimal}" val="{math:log(xs:decimal(2.0))}"/>
  <log arg="xs:decimal(4.0)" typecheck="{(math:log(xs:decimal(4.0))) instance of xs:decimal}" val="{math:log(xs:decimal(4.0))}"/>
  <log arg="xs:decimal(-1.0)" typecheck="{(math:log(xs:decimal(-1.0))) instance of xs:decimal}" val="{math:log(xs:decimal(-1.0))}"/>
 </log-tests>
 <exp-tests>
  <exp arg="xs:double(0.0)" typecheck="{(math:exp(xs:double(0.0))) instance of xs:double}" val="{math:exp(xs:double(0.0))}"/>
  <exp arg="xs:double(1.0)" typecheck="{(math:exp(xs:double(1.0))) instance of xs:double}" val="{math:exp(xs:double(1.0))}"/>
  <exp arg="xs:double(2.0)" typecheck="{(math:exp(xs:double(2.0))) instance of xs:double}" val="{math:exp(xs:double(2.0))}"/>
  <exp arg="xs:double(4.0)" typecheck="{(math:exp(xs:double(4.0))) instance of xs:double}" val="{math:exp(xs:double(4.0))}"/>
  <exp arg="xs:double(-1.0)" typecheck="{(math:exp(xs:double(-1.0))) instance of xs:double}" val="{math:exp(xs:double(-1.0))}"/>
  <exp arg="xs:float(0.0)" typecheck="{(math:exp(xs:float(0.0))) instance of xs:float}" val="{math:exp(xs:float(0.0))}"/>
  <exp arg="xs:float(1.0)" typecheck="{(math:exp(xs:float(1.0))) instance of xs:float}" val="{math:exp(xs:float(1.0))}"/>
  <exp arg="xs:float(2.0)" typecheck="{(math:exp(xs:float(2.0))) instance of xs:float}" val="{math:exp(xs:float(2.0))}"/>
  <exp arg="xs:float(4.0)" typecheck="{(math:exp(xs:float(4.0))) instance of xs:float}" val="{math:exp(xs:float(4.0))}"/>
  <exp arg="xs:float(-1.0)" typecheck="{(math:exp(xs:float(-1.0))) instance of xs:float}" val="{math:exp(xs:float(-1.0))}"/>
  <exp arg="xs:decimal(0.0)" typecheck="{(math:exp(xs:decimal(0.0))) instance of xs:decimal}" val="{math:exp(xs:decimal(0.0))}"/>
  <exp arg="xs:decimal(1.0)" typecheck="{(math:exp(xs:decimal(1.0))) instance of xs:decimal}" val="{math:exp(xs:decimal(1.0))}"/>
  <exp arg="xs:decimal(2.0)" typecheck="{(math:exp(xs:decimal(2.0))) instance of xs:decimal}" val="{math:exp(xs:decimal(2.0))}"/>
  <exp arg="xs:decimal(4.0)" typecheck="{(math:exp(xs:decimal(4.0))) instance of xs:decimal}" val="{math:exp(xs:decimal(4.0))}"/>
  <exp arg="xs:decimal(-1.0)" typecheck="{(math:exp(xs:decimal(-1.0))) instance of xs:decimal}" val="{math:exp(xs:decimal(-1.0))}"/>
 </exp-tests>
 <power-tests>
  <power arg1="xs:decimal(2)" arg2="xs:decimal(8)" typecheck="{math:power(xs:decimal(2), xs:decimal(8)) instance of xs:decimal}" val="{math:power(xs:decimal(2), xs:decimal(8))}"/>
  <power arg1="xs:decimal(7)" arg2="xs:decimal(0)" typecheck="{math:power(xs:decimal(7), xs:decimal(0)) instance of xs:decimal}" val="{math:power(xs:decimal(7), xs:decimal(0))}"/>
  <power arg1="xs:decimal(4)" arg2="xs:decimal(-1)" typecheck="{math:power(xs:decimal(4), xs:decimal(-1)) instance of xs:decimal}" val="{math:power(xs:decimal(4), xs:decimal(-1))}"/>
  <power arg1="xs:decimal(-4)" arg2="xs:decimal(3)" typecheck="{math:power(xs:decimal(-4), xs:decimal(3)) instance of xs:decimal}" val="{math:power(xs:decimal(-4), xs:decimal(3))}"/>
  <power arg1="xs:decimal(-7)" arg2="xs:decimal(0)" typecheck="{math:power(xs:decimal(-7), xs:decimal(0)) instance of xs:decimal}" val="{math:power(xs:decimal(-7), xs:decimal(0))}"/>
  <power arg1="xs:decimal(-2)" arg2="xs:decimal(-3)" typecheck="{math:power(xs:decimal(-2), xs:decimal(-3)) instance of xs:decimal}" val="{math:power(xs:decimal(-2), xs:decimal(-3))}"/>
  <power arg1="xs:decimal(2)" arg2="xs:float(8)" typecheck="{math:power(xs:decimal(2), xs:float(8)) instance of xs:float}" val="{math:power(xs:decimal(2), xs:float(8))}"/>
  <power arg1="xs:float(2)" arg2="xs:decimal(8)" typecheck="{math:power(xs:float(2), xs:decimal(8)) instance of xs:float}" val="{math:power(xs:float(2), xs:decimal(8))}"/>
  <power arg1="xs:float(2)" arg2="xs:float(8)" typecheck="{math:power(xs:float(2), xs:float(8)) instance of xs:float}" val="{math:power(xs:float(2), xs:float(8))}"/>
  <power arg1="xs:float(7)" arg2="xs:float(0)" typecheck="{math:power(xs:float(7), xs:float(0)) instance of xs:float}" val="{math:power(xs:float(7), xs:float(0))}"/>
  <power arg1="xs:float(4)" arg2="xs:float(-1)" typecheck="{math:power(xs:float(4), xs:float(-1)) instance of xs:float}" val="{math:power(xs:float(4), xs:float(-1))}"/>
  <power arg1="xs:float(-4)" arg2="xs:float(3)" typecheck="{math:power(xs:float(-4), xs:float(3)) instance of xs:float}" val="{math:power(xs:float(-4), xs:float(3))}"/>
  <power arg1="xs:float(-7)" arg2="xs:float(0)" typecheck="{math:power(xs:float(-7), xs:float(0)) instance of xs:float}" val="{math:power(xs:float(-7), xs:float(0))}"/>
  <power arg1="xs:float(-2)" arg2="xs:float(-3)" typecheck="{math:power(xs:float(-2), xs:float(-3)) instance of xs:float}" val="{math:power(xs:float(-2), xs:float(-3))}"/>
  <power arg1="xs:decimal(2)" arg2="xs:double(8)" typecheck="{math:power(xs:decimal(2), xs:double(8)) instance of xs:double}" val="{math:power(xs:decimal(2), xs:double(8))}"/>
  <power arg1="xs:double(2)" arg2="xs:decimal(8)" typecheck="{math:power(xs:double(2), xs:decimal(8)) instance of xs:double}" val="{math:power(xs:double(2), xs:decimal(8))}"/>
  <power arg1="xs:float(2)" arg2="xs:double(8)" typecheck="{math:power(xs:float(2), xs:double(8)) instance of xs:double}" val="{math:power(xs:float(2), xs:double(8))}"/>
  <power arg1="xs:double(2)" arg2="xs:float(8)" typecheck="{math:power(xs:double(2), xs:float(8)) instance of xs:double}" val="{math:power(xs:double(2), xs:float(8))}"/>
  <power arg1="xs:double(2)" arg2="xs:double(8)" typecheck="{math:power(xs:double(2), xs:double(8)) instance of xs:double}" val="{math:power(xs:double(2), xs:double(8))}"/>
  <power arg1="xs:double(7)" arg2="xs:double(0)" typecheck="{math:power(xs:double(7), xs:double(0)) instance of xs:double}" val="{math:power(xs:double(7), xs:double(0))}"/>
  <power arg1="xs:double(4)" arg2="xs:double(-1)" typecheck="{math:power(xs:double(4), xs:double(-1)) instance of xs:double}" val="{math:power(xs:double(4), xs:double(-1))}"/>
  <power arg1="xs:double(-4)" arg2="xs:double(3)" typecheck="{math:power(xs:double(-4), xs:double(3)) instance of xs:double}" val="{math:power(xs:double(-4), xs:double(3))}"/>
  <power arg1="xs:double(-7)" arg2="xs:double(0)" typecheck="{math:power(xs:double(-7), xs:double(0)) instance of xs:double}" val="{math:power(xs:double(-7), xs:double(0))}"/>
  <power arg1="xs:double(-2)" arg2="xs:double(-3)" typecheck="{math:power(xs:double(-2), xs:double(-3)) instance of xs:double}" val="{math:power(xs:double(-2), xs:double(-3))}"/>
 </power-tests>
</tests>
