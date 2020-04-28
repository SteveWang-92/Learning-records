#!/usr/bin/env python3.7 

import pygal

line_chart = pygal.Bar()
line_chart.title = 'Different strategy true result(in %)'
line_chart.x_title = 'Attack(packets/s)'

line_chart.x_labels = map(str, range(100, 1100,100))
#最后一个数字不显示的,所以正常要多一个范围
#line_chart.y_labels = map(str, range(60, 100,))
line_chart.add('Bestroute', [83.27,87.58,90.60,92.73,93.88,94.89,95.72,95.75,95.76,95.73])
line_chart.add('Mulicast',  [63.44,67.10,72.35,75.82,78.67,80.23,80.96,81.41,81.59,81.68])
#line_chart.render()
line_chart.render_to_file('safe_true.svg')




line_chart = pygal.Bar()
line_chart.title = 'Different strategy false result(in %)'
line_chart.x_title = 'Attack(packets/s)'

line_chart.x_labels = map(str, range(100, 1100,100))
#最后一个数字不显示的,所以正常要多一个范围
#line_chart.y_labels = map(str, range(60, 100,))
line_chart.add('Bestroute', [2.51,2.32,2.03,1.79,1.64,1.42,1.31,1.02,0.87,0.76])
line_chart.add('Mulicast',  [10.83,8.56,7.02,5.14,4.89,4.53,4.21,3.96,3.44,3.00])
#line_chart.render()
line_chart.render_to_file('safe_false.svg')
