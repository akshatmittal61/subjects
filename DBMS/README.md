# DBMS

**Data**: Any fact that could be recorded. For e.g.) text, images, numbers, media etc.

**Database**: Collection of related data.

## Models in DB

-   **High Level / Conecptual Level**: The layout of the database as shown to the users. For e.g.) ER Model
-   **Representational Level / Implementation**: The relational model i.e.) the tables
-   Low Level / Physical Data Model

# ER Model

-   **Entity**: Any object/thing is called an entity.
-   **Attributes**: Properties of an entity.
-   **Relationships**: A relationship is verb maintaining any relationship among entities.

| Title         | Def         | Exmaples  |
| ------------- | ----------- | --------- |
| Entity        | Thing       | Person    |
| Attributes    | Properties  | Name, Age |
| Relationships | Association | Works for |

**Entity type**: Schema (The layout of any entity).

For e.g.) PERSON(name, age, address): ("Akshat", 20, UP-IN)

The first is the extension of a schema while the last one is intension of it.

## Attrtibutes

-   Simple Attrbiutes
-   **Composite Attrbiutes**: Attributes that can further be divided intp sub-attributes, like name: fname, mname, lname
-   **Single Values Attributes**: Address, Ph.No. etc.
-   **Multi Values Attributes**: age
-   **Stored Attributes**: DOB
-   **Derived Attributes**: age

# Key

A key is used to uniquely identify any tuple in a table.

-   **Candidate Key**: The minimal set of attributes that can uniquely identify a tuple is known as a candidate key.
-   **Super Key**: The set of attributes that can uniquely identify a tuple is known as Super Key.
-   **Primary Key**: There can be more than one candidate key in relation out of which one can be chosen as the primary key.
-   **Alternate Key**: The candidate key other than the primary key is called an alternate key.
-   **Foreign key**: If an attribute can only take the values which are present as values of some other attribute, it will be a foreign key to the attribute to which it refers.

![Types of Keys](images/types_of_keys.png)
