
//*****注意！！！NDN的例子运行需要放在ndnsim的example里面。而ns3的则可以直接放在scratch里面。在运行不用了之后要在build文件夹里面把生成的.o文件删除，可以在/src/ndnSIM/examples/里面建一个文件夹，然后把自己的模拟代码放进去之后用完了在/build/src/ndnSIM/examples/之下相应的文件夹里面删除就好了


ns3::ndn::StackHelper ndnHelper
//这都是CS的策略
ndnHelper.setPolicy("nfd::cs::lru")
ndnHelper.setPolicy("nfd::cs::priority_fifo");//现在内容缓存策略有这两种

//还有其他的老的策略
ndnHelper.SetOldContentStore("ns3::ndn::cs::Random", "MaxSize", "10000");
ns3::ndn::cs::Lru（Fifo，Lfu，Random，Nocache）
ns3::ndn::cs::Stats::Lru（Freshness，Probability）//这里的Stats可以替换成括号里面的，后面的Lru可以替换成上一段括号里面的内荣，可以理解为一个是缓存策略，一个是替换策略
ndnHelper.setCsSize(1000);//默认100
.Install(node1)//这个有两种方法，一个是节点指针，一个是节点容器类
.InstallAll()
.getKeyChain()//安全相关的
//还有接口回调函数就是为了添加堆栈相对的接口，实现多接口的网络的互联
NodeContainer allOtherNodes;
for (NodeList::Iterator i = NodeList::Begin(); i != NodeList::End(); ++i) {
  if (*i != node1 && *i != node2) {
    allOtherNodes.Add(*i);
  }
}
ndnHelper.Install(allOtherNodes);
//遍历除了node1以及node2的所有节点
//如果需要让某个节点不要缓存那么就
ndnHelper.SetOldContentStore("ns3::ndn::cs::Nocache");
ndnHelper.Install(node3);

FIB类助手
ndn::FibHelper::AddRoute("c1", "/data", "n1", 1); // link to n1
//在节点c1上的n1接口 安装/data前缀，表明可以通过这个转发出去，最后的1差不多是损耗，就是类似于介数一类的东西，通过他来计算是不是通过这里出去
可以参照定义里面的内容进行设置

Global Routing Helper其实就是简单了路由信息的配置
要用这个助手需要几个步骤，
1.在节点上安装助手
GlobalRoutingHelper ndnGlobalRoutingHelper;
ndnGlobalRoutingHelper.Install(nodes);
2.指定那些节点安装那些前缀名
Ptr<Node> producer; // producer node that exports prefix
std::string prefix; // exported prefix
...
ndnGlobalRoutingHelper.AddOrigins(prefix producer);//这个有多态，可以直接看网站
//AddOriginsForAll，所有的节点都安上 ，没必要其实	
3.计算并安装FIB表
GlobalRoutingHelper::CalculateRoutes();这是最短路径树


//转发策略选择助手，转发策略安装到特定节点上面
StrategyChoiceHelper::Install(nodes, prefix, strategyName);
//转发策略安装到所有的的拓扑节点上面
StrategyChoiceHelper::InstallAll(prefix, strategyName);
//这里的prefix不需要与后面的额strategyName结合
strategyName
//可以选择以下几项
1. /localhost/nfd/strategy/best-route   
2. /localhost/nfd/strategy/multicast
3. /localhost/nfd/strategy/best-route
4. /localhost/nfd/strategy/multicast
//编写自己的转发策略
看./ns-3/src/ndnSIM/examples/ndn-load-balancer.cpp
和他有关的是他同一目录下的ndn-load-balancer文件夹以及TXT的拓扑
其实说来就是几个纯虚函数的重新实现
至少实现一个？？？看网页





//应用助手类
AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
consumerHelper.SetPrefix(prefix);
consumerHelper.SetAttribute("Frequency", StringValue ("10"));
consumerHelper.Install(nodes)
ConsumerCbr  可以有两个Attribute可以设置，一个是频率， 一个是随机化
随机化结果和frequency有关
"none": no randomization

"uniform": uniform distribution in range (0, 1/Frequency)

"exponential": exponential distribution with mean 1/Frequency
helper.SetAttribute("Randomize", StringValue("uniform"));

ndn::AppHelper helper("ns3::ndn::ConsumerZipfMandelbrot");//其实就是二八定律
//这个是consumercbr的子类，那么他除了继承上面的attribute之外还自己有一个新加的属性
//NumberOfContents
  consumerHelper.SetAttribute("NumberOfContents", StringValue("100")); // 10 interests a second

ndn::AppHelper consumerHelper("ns3::ndn::ConsumerBatches");
consumerHelper.SetAttribute("Batches", StringValue("1s 1 2s 5 10s 2"));
1秒到2秒之间发一个包
2-10秒之间发10个包

AppHelper consumerHelper("ns3::ndn::ConsumerWindow");
有以下的Attribute
Window  初始的兴趣包数目，不等待数据包的到达就一下子发送，默认是1
Payloadsize	数据包的负载大小 默认1024字节
Size	请求的数据量，如果设置为-1的话直到模拟结束都会一直满足

AppHelper consumerHelper("ns3::ndn::ConsumerPcon");//由window继承而来除了已有的Attribute，还有添加的
//这是一个滑动窗口控制协议实现了在TCP/IP下的
//里面有很多属性

生产者的应用就是满足这些包就好了
AppHelper consumerHelper("ns3::ndn::Producer");

自定义的应用


//链路状态控制，可以控制误码率还有链路通断
#include "ns3/ndnSIM/helper/ndn-link-control-helper.hpp"
Simulator::Schedule(Seconds(10.0), ndn::LinkControlHelper::FailLink, node1, node2);
Simulator::Schedule(Seconds(15.0), ndn::LinkControlHelper::UpLink, node1, node2);

//可以利用自定义的回调函数进行内容的记录

//统计节点的缓存命中率和丢失率，可以安装在所有节点上，也可以安装在一个节点上。具体看ndn-cs-tracer.cpp
CsTracer::InstallAll("cs-trace.txt", Seconds(1));

