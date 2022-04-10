# Practical 3 answers

### [Click here](./practical3.pdf) to view the questions

Q1

```sql
SELECT * FROM sailors
WHERE rating>7;
```

Q2

```sql
SELECT sname
FROM sailors s, reserves r
WHERE s.sid=r.sid AND r.bid=103;
```

Q3

```sql
SELECT b.color
FROM sailors s, reserves r,boats b
WHERE s.sname="Lubber"
AND s.sid=r.sid
AND r.bid=b.bid
```

Q4

```sql
SELECT rating*1.1
FROM sailors
WHERE sid IN(
    SELECT a.sid
    FROM reserves a, reserves b
    WHERE a.sid=b.sid
    AND a.bid<>b.bid
    AND a.day=b.day
);
```

Q5

```sql
SELECT age
FROM sailors
WHERE sname LIKE "b%_%b";
```

Q6

```sql
SELECT sname
FROM sailors
WHERE sid IN(
    SELECT sid FROM reserves WHERE sid IN (
        SELECT sid FROM reserves r, boats b WHERE b.color="red" AND r.bid=b.bid
    ) AND sid IN (
        SELECT sid FROM reserves r, boats b WHERE b.color="green" AND r.bid=b.bid
    )
);
```

Q7

```sql
SELECT sname
FROM sailors
WHERE sid IN(
    SELECT sid FROM reserves WHERE sid IN (
        SELECT sid FROM reserves r, boats b WHERE b.color="red" AND r.bid=b.bid
    ) AND sid NOT IN (
        SELECT sid FROM reserves r, boats b WHERE b.color="green" AND r.bid=b.bid
    )
);
```

Q8

```sql
SELECT sid
FROM sailors
WHERE rating=10 OR sid IN(
    SELECT sid FROM reserves WHERE bid=103
);
```

Q9

```sql
SELECT s.sname
FROM sailors s,reserves r
WHERE s.sid=r.sid AND r.bid=103;
```

Q10

```sql
SELECT sname
FROM sailors
WHERE rating>SOME(
    SELECT rating
    FROM sailors
    WHERE sname="Horatio"
);
```

Q11

```sql
SELECT sname
FROM sailors
WHERE sid IN(
    SELECT sid FROM reserves WHERE sid IN (
        SELECT sid FROM reserves r, boats b WHERE b.color="red" AND r.bid=b.bid
    ) AND sid IN (
        SELECT sid FROM reserves r, boats b WHERE b.color="green" AND r.bid=b.bid
    )
);
```

Q12

```sql
SELECT sname
FROM sailors
WHERE sid IN(
    SELECT sid
    FROM reserves
    GROUP BY sid
    HAVING COUNT(DISTINCT bid)=ALL(
        SELECT COUNT(bid) FROM boats
    )
);
```

Q13

```sql
SELECT sname
FROM sailors
WHERE sid IN(
    SELECT sid
    FROM sailors
    HAVING age>ALL(
        SELECT age
        FROM sailors
        WHERE rating=10
    )
);
```

Q14

```sql
SELECT rating,MIN(age)
FROM sailors
GROUP BY rating;
```

Q15

```sql
SELECT rating,MIN(age)
FROM sailors
WHERE age>18
GROUP BY rating
HAVING COUNT(*)>=2;
```

Q16

```sql
SELECT rating,AVG(age)
FROM sailors
GROUP BY rating
HAVING COUNT(*)>=2;
```

Q17

```sql
SELECT rating
FROM (
    SELECT rating,AVG(age) as age
    FROM sailors
    GROUP BY rating
) as rating_table
WHERE age IN(
    SELECT MIN(avg_age) FROM (
        SELECT AVG(age) as avg_age
        FROM sailors
        GROUP BY rating
    ) as age
);
```
