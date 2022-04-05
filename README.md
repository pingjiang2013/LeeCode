# LeeCode
LeeCode

如果UnitTest中的测试无法运行，
可以把UnitTest中的所有printInUnitTest改为printf，
并且把所有的Assert等判定语句去掉，
然后在原来的项目中创建一个新的main.cpp，
比如在0105oneEditAway中创建一个新的main.cpp，
把剩下的内容拷贝进main函数，
把原来的项目设定为启动项目，
就应该可以运行了。

目前把所有的单元测试放在一起，
是为了便于一次性检查所有的项目是否完好，
避免误操作造成的错误。
