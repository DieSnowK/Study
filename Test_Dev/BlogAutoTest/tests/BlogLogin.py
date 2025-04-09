import time

from selenium.webdriver.common.by import By

from common.Utils import BlogDriver
#测试博客登陆页面

class BlogLogin:
    url = ""
    driver = ""
    def __init__(self):
        self.url = "http://192.168.47.135:8653/blog_system/blog_login.html"
        self.driver = BlogDriver.driver
        self.driver.get(self.url)
    #成功登陆的测试用例
    def LoginSucTest(self):
        self.driver.find_element(By.CSS_SELECTOR, "#username").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#password").clear()

        self.driver.find_element(By.CSS_SELECTOR,"#username").send_keys("admin")
        self.driver.find_element(By.CSS_SELECTOR,"#password").send_keys("123")
        self.driver.find_element(By.CSS_SELECTOR,"#submit").click()
        #能够找到博客首页用户的昵称，说明登录成功，否则登录失败
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.left > div > h3")
        #添加屏幕截图
        BlogDriver.getScreeShot()
        #返回到登陆页面
        self.driver.back()

    #异常登陆的测试用例
    def LoginFailTest(self):
        #若连续多次的send_keys则会出现关键词拼接，而不是替换。若要替换需要先clear
        self.driver.find_element(By.CSS_SELECTOR, "#username").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#password").clear()

        self.driver.find_element(By.CSS_SELECTOR, "#username").send_keys("admin")
        #错误的密码
        self.driver.find_element(By.CSS_SELECTOR, "#password").send_keys("1234")
        self.driver.find_element(By.CSS_SELECTOR, "#submit").click()
        #检查是否登录失败
        actual=self.driver.find_element(By.CSS_SELECTOR,"body").text
        #添加屏幕截图
        BlogDriver.getScreeShot()
        #断言检测一下是否符合预期
        assert actual == "用户名或密码错误!"

login = BlogLogin()
login.LoginSucTest()
login.LoginFailTest()