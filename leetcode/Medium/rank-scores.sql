// Problem: Rank Scores
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: mysql
// Verdict: Accepted
// URL: https://leetcode.com/problems/rank-scores/
// Solved on: 2026-09-22T20:44:47.449Z

# Write your MySQL query statement below
SELECT 
score ,
DENSE_RANK() OVER(ORDER BY score DESC) AS 'rank'
FROM Scores