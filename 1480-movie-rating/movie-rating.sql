# Write your MySQL query statement below
WITH username AS(
    SELECT u.name, COUNT(1) AS rated FROM users u LEFT JOIN movierating m ON u.user_id = m.user_id GROUP BY m.user_id ORDER BY rated DESC, u.name ASC LIMIT 1
),
moviename AS(
    SELECT m.title, AVG(mr.rating) AS rating FROM movies m LEFT JOIN movierating mr ON m.movie_id = mr.movie_id AND mr.created_at BETWEEN '2020-02-01' AND '2020-02-29' GROUP BY mr.movie_id ORDER BY rating DESC, m.title ASC LIMIT 1
)
SELECT u.name AS results FROM username u
UNION ALL
SELECT m.title FROM moviename m