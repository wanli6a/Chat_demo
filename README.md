# Chat_demo
A chat_demo for learning C++ and Qt
练习了用C++结合Qt编写一个简单的多人聊天demo，比较基础。
首先写了一个简单的注册、登录界面，注册部分通过插入MySQL的users表记录注册用户的账号和密码，登录部分通过查询输入的账号密码与users表中的账号密码是否匹配，匹配则登录成功。
登录后弹出登录成功的窗口，点击OK后跳转到聊天用户窗口，由于不会多个用户登录产生多个登录的客户端，就直接生成了几个用户显示在用户列表中。点击用户头像即可加入聊天。
聊天基于UDP实现，通过socket绑定端口，收发信息。实现了一点辅助功能：更改字体和字体大小、更换字体颜色、字体加粗、字体倾斜以及保存聊天记录到本地txt文件
和清除当前对话框中的聊天记录。
 之前看B站视频学了个做天气预报的客户端，也跟着实现了。本来把天气功能也加上，等有点空再试试。
1.注册和登录
![Alt text](https://github.com/wanli6a/Chat_demo/blob/main/%E6%B3%A8%E5%86%8C%E5%92%8C%E7%99%BB%E5%BD%95.gif)
2.打开聊天窗口
![Alt text](https://github.com/wanli6a/Chat_demo/blob/main/%E6%89%93%E5%BC%80%E8%81%8A%E5%A4%A9%E7%AA%97%E5%8F%A3.gif)
3.字体设置
![Alt text](https://github.com/wanli6a/Chat_demo/blob/main/%E5%AD%97%E4%BD%93%E8%AE%BE%E7%BD%AE.gif)
4.保存记录
![Alt text](https://github.com/wanli6a/Chat_demo/blob/main/%E4%BF%9D%E5%AD%98%E8%AE%B0%E5%BD%95.gif)
5.查看保存到本地的记录和清除当前对话框中的聊天内容
![Alt text](https://github.com/wanli6a/Chat_demo/blob/main/%E6%9F%A5%E7%9C%8B%E4%BF%9D%E5%AD%98%E7%9A%84%E8%AE%B0%E5%BD%95%E5%92%8C%E6%B8%85%E9%99%A4.gif)
