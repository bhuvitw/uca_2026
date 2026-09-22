# DBMS Week - 10

## Indexing 

=> An index is a pre-sorted B-Tree data structure that trades storage and write speed (O(N) updates) for lightening-fast lookup (O(logN)) reads.

2. **Purpose Of Indexing**
    What is the primary purpose of creating an index on a column?
    => Speed up data retrieval for queries that filter or sort on that column

3. **Using a Composite Index — Leading Column**
    Given the index idx_dept_salary ON Employee(department, salary), which query will use this index efficiently?
    => `SELECT * FROM Employee WHERE department = 'Engineering';`
    
4. **Using a Composite Index — Both Columns**
    Using idx_dept_salary ON Employee(department, salary), will the following query use the index efficiently? 
    `SELECT * FROM Employee WHERE department = 'Engineering' AND salary > 90000;`
    => Yes, because both columns are used in the same left-to-right order as the index

5. **Selectivity and Index Usage*
    The department column has only 3 distinct values spread across all 10 rows. What term describes this, and how might it affect whether MySQL actually uses an index on department?
    => Low selectivity; MySQL's optimizer may skip the index and perform a full table scan instead
    ![alt text](image.png)

    ### Selectivity VS Cardinality

    1. **Core Defination** 
    * **Cardinality:** The raw coutn of unique/distince values in a column.
        * Example: In a table of 1,000,000 employees, `gender` might have a cardinality of `2` or `3`, while `email` has a cardinality of `1,000,000`.
    * **Selectivity:** The ratio of unique values to the total row count: 
        ![alt text](image-1.png)
        * Range: 0.0 to 1.0 (or 0% to 100%); 
        * **High Selectivity ($\approx 1.0$):** `email`, `employee_id`, `ssn`. Excellent candidates for an idnex.
        * **Low Selectivity ($\approx 0.0$):** `is_active`, `gender`,  `order_status`. Generally poor candidates for standalone B-Tree indexes.
    
    2. The "Tipping Point" Rule of Thumb
    * If a query's filter condition matches more than ~15% to 25% of the total rows in a table, the MySQL cost-based optimizer usually decides:
    > "Reading the index pages + doing random-lookup jumps to fetch row data is more expensive than just reading the entire table sequentially in contiguous disk blocks."
    * Result: MySQL ignores the index and runs a Full Table Scan (ALL).

    3. One-Liner for Notes & Interviews
    > "Selectivity is the proportion of unique values in a column; high selectivity warrants an index because it isolates small result sets, whereas low selectivity often causes the optimizer to bypass the index in favor of a full table scan."

6. **Reading EXPLAIN Output**
    Which column in the output of an EXPLAIN statement tells you which index, if any, was actually used by the query?
    => Key

7. **Interpreting a Full Table Scan**
    If EXPLAIN shows type = ALL and key = NULL for a query, what does this indicate?
    => The query performed a full table scan without using any index
    > "When type = ALL and key = NULL, it means the query optimizer found no usable index—or chose not to use one—and performed a full table scan, checking every single record on disk."

8. **When a Single-Column Index Helps**
    Given idx_email ON Employee(email), which query would benefit most directly from this index?
    => `SELECT * FROM Employee WHERE email = 'aarav@company.com';`  >>>  `WHERE email LIKE '%company.com';`
    > "An exact equality lookup (=) uses a B-Tree index at peak efficiency via logarithmic search, whereas a leading wildcard (LIKE '%...') breaks alphabetical ordering and forces a full table scan."
    * Leading Wildcard Rule: LIKE '%xyz' invalidates B-Tree index lookups; LIKE 'xyz%' preserves index lookups.
    * Exact Match (=): Yields maximum index efficiency on high-selectivity columns like email.

9. **Covering Index Behavior**
    When a query can be fully answered using only the columns present in an index, without needing to access the actual table rows, what does the EXPLAIN "Extra" column typically show?
    => Using index

    **Core Concept: What is Covering index?**
    * **Definition:** A query is "covered" when all columns requested in `SELECT`, `WHERE`, `JOIN`, and `ORDER BY` exist directly inside the index tree.
    * **Why it matters:** Eliminates the secondary lookup (bookmark/row lookup) to the base table on disk, resolving the query entirely from memory/index tree and avoiding expensive random I/O.

    `EXPLAIN` **Indicator**
    * `Extra: Using index` -> **Covering Index achieved.** (Best possible performance; zero base-table I/O).
    * Watch out: Do not confuse `Using index` (in `Extra`) with:
      * `key: <index_name>` -> The index is used to search, but base table rows are still fetched for non-indexed columns.
      * `Extra: Using index condition` (ICP) -> Filters rows at the index engine level, but still requires base-table lookups.
      * `Extra: Using where; Using index` -> Fully covered; in-memory filtering occurred strictly on index data.

    **Interview Edge Cases to Know:**
    * **InnoDB Primary Key Inherent Inclusion:** In MySQL InnoDB, secondary indexes always append the Primary Key at the leaf level. An index on `(status)` automatically covers `SELECT id, status WHERE status = 'active'`.
    * **PostgreSQL Equivalent:** Displayed as `Index Only Scan` (relies on the Visibility Map via `VACUUM` to skip heap lookups).
    * **`INCLUDE` Clause:** Supported in PostgreSQL and SQL Server to store non-search payload columns only at the leaf nodes, creating a covering index without widening intermediate B-Tree nodes.

10. **LIKE Patterns and Index Usage**
    Which of the following LIKE patterns generally CANNOT make efficient use of a standard B-Tree index on the column?
    => `LIKE '%arma'`
    > "B-Trees store data in sorted alphabetical order, so a leading wildcard prevents tree traversal and forces a full scan because there is no fixed prefix to seek."


11. **The Cost of Too Many Indexes**
    What is the main downside of adding many indexes to a table that is updated very frequently?
    => INSERT, UPDATE, and DELETE operations become slower, since every index on the table must also be updated
    > "Indexes accelerate reads at the direct expense of writes, because every INSERT, UPDATE, and DELETE forces the engine to maintain and rebalance all secondary B-Tree structures."
    
        