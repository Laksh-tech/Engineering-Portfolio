# Project: Healthcare Operations Analysis

## 🎯 The Goal
The objective of this project was to analyze Patient Throughput and Financial Performance within a hospital system. The analysis focused on calculating "Turnaround Time" (stay duration), categorizing resource utilization, and identifying revenue bottlenecks across departments and cities.

## 🏗️ Database Schema
The project utilizes two relational tables connected via a standard Foreign Key relationship:

**Healthcare_Operations**: Tracks individual patient episodes, including admission/discharge dates, diagnosis, and billing.

**Hospital_Details**: Stores dimensional data about the physical locations, including city and infrastructure capacity.
## ⚙️ Core Operations (What the Script Does)
* **1. Resource Categorization (Logic & Arithmetic):** Created strict table structures with appropriate data types and foreign key constraints.
* **2. Multi-Table Financial Aggregation (Joins)**We linked operational billing data with geographical hospital data to identify high-revenue regions.

## 🛠️ Tech Stack
Database: MySQL (Workbench)
Language: SQL (Advanced DQL, CTEs, Joins)
