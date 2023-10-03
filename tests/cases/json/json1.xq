xquery version "1.0";

let $json := '{
     "firstName": "John",
     "lastName": "Smith",
     "age": 25,
     "lala": true,
     "noggin": null,
     "char test": "\"\\\n\t\u0041",
     "address": 
     {
         "streetAddress": "21 2nd Street",
         "city": "New York",
         "state": "NY",
         "postalCode": "10021"
     },
     "phoneNumber": 
     [
         {
           "type": "home",
           "number": "212 555-1234"
         },
         {
           "type": "fax",
           "number": "646 555-4567"
         }
     ]
 }'
return (
  let $xml := xqilla:parse-json($json)
  return ($xml, text{"&#xA;"}, xqilla:serialize-json($xml))
)
