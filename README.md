Grove temperature sensor MAX31850K  [![Build Status](https://travis-ci.com/Seeed-Studio/Seeed_MAX31850K.svg?branch=master)](https://travis-ci.com/Seeed-Studio/Seeed_MAX31850K)
=============================================================  

![MAX31850](https://github.com/linux-downey/Grove_Temperature_sensor_MAX31850K/blob/master/MAX31850K_module.png)  

Introduction of sensor
----------------------------  
The MAX31850/MAX31851 cold-junction compensated, 1-WireM thermocouple-to-digital converters perform
cold-junction compensation and digitize the signal from
a K-, J-, N-, T-, S-, R-, or E-type thermocouple. The converters resolve temperatures to 0.25NC, allow readings
as high as +1768NC and as low as -270NC, and exhibit
thermocouple accuracy of 8 LSBs (2NC) for temperatures
ranging from -200NC to +700NC. 

***
Before using:
==============
The communication of module is base on one-wire,Sopports two use modes:  
>* single mode(one host and one slave)  
>* multiple mode(one host and multiple slaves,base on rom addressing-one wire search algorithm.This is more complex and subtle than IIC addressing.).**In multiple mode ,you can change the address of the module by changing the Pad connection method on the back of board,default is all to low.**

Usage:
==========  
Download all the source files.
Attach the type K Thermocouple to the module port.
Note that the **one-wire pin is D3**.
There are two examples for user to use.
>* **example/Single/Single.ino**,single mode.  
>* **example/Multiple/Multiple.ino**,multiple mode,Use this demo when two or more modules attach to host arduino board.It also can be used in the situation that only attach one module.But we don't recommend such operation,Cause it will reduce the operating efficiency of the program.  

Extended:
------------
[One-wire search algorithm](https://www.maximintegrated.com/cn/app-notes/index.mvp/id/187) for chinese.  

[One-wire search algorithm](http://www.sal.wisc.edu/PFIS/docs/rss-nir/archive/public/Product%20Manuals/maxim-ic/AN187.pdf) for english.

Read the source code and refer to manual Simultaneously.This algorithm is worth a look if you are a software lovers.
***

Reference:
===============
Refer to the **/doc** to get more detail.

***

declaration:
=====
This most part of arduino library is based on [Dallas temperature library](https://github.com/tomdeboer/SparkCoreDallasTemperature).



***
This software is written by downey  for seeed studio<br>
Email:dao.huang@seeed.cc
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>