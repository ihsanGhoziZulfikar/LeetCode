# Write your MySQL query statement below
WITH subq AS(
    SELECT c.user_id, ROUND(COUNT(
        CASE c.action
            WHEN "confirmed" THEN 1
            ELSE null
        END
    ) / COUNT(1), 2)
    AS confirmation_rate FROM confirmations c GROUP BY c.user_id
)
SELECT s.user_id, COALESCE(q.confirmation_rate, 0) AS confirmation_rate FROM signups s LEFT JOIN subq q ON s.user_id = q.user_id