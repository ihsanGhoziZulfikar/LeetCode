# Write your MySQL query statement below
SELECT 
    query_name, 
    ROUND(AVG(rating/position),2) AS quality, 
    ROUND(COUNT(CASE WHEN rating<3 THEN 1 END)/COUNT(1)*100,2) AS poor_query_percentage
FROM queries 
GROUP BY query_name