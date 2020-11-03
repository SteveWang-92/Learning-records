import random
import matplotlib.pyplot as plt 

q = float(0.7)
#noise
s = float(0.7)
#s represent the popularity percent of all the content 
num=[0.0] 
for i in range(1,100):
    N =  num[i-1]+1.0/((i+q)**s)
    num.append(N)
for i in range(0,100):
    num[i] = num[i] / num[99]
print(num)
print(len(num))
#存放输出
out = []
for j in range(0,10000):
    randomvalue = float(0.0)
    randomvalue = float(random.randint(0,100)/100)
    while randomvalue == 0.0:
    	randomvalue = float(random.randint(0,100)/100)
    for i in range(0,100):
        if randomvalue <= num[i]:
            out.append(i)
            break
               
print(out)                            
#直方图

group = [0,10,20,30,40,50,60,70,80,90,100]
plt.hist(out, group, histtype='bar', rwidth=0.8)

plt.legend()

plt.xlabel('number')
plt.ylabel('count')

plt.title('zip hit fig')

plt.show()
