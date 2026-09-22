// Problem: Second Highest Salary
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: mysql
// Verdict: Accepted
// URL: https://leetcode.com/problems/second-highest-salary/
// Solved on: 2026-09-22T20:36:39.080Z

# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
FROM (
    SELECT 
        salary,
        DENSE_RANK() OVER(ORDER BY salary DESC) AS rank1
    FROM Employee
) AS t
WHERE rank1 = 2;