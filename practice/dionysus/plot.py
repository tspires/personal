import plotly.plotly as py
from plotly.graph_objs import *
import numpy as np
py.sign_in('tsspires', 'un6fk20uak')


def box_plot(y0):
	trace1 = Box(
	    y=y0
	)
	data = Data([trace1])
	plot_url = py.plot(data, filename='basic-box-plot')
	return plot_url
