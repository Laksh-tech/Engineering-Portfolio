from database import Base
from sqlalchemy import Float ,Column,String,Integer

class Weather(Base):
    __tablename__="weather_data"
    id = Column(Integer,autoincrement=True,primary_key=True)
    time = Column(String(50))
    temperature = Column(Float)

#It is the Weather Model definiton with two attributes time and temperature and Table Name : "weather_data"