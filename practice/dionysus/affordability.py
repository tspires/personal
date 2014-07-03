#!/usr/bin/python
import dionysus
from pprint import pprint
import locale
def main():
	lower_range = int(raw_input('What is the lower range of your income target? '))
	higher_range = int(raw_input('What is the higher range of your income target? '))
	amount_down = int(raw_input('How much will you put down? '))
	monthly_debts = int(raw_input('How much in monthly debt obligations do you have? '))
	term = int(raw_input('What term loan will you have? '))
	arguments = {}
	arguments['zws-id'] = dionysus.zillow_zws_id
	arguments['down'] = amount_down
	arguments['monthlydebts'] = monthly_debts
	arguments['term'] = term
	arguments['zws-id'] = dionysus.zillow_zws_id
	locale.setlocale(locale.LC_ALL, 'en_US.UTF-8')
	api_helper = dionysus.APIHelper()
	xml_helper = dionysus.XMLHelper()
	print('{0} down'.format(locale.currency(amount_down,grouping=True)))
	for x in range(lower_range/10000,higher_range/10000):
		arguments['annualincome'] = x * 10000
		affordability = api_helper.call(dionysus.zillow_api['CalculateAffordability'],arguments)
		price = int(affordability[affordability.keys()[0]]['response']['affordabilityamount'])
		income = int(arguments['annualincome'])
		print(locale.currency(income,grouping=True),locale.currency(price,grouping=True))
if __name__ == '__main__':
	main()
