// Problem: Consecutive Numbers
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: mysql
// Verdict: Accepted
// URL: https://leetcode.com/problems/consecutive-numbers/
// Solved on: 2026-09-22T20:47:54.479Z

# Write your MySQL query statement below
SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT 
        num,
        LEAD(num, 1) OVER (ORDER BY id) AS next_1,
        LEAD(num, 2) OVER (ORDER BY id) AS next_2
    FROM Logs
) t
WHERE num = next_1 
  AND num = next_2;