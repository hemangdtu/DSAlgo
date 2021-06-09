# Hash Tables
#### Purpose
To support insertion, deletion and searching in average-case constant time.
- Assumption: Order of element is irrelevant.
- Hash tables are **not** useful if we have to maintain and retrieve data in a specified order of the elements.

### Key Components
- Hash Table
- Hash Function
- Collision Handling Scheme

#### Hash Table
A hash table is a data structure that is used to store keys/value pairs. It uses a hash function to compute an index into an array in which an element will be inserted or searched. By using a good hash function, hashing can work well. Under reasonable assumptions, the average time required to search for an element in a hash table is O(1).

#### Hash Function
If we have a table with *Food Items* as key and their *Price* as the value in Hash Map, then,
- Here, the "string key" is converted into an integer value which corresponds to a memory location where the value is present.
This idea can be expressed as follows,
	> Hash["string key"] &rarr; Integer Value

	In simple words we can also say that, based on whatever key you use a hashing function is applied which will map your specific key into an index. A hashing function should ideally be easy to compute, have uniform distribution, and avoid collisions.

#### Collision Handling Scheme
* **Collisions**
	According to a given hash function, if two or more items gets redirected to the same slot in the memory then this is referred to as a collisionand clearly, collisions create a problem for the hashing technique.
* **Collision Resolution**
	If the hash function is perfect, collisions will never occur. However, since this is often not possible, collision resolution becomes a very important part of hashing. Following are some of the techniques used for collision resolution.
	* **Chaining** — Chaining is the idea of formatting linked lists on all collisions. The issue with this is you get all the overhead that comes with a linked list. If you want to retrieve that specific information you’d have to traverse the linked list.
	* **Rehashing** — This is where if your first hash leads you to a spot that has something already you simply re-hash it and hope to land in an open space. This rehash can be the same function or something different. As long as the order of hashing is followed, you will get to your desired entry.
	* **Linear Probing** — This is a very simple method where you just add 1 and go to the next position if the first hashed location is taken (collision). The issue with this is with high load factors it can lead to clustering which induces collisions into other collisions.
	* **Quadratic Probing** — This is similar to linear probing except instead of adding 1 or going to the neighboring location you add a successive values of an arbitrary quadratic polynomial until an open slot is found. This leads to less primary clustering.

### Operations on Hash Tables
- Insertion
- Deletion
- Searching
