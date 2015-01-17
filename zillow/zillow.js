//Dependencies
var express = require('express');
var config = require('configure');
var auth = require('http-auth');
var parser = require('xml2json');
var body_parser = require('body-parser');
var zc = require('./zillow_client.js');

//Variables
var app = express();
var basic = auth.basic({
  realm : 'Global',
  file : __dirname + '/data/users.htpasswd'
});

app.use(auth.connect(basic));
app.use(body_parser.json());
app.use(body_parser.urlencoded({extended : true}));

//Routes
app.get('/', function(req, res) {
  var data = config.zillow;
  var property = {};
  data.address = "531 St Marlo Dr.";
  data.citystatezip = "31028";
  zc.getSearchResults(data, function(err, httpResponse, body) {
    var results = JSON.parse(parser.toJson(httpResponse.body))["SearchResults:searchresults"]["response"]["results"];
    property.zpid = results.result.zpid;
    property.address = results.result.address.street;
    property.city = results.result.address.city;
    property.state = results.result.address.state;
    property.zip = results.result.address.zipcode;
    property.zestimate = results.result.zestimate.amount["$t"];
    property.valuation_high = results.result.zestimate.valuationRange.high["$t"];
    property.valuation_low = results.result.zestimate.valuationRange.low["$t"];
    res.status(200).send(property);
  });
});

//Init
app.listen(3000);
