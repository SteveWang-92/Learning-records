#!/usr/bin/env python3

import pygal

#读取文件并返回一个存储了文件各行内容的列表
def readfile(fname):
	try:
		with open(fname) as file_object:
			lines = file_object.readlines()	
	except FileNotFoundError:
		msg = "sorry, the file " + fname + " does not exist."
	else:
		msg = "open the file: " + fname + " successfully."
	print(msg)
	return lines


#对返回的列表进行数据处理，并存储
def reclloect(contents, nodename, packettype, outputfilename):
	outtemp = []
#清空已有的文件的内容，方便读取
	for num in range(len(outputfilename)):
		with open(outputfilename[num], 'w') as f:
			f.truncate()
	for content in contents:
		temp = content.split()
		if temp[1].lower() == nodename.lower()	and temp[3].lower() == packettype[0].lower():
	# and int(temp[2]) == int(face):
			outtemp.append(temp[0])
			outtemp.append(temp[4])
	#		outtemp.append(temp[4])
	#		outtemp.append(temp[5])
	#		outtemp.append(temp[6])
	#		outtemp.append(temp[7])
	#		outtemp.append(temp[8])
			outtemp.append('\n')
			writefile(outputfilename[0], outtemp)
#		elif temp[1].lower() == nodename.lower() and temp[2].lower() == packettype[1].lower():
#			continue
#			outtemp.append(temp[0])
#			outtemp.append(temp[3])
#			outtemp.append('\n')
#			writefile(outputfilename[1], outtemp)
		else:
			continue
#判断temp为不为空就写文件
		outtemp = []


#存储经过处理后的数据进入文件
def writefile(fname, out):
	try:
		with open(fname, 'a') as file_object:
#'w'会清空文件内容，'a'则是追加
			for i in range(len(out)):
				s = '	'+str(out[i])
				print(s)
				file_object.write(s)	
	except FileNotFoundError:
		msg = "sorry, the file " + fname + " does not exist."
	else:
		msg = "open the file: " + fname + " successfully."


def visual(fname):
	x_time = []
	y_value0 = []
	y_value1 = []
	datas0 = readfile(fname[0])
#	datas1 = readfile(fname[1])
	for data in datas0:
		datatemp = data.split()
		x_time.append(float(datatemp[0]))
		y_value0.append(float(int(datatemp[1])/2500))
#	for data in datas1:
#		datatemp = data.split()
#		x_time.append(int(datatemp[0]))
#		y_value1.append(float(int(datatemp[1])/1200))
	fig = pygal.Line(x_label_rotation=1, show_minor_x_labels=False)
	fig.add('flooding', y_value0)
#	fig.add('cache-pollution', y_value0)
#	fig.add('flooding-misses', y_value1)
	fig.x_labels = x_time[:59]
#map(str, range(0, 60))
	N=20	
	fig.x_labels_major = x_time[0:59:N]
#	fig.y_labels = [0, 0.5, 1, 1.5, 2, 2.5, 3]
	fig.y_labels = [0, 0.5, 1]
#	fig.title = 'Root CacheHits+ Misses'
	fig.title = 'Rtr4-Drop Rate'
	fig.x_title = '时间(s)'
	fig.y_title = '丢包率'
	fig.legend_at_bottom = True
	fig.render_to_file('cache.svg')


#inputfilename = '/home/wfh/ndnsim/ns-3/rate-trace.txt'
#inputfilename = 'Flooding.txt'
inputfilename = 'drop.txt'
outputfilename = ['out-1.txt','out-2.txt']
#nodename = input("enter the node's name: ")
#nodename = "root"
nodename = "Rtr4"
#packettype = input("enter the packet's type: ")
packettype = ['cachehits','cachemisses']
packettype = ['Drop']
#face = "257"
contents = readfile(inputfilename)
reclloect(contents, nodename, packettype, outputfilename)
visual(outputfilename)
				
			





