#!/usr/bin/python

import sys, yweather

client = yweather.Client()
city = sys.argv[1]
country = ""
try:
	country = ' , ' + sys.argv[2]
except:
	country = ""

print(client.fetch_woeid(city + country))

