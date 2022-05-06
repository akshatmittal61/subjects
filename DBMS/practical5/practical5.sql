-- 1

SELECT e.eid
FROM Employees e, Certified c, Aircraft a
WHERE a.aname="%Boeing%" AND e.eid=c.eid AND c.aid=a.aid;


-- 2

SELECT e.ename 
FROM Employees e, Certified c, Aircraft a
WHERE a.aname="%Boeing%" AND e.eid=c.eid AND c.aid=a.aid;


-- 3

SELECT a.aid
FROM Aircraft a, Flights f
WHERE a.aid=f.flno AND f.from="Delhi" AND f.to="Madras";


-- 4

SELECT f.* 
FROM Flights f, Aircraft a 
WHERE f.flno=a.aid AND a.aid IN(
    SELECT a.aid 
    FROM Employees e,Certified c,Aircraft a 
    WHERE e.salary>100000 AND c.eid=e.eid AND a.aid=c.aid
)


-- 5

SELECT e.ename 
FROM Employees e, Certified C 
WHERE e.eid=c.eid AND c.aid IN(
    SELECT a.aid 
    FROM Aircraft a, Flights f 
    WHERE EXISTS (
        SELECT * 
        FROM Aircraft a,Flights f
        WHERE f.distance>3000
    ) AND 
    NOT EXISTS (
        SELECT * 
        FROM Aircraft a,Flights f 
        WHERE a.aname LIKE "%Boeing%"
    )
)


-- 6

SELECT eid 
FROM Employees 
WHERE salary IN (
    SELECT MAX(salary) 
    FROM Employees
)

-- 10

SELECT SUM(salary) 
FROM Employees;