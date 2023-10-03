declare namespace myns="myns";
declare function myns:myfunc($po as xs:string)
   as item() {
      .
};

count(/html/myns:myfunc('abc'))