import pandas as pd




import pandas as pd

import numpy as np


mytable = pd.read_table('cs-trace.txt')
//\t是默认分隔符，选择逗号 sep=','
//sort_values是排序操作，

mytable=pd.DataFrame(pd.read_csv('LoanStats3a.csv',header=1))

mytable.sort_values(["loan_amnt"])

#单列数据进行排序，以及多列数据进行排序,默认是升序
mytable.sort_values_values(["loan_amnt"],ascending=True)
mytable.sort_values(["loan_amnt"],ascending=False)
mytable.sort_values(["loan_amnt","int_rate"],ascending=False)
mytable.sort_values(["int_rate","loan_amnt"],ascending=False)
#获取金额最小的前十项，head()默认前五行
mytable.sort_values(["loan_amnt"],ascending=True).head(10)


#单列数据筛选
mytable.loc[mytable["grade"] == "B"].head()
mytable.loc[mytable["grade"] != "B"].head()
#只显示这三列
mytable.loc[mytable["grade"] == "B", ["member_id", "loan_amnt", "grade"]].head()
mytable.loc[mytable["grade"] == "B", ["member_id", "loan_amnt", "grade"]].sort_values(["loan_amnt"])
mytable.loc[mytable["grade"] != "B", ["member_id", "loan_amnt", "grade"]].sort_values(["loan_amnt"],ascending=False)

#多列数据筛选并排序
mytable.loc[(mytable["grade"] == "B") & (mytable["loan_amnt"]>5000), ["member_id", "term" , "loan_amnt", "grade","sub_grade", "int_rate"]].head()
mytable.loc[(mytable["grade"] != "B") & (mytable["loan_status"] != "Charged Off"),["member_id", "term" , "loan_amnt", "grade", "sub_grade", "loan_status"]].head()
mytable.loc[(mytable["grade"] == "B") | (mytable["loan_amnt"] > 5000), ["member_id", "term" , "loan_amnt", "grade","sub_grade", "int_rate"]].head()
mytable.loc[(mytable["grade"] == "B") & (mytable["loan_amnt"] > 5000), ["member_id", "term" , "loan_amnt", "grade","sub_grade", "int_rate"]].sort_values(["loan_amnt"])
mytable.loc[(mytable["grade"] == "B") & (mytable["loan_amnt"] > 5000), ["member_id", "term" , "loan_amnt", "grade","sub_grade", "int_rate"]].sort_values(["loan_amnt"],ascending=False)
mytable.loc[(mytable["grade"] == "B") | (mytable["loan_amnt"] > 5000), ["member_id", "term" , "loan_amnt", "grade","sub_grade", "int_rate"]].sort_values(["loan_amnt"],ascending=False)

#求和
mytable.loc[(mytable["grade"] == "B") & (mytable["loan_amnt"] > 5000)].loan_amnt.sum()
#计数
mytable.loc[mytable["grade"] == "B"].loan_amnt.count()
#平均值
mytable.loc[mytable["grade"] == "B"].loan_amnt.mean()
#最大值
mytable.loc[mytable["grade"] == "B"].loan_amnt.max()
#最小值
mytable.loc[mytable["grade"] != "B"].loan_amnt.min()




# -*- coding:utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 2 * (np.pi))  
#numpy.linspace(开始，终值(含终值))，个数)..x和y的维度应该相同。
y1 = np.sin(x)
y2 = np.cos(x) ， 

#画图
plt.title('Compare cosx with sinx')  #标题
#plt.plot(x,y)
#常见线的属性有：color,label,linewidth,linestyle,marker等
plt.plot(x, y1, color='cyan', label='sinx')
plt.plot(x, y2, 'b', label='cosx')#'b'指：color='blue'
plt.legend()  #显示上面的label
#绘制网格
plt.grid(alpha=0.4,linestyle=':')
#添加图例，prop指定图例的字体, loc参数可以查看源码
plt.legend(prop=my_font,loc="upper left")
plt.xlabel('x')
plt.ylabel('f(x)')
plt.axis([0, 2*np.pi, -1, 1])#设置坐标范围axis([xmin,xmax,ymin,ymax])
#plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()


线的颜色：
‘b’ blue 
‘g’ green 
‘r’ red 
‘c’ cyan 
‘m’ magenta 
‘y’ yellow 
‘k’ black 
‘w’ white
线的形状：
‘-’ solid line style 
‘–’ dashed line style 
‘-.’ dash-dot line style 
‘:’ dotted line style

点的标记：
‘.’ point marker 
‘,’ pixel marker 
‘o’ circle marker 
‘v’ triangle_down marker 
‘^’ triangle_up marker 
‘<’ triangle_left marker 
‘>’ triangle_right marker 
‘1’ tri_down marker 
‘2’ tri_up marker 
‘3’ tri_left marker 
‘4’ tri_right marker 
‘s’ square marker 
‘p’ pentagon marker 
‘*’ star marker 
‘h’ hexagon1 marker 
‘H’ hexagon2 marker 
‘+’ plus marker 
‘x’ x marker 
‘D’ diamond marker 
‘d’ thin_diamond marker 
‘|’ vline marker 
‘_’ hline marker
