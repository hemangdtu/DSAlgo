# Hash Tables
#### Purpose
To support insertion, deletion and searching in average-case constant time.
- Assumption: Order of element is irrelevant.
- Hash tables are **not** useful if we have to maintain and retrieve data in a specified order of the elements.

#### Hash Function
If we have a table with *Food Items* as key and their *Price* as the value in Hash Map, then,
- Here, the "string key" is converted into an integer value which corresponds to a memory location where the value is present.
This idea can be expressed as follows,
> Hash["string key"] &rarr; Integer Value

### Key Components
- Hash Function
- Hash Table
- Collision Handling Scheme