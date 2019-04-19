# Round_robin_scheduling
Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time. He will log into the system from 10am to 12am only.  He wants to have separate requests queues for students and faculty. Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries and average query time.

Description:

•	First, take input of the number of queries and get the value of whether the query is from a student or faculty.
•	Then take the corresponding values of each query like Arrival time, Burst time etc.
•	Check if arrival time is in working hours of Mr. Sudhesh Sharma (10.00 AM to 12.00 PM).
•	If not, then let the user know that Mr. Sharma is not available.
•	Else, continue to the process of creating an order of execution of different queries in Faculty queue and Student queue.
•	Now, proceed to the round robin scheduling process and take the time quantum from the user.
•	Complete the queries according to the round robin schedule and calculate the time spent on handling queries, average time taken by each query.
•	Print the values.
