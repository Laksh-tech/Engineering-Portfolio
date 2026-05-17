from fastapi import FastAPI
from worker import data_ingestion_pipeline
from database import db
from fastapi import Depends
from sqlalchemy.orm import Session
from sqlalchemy import func 
app = FastAPI(title="Weather Microservice")
from models import Weather
def get_db():
    session = db
    try:
        yield session
    finally:
        session.close()

@app.get("/analytics")
def get_analytics(session : Session = Depends(get_db)):
    max_temp,min_temp,avg_temp = session.query(func.max(Weather.temperature),func.min(Weather.temperature),func.avg(Weather.temperature)).first()
    if max_temp is None:
        return {"status": "pending", "message": "No data points gathered by worker engine yet."}
    return {
            "status": "success",
            "metrics": {
            "maximum_temperature": round(max_temp),
            "minimum_temperature": round(min_temp),
            "average_temperature": round(avg_temp)}
            }

