# Automated Weather Analytics Microservice

An enterprise-grade Python data processing pipeline engineered to ingest raw atmospheric data inputs from third-party metrics networks automatically, manage structural storage targets inside a relational database system, and calculate performance aggregates via an on-demand REST API layer.

## 🏗️ System Architecture Description

1. **Ingestion Tier (`worker.py`)**: An isolated background daemon running continuously to poll Open-Meteo JSON feeds, unpack parallel measurement matrices, handle state deduplication constraints, and cache records locally.
2. **Persistence Layer (`database.py` & `models.py`)**: An Object-Relational Mapping data interface built using modern SQLAlchemy 2.0 connected to a self-hosted MySQL relational storage cluster.
3. **Serving Layer (`app.py`)**: A high-performance FastAPI server running analytics extraction scripts over local table indexes to compute moving metrics (min, max, mean) instantly without hitting external connection boundaries.

## 🚀 Deployment Instructions

### 1. Setup Local Configurations
Ensure a local MySQL instance is live, then compile dependencies:
```bash
pip install fastapi uvicorn requests sqlalchemy pymysql

### 2. Run and API Calling 

run worker.py and uvicorn app:app 
at endpoint /analytics :

    {
  "status": "success",
  "metrics": {
    "maximum_temperature": 27,
    "minimum_temperature": 6,
    "average_temperature": 17
  }

at workers terminal : Logs and Pipeline executed successfully. Added 10 new data rows.
                      Sleeping for 1 hour before next metric ingest sync...
