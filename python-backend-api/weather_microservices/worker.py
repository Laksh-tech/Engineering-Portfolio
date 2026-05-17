from models import Weather
import requests
from database import db
import time
url = "https://api.open-meteo.com/v1/forecast"
params = {
    "latitude": 52.52,
    "longitude": 13.41,
    "hourly": "temperature_2m"
}

def  data_ingestion_pipeline():
    try:
        response = requests.get(url=url,params=params)
        if response.status_code == 200:
            data = response.json()
            time = data["hourly"]["time"]
            temp = data["hourly"]["temperature_2m"]
            new_records = 0
            for curr_t,curr_temp in zip(time,temp):
                existing = db.query(Weather).filter(Weather.time == curr_t).first()
                if existing is not None:
                    print(f"Skipped Logs || Already Logged !!")
                else:
                    print(f"Adding New Logs - {curr_t} || {curr_temp}")
                    new = Weather(time = curr_t, temperature= curr_temp)
                    db.add(new)
                    new_records+=1
            db.commit()
            print(f"Pipeline executed successfully. Added {new_records} new data rows.")
           
    except Exception as e:
        db.rollback()
        print(f"Error Encountered : {e} ||")
    finally:
        db.close()

if __name__ == "__main__":
    print("Background Ingest Engine Started...")
    while True:
        data_ingestion_pipeline()
        print("Sleeping for 1 hour before next metric ingest sync...")
        time.sleep(3600)  # Runs every hour