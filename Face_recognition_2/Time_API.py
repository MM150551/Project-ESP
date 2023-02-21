#Starting project file for git repo
#print('This is the first file in the repository')
#print()

import requests
import json

#timezones = requests.get('http://worldtimeapi.org/api/timezone')
timeInEgypt = requests.get('http://worldtimeapi.org/api/timezone/Africa/Cairo')

#print the request obj in a formatted json format 
def jprint(obj):
	formattedJson = json.dumps(obj.json(), indent=1)
	print(formattedJson)
	
#print the full dictionary 
#jprint(timeInEgypt)

# extract the full time from the dictionary
fullTime = timeInEgypt.json()["datetime"]

#extract the time from the fulltime string
def timeFromString(fulltime):
	indStart = fullTime.find("T")
	indEnd = fullTime.find(".")
	return fullTime[indStart+1:indEnd]

def dateFromString(fulltime):
	indStart = 0
	indEnd = fullTime.find("T")
	return fullTime[indStart:indEnd]

#print(timeFromString(fullTime))
#print(dateFromString(fullTime))