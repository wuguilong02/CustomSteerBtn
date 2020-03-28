Windows端Qt可执行程序打包发布的方法

​    以CustomSteerBtn工程为例来学习一下如何制作qt的安装包。[源码链接](https://github.com/wuguilong02/CustomSteerBtn)

​    Qt之所以强大，就是因为有很多Qt库可供程序员使用，qtcreator编译出来的exe需要有这些库才能正常运行。所以发布qt可执行程序的方法就是要找到这些依赖项，并添加到发布文件夹中。

# 1 制作发布包

## 1.1 手动拷贝依赖

​    开始尝试过自己去找依赖库，虽然找全了，但是有两个问题：（1）耗时，根据软件运行时报错的提示去找的依赖也有可能不全；（2）太大，如果手动去拷贝，光一个Qt5Cored.dll就166MB，整个发布包共有656MB，就这样一个简单的程序，竟然要占这么大的空间！

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image002.jpg)

## 1.2 自动寻找依赖

后面尝试了自动寻找依赖库的方法：

https://blog.csdn.net/lxj434368832/article/details/80814388

（1）编译时选择release版本

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image004.jpg)

（2）去release目录下将exe文件拷贝出来，放在一个待发布的文件夹内；

 

（3）将用到的资源images文件夹拷贝到exe所在的目录（程序中是从exe所在的目录下去找images的）

（4）打开qt的终端，通过windeployqt命令来自动寻找依赖项：

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image006.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image008.jpg)

 

​    制作完成后的发布文件夹如下图：

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image010.jpg)

 

现在的大小只有53.9MB，勉强能接受了。

 

# 2 制作安装包

​    但是真正要发布的还不是这么个文件夹，而是要制作成安装包：

https://www.cnblogs.com/linuxAndMcu/p/10974927.html

（1）下载制作安装包的工具：

http://www.jrsoftware.org/isdl.php#stable

（2）根据操作提示一步一步制作打包脚本：

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image012.jpg)

 

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image014.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image016.jpg)

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image018.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image020.jpg)

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image022.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image024.jpg)

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image026.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image028.jpg)

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image030.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image032.jpg)

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image034.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image036.jpg)

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image038.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image040.jpg)

最后将打包脚本放在install目录下：

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image042.jpg)

最后install目录下会生成一个exe，双击该文件就可以执行安装步骤：

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image044.jpg)

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image046.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image048.jpg)

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image050.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image052.jpg)

![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image054.jpg) ![img](https://github.com/wuguilong02/CustomSteerBtn/01\clip_image056.jpg)

​    制作好的安装包只有16.5MB，而安装后的文件还是56.4 MB。

 

 

 

 

 

 

 





