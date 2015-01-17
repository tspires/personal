var request = require('request');

var getSearchResults = function(data, cb) {
  request.post('http://www.zillow.com/webservice/GetSearchResults.htm?' + 'zws-id=' + data.zwsid + '&address=' + data.address + '&citystatezip=' + data.citystatezip, data.post, cb);
};

module.exports = {
  getSearchResults : getSearchResults
};
