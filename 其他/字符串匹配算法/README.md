﻿使用语言： Javascript <br/>
编译环境： Chrome浏览器 <br/>
算法代码地址：https://github.com/huyaocode/algorithm/tree/master/stringMatching <br/>

## 实现方法：
定义一个工具类，可生成随机的01字符串、验证是否匹配成功、和对查找算法进行时间统计，定义了3个算法类， Horspool、BoyerMoore、BoyerMoore2。每一次匹配都将匹配位置和所耗时间求出。其中BoyerMoore2是对代码的改进，因为第一版做出来Horspool比BoyerMoore快，感觉不对再做了一遍。

## 目录结构
|文件名|备注|
| - | - |
| BinaryTest.js   |   二进制数测试js文件，程序的控制中心 | 
| BoyerMoore.js   |   BoyerMoore实现 | 
| BoyerMoore2.js    | BoyerMoore改进 | 
| draw.js           | Echarts绘图函数 | 
| Horspool.js       | Horspool算法实现 | 
| index.html        | html文件 | 
| NatualTest.js     | 自然文本语言匹配 | 
| README.md         | markdown | 
| StrMatchHelper.js | 匹配帮助类 | 
| ViolenceSerch.js  | 暴力匹配 | 
| 测试结果1.png      | 测试结果截图 | 
| 测试结果2.png      | 测试结果截图 | 

## 二进制文本匹配
制表方法：
为了比较不同文本长度下2种算法的效率，并预测算法的增长速度。欲将匹配位置从0到100000所消耗的时间都求出。但是字符串匹配到底在哪里停下来是不能控制的。并且Echart生成图表时如果想把n个数据放在同一组图中，一个横坐标必须对应n个数据。所以我对得到的数据在百位进行四舍五入（比如在2325处匹配到字符串，在百位四舍五入为2300）。并使用数组标记到底那些区间已有数据，然后一直随机进行匹配，直到每隔100个位置都有匹配成功的数据。**从而让横坐标变得均匀**。最后将【100,200,300...10000】所对应的时间用Echarts进制表。

**待查找01字符串长度**：100000
**模式01字符串长度**：15

所得结果如下图 <br/>
深红（最上面那条线）为BoyerMoore算法 	代码参考《算法》(第四版)504页 <br/>
蓝色（中间那条线 ）  为Horspool算法		代码参考教材《算法设计与分析基础》 <br/>
红色（最下面那条线）为BoyerMoore改进算法	代码参考网上大牛 <br/>


## 结果1
![此处输入图片的描述][1]
## 结果2
![此处输入图片的描述][2]
## 结果分析：
1.BoyerMoore算法最快，耗时最少，在100000数据量下都没有发现明显的增长趋势 <br/>
2.Horspool 算法效率稍微次之 <br/>


  [1]: https://raw.githubusercontent.com/huyaocode/algorithm/master/stringMatching/%E6%B5%8B%E8%AF%95%E7%BB%93%E6%9E%9C1.png
  [2]: https://raw.githubusercontent.com/huyaocode/algorithm/master/stringMatching/%E6%B5%8B%E8%AF%95%E7%BB%93%E6%9E%9C2.png