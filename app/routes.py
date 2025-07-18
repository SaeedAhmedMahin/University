from flask import Blueprint, render_template
from datetime import datetime
import openmeteo_requests
import pytz
import requests_cache
import requests
from retry_requests import retry

main = Blueprint('main', __name__)



# this fethces a joke and we use it to get jokes according to the type of weather
def joke_fetcher(type):
    joke = (requests.get(f"https://official-joke-api.appspot.com/jokes/{type}/random")).json()
    setup = str(joke[0]["setup"])
    punchline = str(joke[0]["punchline"])
    return setup+"\n"+punchline

@main.route('/', defaults={'city_name': 'dhaka'})
@main.route('/<city_name>')
def home(city_name): 
    try:
        cities = requests.get(f"https://geocoding-api.open-meteo.com/v1/search?name={city_name}") # GET cities and turn it into json
        city_data = cities.json()
        latitude = city_data["results"][0]["latitude"]
        longitude = city_data["results"][0]["longitude"]
        city = city_data["results"][0]["name"]
        country = city_data["results"][0]["country"]
        time_zone = city_data["results"][0]["timezone"]
        # GET weather data
        response = requests.get( 
            f"https://api.open-meteo.com/v1/forecast?latitude={latitude}&longitude={longitude}&current_weather=true&hourly=pressure_msl,relative_humidity_2m,apparent_temperature&daily=temperature_2m_max,temperature_2m_min")
        if response.status_code == 200:
            data = response.json()
            local_tz = pytz.timezone(time_zone)
            local_time = datetime.now(local_tz)
                 
            temperature = data["current_weather"]["temperature"]
            windspeed = data["current_weather"]["windspeed"]

            current_time =  int(str(str(local_time).split(' ')[1])[:2]) # GET current hour -> 00-23
            current_pressure = data["hourly"]["pressure_msl"][current_time]
            current_humidity = data["hourly"]["relative_humidity_2m"][current_time]
            apparent_temp = data["hourly"]["apparent_temperature"][current_time]
            
            max_temp = data["daily"]["temperature_2m_max"][0] # 0 gives us current day
            min_temp = data["daily"]["temperature_2m_min"][0]

            #weather code i.e if its cloudy or sunny, taken from Open-Meteo API docs, we fetch a joke according to type of weather
            code = int(data["current_weather"]["weathercode"]) 
            if code == 0:
                joke = joke_fetcher("dad")
                icon = "fa-solid fa-sun"
                weather_condition = "Sunny"
            elif code in [1,2]:
                joke = joke_fetcher("dad")
                icon = "fa-solid fa-cloud-sun"
                weather_condition = "Partly Cloudy"
            elif code ==3:
                joke = joke_fetcher("general")
                icon = "fa-solid fa-cloud"
                weather_condition = "Overcast"
            elif code in [45,48]:
                joke = joke_fetcher("general")
                icon = "fa-solid fa-smog"
                weather_condition = "Fog"
            elif code>50 and code<68:
                joke = joke_fetcher("programming")
                icon = "fa-solid fa-cloud-rain"
                weather_condition = "Drizzle"
            elif code>70 and code <78:
                joke = joke_fetcher("knock-knock")
                icon = "fa-solid fa-snowflake"
                weather_condition = "Snow"
            elif code > 79 and code<87:
                joke = joke_fetcher("programming")
                icon = "fa-solid fa-cloud-showers-heavy"
                weather_condition = "Rain Showers"
            elif code>94 and code<100:
                joke = joke_fetcher("knock-knock")
                icon = "fa-solid fa-cloud-bolt"
                weather_condition = "Thunderstorms"
            else:
                joke = joke_fetcher("knock-knock")
                icon = "fa-solid fa-cloud"
                weather_condition = "Cloudy"
            return render_template('index.html', temperature=temperature, city=city, country=country,
                           windspeed=windspeed, today = local_time,
                           current_humidity=current_humidity, current_pressure=current_pressure,
                           apparent_temp=apparent_temp, max_temp=max_temp, min_temp=min_temp,
                           weather_condition=weather_condition, icon=icon, joke=joke
                           )
    except Exception as e: 
        # All of this is to have a 404 page without a new page
        return render_template('index.html',city="Error", country="404",temperature="", 
                           windspeed="", today = datetime.now(),
                           current_humidity="", current_pressure="",
                           apparent_temp="", max_temp="", min_temp="",
                           weather_condition="Not Found", icon="fa-solid fa-triangle-exclamation" , 
                           joke="Oops! You might want to check your spelling!"
                           )
    
    
  

    

