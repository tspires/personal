#!/usr/bin/python
from pprint import pprint
import urllib
import urllib2
import xml.etree.cElementTree as ElementTree
import xmldict
import ApplicationHelper
import plot
import numpy as np
#Zillow API Functions & URLs
zillow_zws_id = 'X1-ZWz1b9iilf4xe3_90hcq'
zillow_api = {'CalculateAdjustableMortgage': 'http://www.zillow.com/webservice/CalculateAdjustableMortgage.htm?{0}',
 'CalculateAffordability': 'http://www.zillow.com/webservice/mortgage/CalculateAffordability.htm?{0}',
 'CalculateBiWeeklyPayment': 'http://www.zillow.com/webservice/CalculateBiWeeklyPayment.htm?{0}',
 'CalculateDiscountPoints': 'http://www.zillow.com/webservice/CalculateDiscountPoints.htm?{0}',
 'CalculateFixedVsAdjustableRate': 'http://www.zillow.com/webservice/CalculateFixedVsAdjustableRate.htm?{0}',
 'CalculateHELOC': 'http://www.zillow.com/webservice/CalculateHELOC.htm?{0}',
 'CalculateInterstOnlyVsTraditional': 'http://www.zillow.com/webservice/CalculateInterstOnlyVsTraditional.htm?{0}',
 'CalculateMonthlyPaymentsAdvanced': 'http://www.zillow.com/webservice/CalculateMonthlyPaymentsAdvanced.htm?{0}',
 'CalculateMortgageTerms': 'http://www.zillow.com/webservice/CalculateMortgageTerms.htm?{0}',
 'CalculateNoCostVsTraditional': 'http://www.zillow.com/webservice/CalculateNoCostVsTraditional.htm?{0}',
 'CalculateRefinance': 'http://www.zillow.com/webservice/CalculateRefinance.htm?{0}',
 'CalculateTaxSavings': 'http://www.zillow.com/webservice/CalculateTaxSavings.htm?{0}',
 'GetChart': 'http://www.zillow.com/webservice/GetChart.htm?{0}',
 'GetComps': 'http://www.zillow.com/webservice/GetComps.htm?{0}',
 'GetDeepComps': 'http://www.zillow.com/webservice/GetDeepComps.htm?{0}',
 'GetDeepSearchResults': 'http://www.zillow.com/webservice/GetDeepSearchResults.htm?{0}',
 'GetDemographics': 'http://www.zillow.com/webservice/GetDemographics.htm?{0}',
 'GetMonthlyPayments': 'http://www.zillow.com/webservice/GetMonthlyPayments.htm?{0}',
 'GetRateSummary': 'http://www.zillow.com/webservice/GetRateSummary.htm?{0}',
 'GetRegionChart': 'http://www.zillow.com/webservice/GetRegionChart.htm?{0}',
 'GetRegionChildren': 'http://www.zillow.com/webservice/GetRegionChildren.htm?{0}',
 'GetSearchResults': 'http://www.zillow.com/webservice/GetSearchResults.htm?{0}',
 'GetUpdatedPropertyDetails': 'http://www.zillow.com/webservice/GetUpdatedPropertyDetails.htm?{0}',
 'GetZestimate': 'http://www.zillow.com/webservice/GetZestimate.htm?{0}'}
#Trulia API Functions & URLs
trulia_api = {'getCitiesInState': 'http://api.trulia.com/webservices.php?library=LocationInfo&function=getCitiesInState&{0}',
 'getCityStats': 'http://api.trulia.com/webservices.php?library=TruliaStats&function=getCityStats&{0}',
 'getCountiesInState': 'http://api.trulia.com/webservices.php?library=LocationInfo&function=getCountiesInState&{0}',
 'getCountyStats': 'http://api.trulia.com/webservices.php?library=TruliaStats&function=getCountyStats&{0}',
 'getNeighborhoodStats': 'http://api.trulia.com/webservices.php?library=TruliaStats&function=getNeighborhoodStats&{0}',
 'getNeighborhoodsInCity': 'http://api.trulia.com/webservices.php?library=LocationInfo&function=getNeighborhoodsInCity&{0}',
 'getStateStats': 'http://api.trulia.com/webservices.php?library=TruliaStats&function=getStateStats&{0}',
 'getStates': 'http://api.trulia.com/webservices.php?library=LocationInfo&function=getStates&{0}',
 'getZipCodeStats': 'http://api.trulia.com/webservices.php?library=TruliaStats&function=getZipCodeStats&{0}',
 'getZipCodesInState': 'http://api.trulia.com/webservices.php?library=LocationInfo&function=getZipCodesInState&{0}'}
#Default Arguments for testing
arguments = {'address': '531 St Marlo Dr',
 'citystatezip': '31028',
 'unit-type':'dollar',
 'count':'25',
 'rentzestimate':'true',
 'zws-id': zillow_zws_id}

def main():
	print ApplicationHelper.logo
	#Members
	api_helper = APIHelper()
	#Execution
	print("{0}".format(ApplicationHelper.figlet(arguments['address'])))
	asset = Property(arguments['address'],arguments['citystatezip'])
	#Get Search Results
	search = api_helper.call(zillow_api['GetSearchResults'],arguments)
	asset.zillow_search = search
	arguments['zpid'] = search[search.keys()[0]]['response']['results']['result']['zpid']
	asset.zpid = arguments['zpid']
	asset.zestimate = int(search[search.keys()[0]]['response']['results']['result']['zestimate']['amount']['#text'])
	#Get Zestimate
	zestimate_search_result = api_helper.call(zillow_api['GetZestimate'],arguments)
	asset.zillow_zestimate_search_result = zestimate_search_result
	#Get Deep Comps for ZPID
	deep_comps = api_helper.call(zillow_api['GetDeepComps'],arguments)
	#Populate Asset Data
	asset.comps = deep_comps[deep_comps.keys()[0]]['response']['properties']['comparables']['comp']
	asset.comps_sqft = [int(x['finishedSqFt']) for x in asset.comps]
	asset.comps_bedrooms = [int(x['bedrooms']) for x in asset.comps]
	asset.comps_rent_zestimates = [int(x['rentzestimate']['amount']['#text']) for x in asset.comps]	
	asset.comps_built_years = [x['yearBuilt'] for x in asset.comps]
	asset.comps_last_sold_dates = [x['lastSoldDate'] for x in asset.comps]
	asset.comps_zestimates = [int(x['zestimate']['amount']['#text']) for x in asset.comps]
class XMLHelper(object):
	def toDict(self,data):
		root = ElementTree.XML(data)
		result = xmldict.xml_to_dict(root)
		return result

class APIHelper(object):
	def call(self,url,arguments):
		"""Takes an API URL and a dictionary of arguments. Encodes arguments and returns HTTP response of URL + Encoded Arguments converted to a dictionary"""
		xml_helper = XMLHelper()
		arguments = urllib.urlencode(arguments)
		call = url.format(arguments)
		#print call
		response = urllib2.urlopen(url.format(arguments))
		data = xml_helper.toDict(response.read())
		return data

class Property(object):
	def __init__(self,address,zipcode):
		self.address = address
		self.zipcode = zipcode
		
	
		
if __name__ == '__main__':
	main()
