# Write your MySQL query statement below
SELECT name FROM employee e, (SELECT managerid, COUNT(managerid) as total FROM employee GROUP BY managerid) sub WHERE sub.total>=5 && e.id = sub.managerid

-- SELECT managerid, COUNT(managerid) as total FROM employee GROUP BY managerid