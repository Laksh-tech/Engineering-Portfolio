from fastapi import FastAPI
from database import Sessionlocal as SessionLocal,redis_client
from fastapi import Depends
from sqlalchemy.orm import Session
from sqlalchemy import func
from models import Weather
import json
app = FastAPI(title="Weather Microservice")

def get_db():
    session = SessionLocal()
    try:
        yield session
    finally:
        session.close()

@app.get("/analytics")
def get_analytics(session : Session = Depends(get_db)):
    try:
        cache_key = "weather_stats"
    
    # 1. Check Redis first
        cached_data = redis_client.get(cache_key)
        if cached_data is not None:
            print("🚀 CACHE HIT: Serving directly from Redis memory!")
            return json.loads(cached_data)  # Turn string back into JSON dictionary
        
        print("🐢 CACHE MISS: Fetching calculations from MySQL...")
    
    # 2. Run the heavy MySQL aggregation query
        stats = session.query(
        func.max(Weather.temperature),
        func.min(Weather.temperature),
        func.avg(Weather.temperature)
        ).first()
    
        max_temp, min_temp, avg_temp = stats
        if max_temp is None:
            return {"status": "pending", "message": "Database empty."}
        
    # 3. Format the final output response
        response_payload = {
        "status": "success",
        "metrics": {
            "maximum_temperature": round(max_temp, 2),
            "minimum_temperature": round(min_temp, 2),
            "average_temperature": round(avg_temp, 2)
        }
    }
    
    # 4. Save a copy in Redis with a Time-To-Live (TTL) of 60 seconds
        redis_client.setex(
        name=cache_key,
        time=60,  # Expires automatically in 60 seconds
        value=json.dumps(response_payload)  # Convert dict to string
    )
    
        return response_payload
    except Exception as e:
        return {"status": "error", "message": str(e)}
    
if __name__ == "__main__":
    import uvicorn


    