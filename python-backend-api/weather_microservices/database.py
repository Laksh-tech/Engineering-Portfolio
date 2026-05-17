from sqlalchemy import create_engine
from sqlalchemy.orm import DeclarativeBase,sessionmaker
import os
from dotenv import load_dotenv

load_dotenv()
class Base(DeclarativeBase):
    pass
#Connecting Database 
Database_url = os.getenv('DATABASE_URL')
engine = create_engine(Database_url)
Sessionlocal = sessionmaker(autoflush=False, autocommit=False,bind=engine)
db = Sessionlocal()
