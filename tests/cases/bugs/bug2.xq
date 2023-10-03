declare namespace myns="myns";
declare function myns:myfunc($po as xs:string)
   as item() {
      .
};

count(/myns:myfunc('abc'))