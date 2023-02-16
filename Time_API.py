#Starting project file for git repo
print('This is the first file in the repository')
print()

import requests
import json

timezones = requests.get('http://worldtimeapi.org/api/timezone')
timeInEgypt = requests.get('http://worldtimeapi.org/api/timezone/Africa/Cairo')

#formats the request obj to a formatted json format for printing
def jprint(obj):
	formattedJson = json.dumps(obj.json(), indent=1)
	print(formattedJson)

jprint(timeInEgypt)

fullTime = timeInEgypt.json()["datetime"]
indStart = fullTime.find("T")
indEnd = fullTime.find(".")

print(fullTime[indStart+1:indEnd])
