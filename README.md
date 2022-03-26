Welcome to my onlinejudge-codes.:smile:

简单介绍一下这个库

![在这里插入图片描述](https://img-blog.csdnimg.cn/c691b179fb454b1690ed9b05b0917598.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAY2xzMTI3Nw==,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
如图所示，其中包含了各oj的题目AC代码

![在这里插入图片描述](https://img-blog.csdnimg.cn/196cabd1a2204daea1035dc427d190da.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAY2xzMTI3Nw==,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
每个题目的编号都写得很清楚，可以方便大家直接点开学习代码

除此之外，还有几个特别的文件/文件夹

```contests```做过的一些比赛的题目，不太全，因为我打比赛（并完整补题）还是比较少的

```debug```一些没能AC的题目代码，还需要进一步调试

```template```这也是我要重点介绍的，是**我的ACM模板库**

![在这里插入图片描述](https://img-blog.csdnimg.cn/b7a9982dc86a407590ea0536ea8bbdce.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAY2xzMTI3Nw==,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
除去文件名开头的```cls```三个字母，其他应该都可以猜得到是什么模板

这套模板是我以**编写模板->改动模板AC模板题->放到模板库中**的步骤完善的，几乎每道题都经过了测试（为什么说“几乎”呢？因为不确定是否有忘记的部分）

每个模板里采用大家最常用的函数命名方式来以函数的形式存放知识点，例如```gcd,exgcd,CRT,fft,ntt```等；与之相关的预处理过程会以```_init```结尾，例如```fft_init,ntt_init```等

每个知识点开始之前会有注释介绍，所以看一眼注释可能会有助于你怎么使用这套模板

除此之外呢，如果你发现某些模板的码风突变，例如```da,dc3```，因为这是我找的别人测试过的模板，且我本人再使用了一遍之后上传的，所以码风会突变。关于这部分的代码，建议大家当黑盒使用。

如果你实在不明白某一模板如何使用，你可以通过我的提交记录，在**除了template文件夹之外的其他oj文件夹**中找到我的改动

例如我在```FFT, NTT practice```提交记录下，修改了```luogu/luogu3803_ntt.cpp```内的内容，所以你就可以看到**我是如何使用FFT或NTT的代码通过的洛谷的P3803题的**。

![在这里插入图片描述](https://img-blog.csdnimg.cn/801df445969140a0ab11434db979c5f3.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAY2xzMTI3Nw==,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
