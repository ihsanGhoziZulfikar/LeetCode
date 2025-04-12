# Write your MySQL query statement below
-- SELECT 
--     s.student_id, 
--     s.student_name, 
--     e.subject_name, 
--     count(e.subject_name) AS attended_exams 
-- FROM 
--     Students s 
-- LEFT JOIN 
--     Examinations e
-- ON 
--     s.student_id = e.student_id 
-- GROUP BY 
--     e.subject_name, s.student_name
-- ORDER BY s.student_id, e.subject_name

SELECT s.student_id, s.student_name, s.subject_name, count(e.subject_name) AS attended_exams 
FROM (SELECT * FROM students CROSS JOIN subjects) s
LEFT JOIN examinations e
ON s.student_id = e.student_id AND s.subject_name=e.subject_name
GROUP BY s.subject_name, s.student_id
ORDER BY student_id, subject_name

-- SELECT * FROM students CROSS JOIN subjects ORDER BY student_id, subject_name