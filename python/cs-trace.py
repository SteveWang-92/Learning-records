import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
PlotHits = []
PlotMisses = []

mytable = pd.DataFrame(pd.read_table('cs-trace.txt'))
#筛选所有的cachehits ，按照时间升序排列
Hits=mytable.loc[mytable["Type"] == "CacheHits" , ["Time" ,  "Packets"]].sort_values("Time").groupby("Time").mean()
Misses=mytable.loc[mytable["Type"] == "CacheMisses" , ["Time" ,  "Packets"]].sort_values("Time").groupby("Time").mean()

print(Hits)
print(Misses)

#percent = Hits /(Hits+Misses)

#x and y should have the same number 
x = np.linspace(0 , 50 , 19 )
plt.title('Time - CacheHits & CacheMisses')
plt.plot(x, Hits, color='cyan', label='CacheHits')
plt.plot(x, Misses, 'b', label='CacheMisses')
#plt.plot(x, percent, 'r', label='Hit%')
#线面是显示图例
plt.legend()
plt.xlabel('Time')
plt.ylabel('Packets')
#设置坐标范围axis([xmin,xmax,ymin,ymax])
plt.axis([0, 20, 0, 50])
plt.show()
