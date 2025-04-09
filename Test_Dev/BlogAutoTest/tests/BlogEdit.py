import time

from selenium.webdriver.common.by import By

from common.Utils import BlogDriver
#测试博客编辑页面
class BlogEdit:
    url = ""
    driver = ""
    def __init__(self):
        self.url = "http://192.168.47.135:8653/blog_system/blog_edit.html"
        self.driver = BlogDriver.driver
        self.driver.get(self.url)

    #正确发布博客（登陆状态下）
    def EditSucTestByLogin(self):
        self.driver.find_element(By.CSS_SELECTOR,"#title").send_keys("自动化测试创建")
        #找到编辑区域，输入关键词(编辑区域不可操作）
        #菜单栏无法元素无法定位
        #博客系统编辑区域默认情况下就不为空，可以暂不处理

        #直接点击发布按钮来发布博客
        self.driver.find_element(By.CSS_SELECTOR,"#submit").click()
        #点击完成之后出现页面的跳转，页面跳转需要加载时间，可能会出现代码执行的速度比页面渲染的速度要快，导致元素查找不到，因此可以添加等待
        #添加隐式等待和显示等待都可以，任选择一个
        #隐式等待：创建浏览器对象之后就可以加上，因为隐式等待的作用域在driver整个生命周期
        #显示等待：可以作用在当前代码中
        actual=self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div:nth-child(1) > div.title").text
        assert actual == "自动化测试创建"
        #屏幕截图
        BlogDriver.getScreeShot()