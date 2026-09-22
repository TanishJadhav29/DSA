// Problem: Department Highest Salary
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: mysql
// Verdict: Accepted
// URL: https://leetcode.com/problems/department-highest-salary/
// Solved on: 2026-09-22T21:25:36.453Z

SELECT 
    d.name AS Department,
    e1.name AS Employee,
    e1.salary AS Salary
FROM Employee e1
JOIN Department d 
    ON e1.departmentId = d.id
WHERE e1.salary = (
    SELECT MAX(e2.salary)
    FROM Employee e2
    WHERE e2.departmentId = e1.departmentId
);