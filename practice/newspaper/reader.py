#!/usr/bin/python
import readability
from readability import ParserClient
def main():
	reader_client = readability.ReaderClient('tsspires','c9nGLhTrvdxBP23FyE8h2rmAaDVqcYPA','tsspires','scooter')
	params = {'url':'http://www.bloomberg.com/news/2014-06-10/hillary-clinton-keeps-obama-close-while-citing-policy-gap.html'}
	print reader_client.add_bookmark(params['url'])
	"""
	parser_client = ParserClient('940d29dd186b3eb57869abbb7e007d2f9fbb2530')
	parser_response = parser_client.get_article_content('http://www.bloomberg.com/news/2014-06-10/hillary-clinton-keeps-obama-close-while-citing-policy-gap.html')
	print parser_response.content['content']
	"""

if __name__ == '__main__':
	main()
