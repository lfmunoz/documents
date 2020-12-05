


> Remember, there are only two hard problems in computer science: cache invalidation, naming, and off-by-one errors.


```kotlin

// End the name of the collection in its plural form
val warnings: List<String>
val jobs: Map<Long, Job>

val job = Job

```

functions should be verbs
objects should be nouns
collections should be plural nouns




Windows have plural names. Like "Program Files", "Users", "Documents", "Videos"


This /order/12/orderdetail/12 is more readable and logical than /orders/12/orderdetails/4.


Classes are always singular. ORM tools generate tables with the same names as class names.


Rest APIs generally stick to nouns when talking about resources and use verbs when describing actions. 


https://stackoverflow.com/questions/6845772/rest-uri-convention-singular-or-plural-name-of-resource-while-creating-it

https://cloud.google.com/apis/design/resource_names



Database Table A resource represents an entity like a database table. It should have a logical singular name. Here's the answer over table names.

Class Mapping Classes are always singular. ORM tools generate tables with same names as class names. As more and more tools are being used, singular names are becoming a standard.



Plural

Simple - all urls start with the same prefix
Logical - orders/ gets an index list of orders.
Standard - Most widely adopted standard followed by the overwhelming majority of public and private APIs.
For example:

GET    /resources - returns a list of resource items

POST   /resources - creates one or many resource items

PUT    /resources - updates one or many resource items

PATCH  /resources - partially updates one or many resource items

DELETE /resources - deletes all resource items

And for single resource items:

GET    /resources/:id - returns a specific resource item based on :id parameter

POST   /resources/:id - creates one resource item with specified id (requires validation)

PUT    /resources/:id - updates a specific resource item

PATCH  /resources/:id - partially updates a specific resource item

DELETE /resources/:id - deletes a specific resource item

To the advocates of singular, think of it this way: Would you ask a someone for an order and expect one thing, or a list of things? So why would you expect a service to return a list of things when you type /order?